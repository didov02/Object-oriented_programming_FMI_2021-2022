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
	String color;
	String model;

public:
	AirVehicle();
	AirVehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year,
		double wingspan, double maxAltitude, const String& color, const String& model);

	void setWingspan(double);
	double getWingspan() const;

	void setMaxAltitude(double);
	double getMaxAltitude() const;

	void setColor(const String&);
	const String& getColor() const;

	void setModel(const String&);
	const String& getModel() const;

	virtual AirType getType() const = 0;
};

