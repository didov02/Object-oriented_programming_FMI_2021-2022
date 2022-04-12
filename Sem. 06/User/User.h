#pragma once

class User
{
private:
	char* name = nullptr;
	char* password = nullptr;
	double money = NULL;
public:
	User() = delete; //forbid creating User with default values
	User(const char*, const char*, double); //Constructor
	User(const User&); //Copy Constructor
	User& operator=(const User&); //Copy assignment operator
	~User(); //destructor

	void setName(const char*);
	void setPassword(const char*);
	void setMoney(double);

	const char* getName() const;
	//We avoid getter for password & money

	void print() const;
private:
	void copy(const User&);
	void free();
};