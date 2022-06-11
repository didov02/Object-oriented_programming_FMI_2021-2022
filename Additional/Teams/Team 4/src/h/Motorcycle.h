#pragma once
#include "Ground.h"

class Motorcycle : public Ground
{
private:
	MyString brand;
	MyString model;
	MyString frameType;
public:
	Motorcycle();
	Motorcycle(int maxPassengers, int maxSpeed, const MyString& name, int year, MyString color, size_t doorsCount,
		MyString brand, MyString model, MyString frameType);

	Vehicle* clone() const override;
	GroundType getType() const override;
	void display() const override;

	void setBrand(const MyString&);
	void setModel(const MyString&);
	void setFrameType(const MyString&);

	const MyString& getBrand() const;
	const MyString& getModel() const;
	const MyString& getFrameType() const;
};

