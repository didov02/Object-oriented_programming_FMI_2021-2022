#include "MyString.h"
#include <cstring>
#pragma warning( disable : 4996)

const size_t MAX_SIZE = 256;

MyString::MyString()
{
	length = 0;
	str = new char[length + 1];
	str[0] = '\0';
}

MyString::MyString(char* value)
{
	length = strlen(value);
	str = new char[length + 1];
	strcpy(str, value);
	str[length] = '\0';
}

MyString::MyString(const char other[])
{
	length = strlen(other);
	str = new char[length + 1];
	strcpy(str, other);
	str[length] = '\0';
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString::~MyString()
{
	free();
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

MyString& MyString::operator=(char*& value)
{
	if(&str != &value)
	{ 
		free();
		length = strlen(value);
		str = value;
	}
	return *this;
}

MyString& MyString::operator=(const char other[])
{
	if (other != nullptr)
	{
		length = strlen(other);
		str = new char[length + 1];
		strcpy(str, other);
		str[length] = '\0';
	}
	return *this;
}

char* MyString::getContent() const
{
	return str;
}

void MyString::setContent(char* value)
{
	length = strlen(value);
	str = value;
}

void MyString::setContent(const char other[])
{
	length = strlen(other);
	str = new char[length + 1];
	strcpy(str, other);
}

int MyString::getLength() const
{
	return length;
}

MyString MyString::operator+=(const MyString& other)
{
	length += other.length;
	char* temp = new char[length + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
	return *this;
}

char MyString::operator[](size_t index) const
{
	if (index < 0 || index > length)
		throw "Index out of bounds";
	else
		return str[index];
}

bool MyString::compare(const MyString& other) const
{
	return strcmp(str, other.str);
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buffer[MAX_SIZE + 1];
	is >> buffer;
	str.free();
	str.length = strlen(buffer);
	str.str = new char[str.length + 1];
	strcpy(str.str, buffer);
	
	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	os << str.str;
	return os;
}

MyString operator+(const MyString& first, const MyString& second)
{
	MyString newString = MyString();
	newString.length = first.length + second.length + 1;
	newString.str = new char[newString.length];
	strcpy(newString.str, first.str);
	strcat(newString.str, second.str);
	return newString;
}

bool operator==(const MyString& first, const MyString& second)
{
	if(strcmp(first.str, second.str) == 0)
		return true;
	return false;
}

bool operator!=(const MyString& first, const MyString& second)
{
	return !(first == second);
}

void MyString::free()
{
	delete[] str;
}

void MyString::copy(const MyString& other)
{
	length = strlen(other.str);
	str = new char[length + 1];
	strcpy(str, other.str);
	str[length] = '\0';
}
