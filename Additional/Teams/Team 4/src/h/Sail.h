#pragma once
#include "WaterVehicle.h"

class Sail : public WaterVehicle
{
private:
	bool hasEngine;
	int sailsCount;

public:

	Sail(int maxPassengers, int maxSpeed, const String& name, int year, double length, double width, int crewSize
		, const String& color, const String& model, bool hasEngine, int sailsCount);

	Vehicle* clone() const override;
	WaterType getType() const override;
	void display() const override;

	bool getHasEngine() const;
	void setHasEngine(bool);

	int getSailsCount() const;
	void setSailsCount(int);

};

