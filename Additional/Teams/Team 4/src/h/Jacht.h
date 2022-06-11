#pragma once
#include "WaterVehicle.h"

class Jacht : public WaterVehicle
{
private:
	bool hasSwimmingPool;
	int roomsCount;

public:

	Jacht(int maxPassengers, int maxSpeed, const MyString& name, int year, double length, double width, int crewSize
		, const MyString& color, const MyString& model, bool hasSwimmingPool, int roomsCount);

	Vehicle* clone() const override;
	WaterType getType() const override;
	void display() const override;

	bool getHasSwimmingPool() const;
	void setHasSwimmingPoll(bool);

	int getRoomsCount() const;
	void setRoomsCount(int);

};

