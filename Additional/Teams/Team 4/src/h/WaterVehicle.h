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
	MyString color;
	MyString model;
	double length;
	double width;
	double crewSize;

public:
	WaterVehicle();
	WaterVehicle(int maxPassengers, int maxSpeed, const MyString& name, int year,
		double length, double width, double crewSize, const MyString& color, const MyString& model);


	void setLength(double);
	double getLength() const;

	void setWidth(double);
	double getWidth() const;

	void setCrewSize(double);
	double getCrewSize() const;

	void setColor(const MyString&);
	const MyString& getColor() const;

	void setModel(const MyString&);
	const MyString& getModel() const;

	virtual Vehicle* clone() const = 0;
	virtual WaterType getType() const = 0;
	virtual void display() const = 0;
};

