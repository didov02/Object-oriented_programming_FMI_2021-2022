#pragma once
#include "Vehicle.h"

enum GroundType
{
	CAR,
	MOTORCYCLE,
	TRUCK
};

class GroundVehicle : public Vehicle
{
protected:
	GroundType t;
private:
	String color;
	size_t doorsCount;
public:
	GroundVehicle();
	GroundVehicle(int, int, const String&, int, const String&, size_t);

	void setColor(const String&);
	const String& getColor() const;

	void setDoorsCount(size_t);
	size_t getDoorsCount() const;

	virtual GroundType getType() const = 0;
};

