#include <iostream>
#include <cstring>
#include "User.h"
#pragma warning (disable: 4996)

//private
void User::copy(const User& other)
{
	name = new char[strlen(other.name) + 1];
	password = new char[strlen(other.password) + 1];

	strcpy(name, other.name);
	strcpy(password, other.password);
	money = other.money;
}
void User::free()
{
	delete[] name;
	delete[] password;
}

//========================

User::User(const char* name, const char* password, double money)
{
	setName(name);
	setPassword(password);
	setMoney(money);
}
User::User(const User& other)
{
	copy(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
User::~User()
{
	free();
}

void User::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void User::setPassword(const char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}
void User::setMoney(double money)
{
	this->money = money;
}

const char* User::getName() const
{
	return name;
}

void User::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Password: hidden" << std::endl;
	std::cout << "Money: hidden" << std::endl;
}
