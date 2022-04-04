#include "Student.h"
#include <iostream>
#include <cstring>

#pragma warning (disable: 4996)
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

//Private:
void Student::copy(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
}
void Student::free()
{
	delete[] name;
}

//Public:
//Default constructor
Student::Student() : name(nullptr) , age(NULL) {}

//Constructor with parameters
Student::Student(const char* name, int age)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
}

//Copy constructor
Student::Student(const Student& other)
{
	copy(other);
}

//Copy assignment operator
Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free(); //free memory
		copy(other); //copy other's data
	}
	return *this; 
}

//Destructor
Student::~Student()
{
	free();
}

//Mutators
void Student::setName(const char* name)
{
	free();
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Student::setAge(int age)
{
	this->age = age;
}

//Accessors
const char* Student::getName() const
{
	return name;
}
int Student::getAge() const
{
	return age;
}

//Methods
void Student::print() const
{
	std::cout << name << " " << age << std::endl;
}
