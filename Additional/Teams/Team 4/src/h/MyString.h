#pragma once
#include <iostream>
class String
{

private:
	char* str;
	size_t length;
public:

	String();
	String(char*);
	String(const char[]);
	String(const String&);
	~String();
	String& operator=(const String&);
	String& operator=(char*&);
	String& operator=(const char[]);
	
	char* getContent() const;
	void setContent(char*);
	void setContent(const char[]);
	int getLength() const;

	String operator+=(const String&);
	friend std::istream& operator>>(std::istream& is, String&);
	friend std::ostream& operator<<(std::ostream& os,const String&);
	friend String operator+(const String&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	char operator[](size_t index) const;

	bool compare(const String&) const;
	//bool substr(const MyString&) const; maybe if i need it in the future

private:
	void free();
	void copy(const String&);
};

