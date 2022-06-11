#pragma once
#include <iostream>
class MyString
{

private:
	char* str;
	size_t length;
public:

	MyString();
	MyString(char*);
	MyString(const char[]);
	MyString(const MyString&);
	~MyString();
	MyString& operator=(const MyString&);
	MyString& operator=(char*&);
	MyString& operator=(const char[]);
	
	char* getContent() const;
	void setContent(char*);
	void setContent(const char[]);
	int getLength() const;

	MyString operator+=(const MyString&);
	friend std::istream& operator>>(std::istream& is, MyString&);
	friend std::ostream& operator<<(std::ostream& os,const MyString&);
	friend MyString operator+(const MyString&, const MyString&);
	friend bool operator==(const MyString&, const MyString&);
	friend bool operator!=(const MyString&, const MyString&);
	char operator[](size_t index) const;

	bool compare(const MyString&) const;
	//bool substr(const MyString&) const; maybe if i need it in the future

private:
	void free();
	void copy(const MyString&);
};

