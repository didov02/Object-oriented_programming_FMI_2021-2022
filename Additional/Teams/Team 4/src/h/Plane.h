#pragma once
#include "AirVehicle.h"


class Plane : public AirVehicle
{
private:
	double maxStorage;
	double maxAirTime;

public:
	Plane(int maxPassengers, int maxSpeed, const MyString& name, int year, double wingspan,
		double maxAltitude, const MyString& color, const MyString& model,  double maxStorage, double maxAirTime);

	Vehicle* clone() const override;
	AirType getType() const override;
	void display() const override;

	double getMaxStorage() const;
	void setMaxStorate(double);

	double getMaxAirtime() const;
	void setMaxAirtime(double);

};

