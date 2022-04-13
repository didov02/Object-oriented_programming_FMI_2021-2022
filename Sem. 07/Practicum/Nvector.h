#pragma once
#include<sstream>

class Nvector
{
private:
	size_t size;
	int* coordinates;

public:
	Nvector();
	Nvector(size_t);
	Nvector(const Nvector&);
	Nvector& operator = (const Nvector&);
	~Nvector();

	Nvector operator+=(const Nvector&) const;
	Nvector operator-=(const Nvector&) const;
	Nvector operator*=(const int multiplier) const;
	bool areParallel(const Nvector&) const;
	bool arePerpendicular(const Nvector&) const;
	double getSizeOfVector() const;
	int& operator[](int);
	int operator[](int) const;
	friend std::istream& operator>>(std::istream&, Nvector);
	friend std::ostream& operator<<(std::ostream& , const Nvector&);

private:
	void copy(const Nvector&);
	void free();
};



