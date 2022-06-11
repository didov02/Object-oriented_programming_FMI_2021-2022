#pragma once
#include "Vehicle.h"

enum AirType
{
	PLANE,
	JET,
};

class AirVehicle : public Vehicle
{
protected:
	AirType t;
	double wingspan;
	double maxAltitude;
	MyString color;
	MyString model;

public:
	AirVehicle();
	AirVehicle(int maxPassengers, int maxSpeed, const MyString& name, int year,
		double wingspan, double maxAltitude, const MyString& color, const MyString& model);

	void setWingspan(double);
	double getWingspan() const;

	void setMaxAltitude(double);
	double getMaxAltitude() const;

	void setColor(const MyString&);
	const MyString& getColor() const;

	void setModel(const MyString&);
	const MyString& getModel() const;

	virtual Vehicle* clone() const = 0;
	virtual AirType getType() const = 0;
	virtual void display() const = 0;
};

