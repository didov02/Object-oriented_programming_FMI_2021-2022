#pragma once
#include "Vehicle.h"

enum GroundType
{
	CAR,
	MOTORCYCLE,
	TRUCK
};

class Ground : public Vehicle
{
protected:
	GroundType t;
private:
	MyString color;
	size_t doorsCount;
public:
	Ground();
	Ground(int, int, const MyString&, int, const MyString&, size_t);

	void setColor(const MyString&);
	const MyString& getColor() const;

	void setDoorsCount(size_t);
	size_t getDoorsCount() const;

	virtual Vehicle* clone() const = 0;
	virtual GroundType getType() const = 0;
	virtual void display() const = 0;
};

