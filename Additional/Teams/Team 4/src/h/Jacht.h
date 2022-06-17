#pragma once
#include "WaterVehicle.h"

class Jacht : public WaterVehicle
{
private:
	bool hasSwimmingPool;
	size_t roomsCount;

public:

	Jacht(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double length, double width, size_t crewSize
		, const String& color, const String& model, bool hasSwimmingPool, size_t roomsCount);

	Vehicle* clone() const override;
	WaterType getType() const override;
	void display() const override;

	bool getHasSwimmingPool() const;
	void setHasSwimmingPoll(bool);

	size_t getRoomsCount() const;
	void setRoomsCount(size_t);

};

