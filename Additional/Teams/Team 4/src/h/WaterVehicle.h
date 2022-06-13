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
	double crewSize;

public:
	WaterVehicle();
	WaterVehicle(int maxPassengers, int maxSpeed, const String& name, int year,
		double length, double width, double crewSize, const String& color, const String& model);


	void setLength(double);
	double getLength() const;

	void setWidth(double);
	double getWidth() const;

	void setCrewSize(double);
	double getCrewSize() const;

	void setColor(const String&);
	const String& getColor() const;

	void setModel(const String&);
	const String& getModel() const;

	virtual WaterType getType() const = 0;
};

