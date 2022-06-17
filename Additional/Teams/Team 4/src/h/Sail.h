#pragma once
#include "WaterVehicle.h"

class Sail : public WaterVehicle
{
private:
	bool hasEngine;
	size_t sailsCount;

public:

	Sail(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double length, double width, size_t crewSize
		, const String& color, const String& model, bool hasEngine, size_t sailsCount);

	Vehicle* clone() const override;
	WaterType getType() const override;
	void display() const override;

	bool getHasEngine() const;
	void setHasEngine(bool);

	size_t getSailsCount() const;
	void setSailsCount(size_t);

};

