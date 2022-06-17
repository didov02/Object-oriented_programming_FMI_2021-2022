#pragma once
#include "Vehicle.h"

enum WaterType {
	JACHT,
	SAIL,
};

class WaterVehicle : public Vehicle
{
protected:
	WaterType t;	
	String color;
	String model;
	double length;
	double width;
	size_t crewSize;

public:
	WaterVehicle();
	WaterVehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year,
		double length, double width, size_t crewSize, const String& color, const String& model);


	void setLength(double);
	double getLength() const;

	void setWidth(double);
	double getWidth() const;

	void setCrewSize(size_t);
	size_t getCrewSize() const;

	void setColor(const String&);
	const String& getColor() const;

	void setModel(const String&);
	const String& getModel() const;

	virtual WaterType getType() const = 0;
};

