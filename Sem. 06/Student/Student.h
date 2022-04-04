#pragma once

class Student
{
private: //data/attributes
	char* name;
	int age;
public:
	Student(); //Default Constructor
	Student(const char*, int); //Constructor for all data
	Student(const Student&); //Copy constructor
	Student& operator=(const Student&); //Copy assignment
	~Student(); //Destructor

	//Mutators
	void setName(const char*);
	void setAge(int);

	//Accessors
	const char* getName() const;
	int getAge() const;

	//Methods/Class functions
	void print() const;
private: //Private methods/Private class functions
	void copy(const Student&);
	void free();
};
