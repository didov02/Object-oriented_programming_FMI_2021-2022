#pragma once
#include "AirVehicle.h"


class Plane : public AirVehicle
{
private:
	double maxStorage;
	double maxAirTime;

public:
	Plane(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan,
		double maxAltitude, const String& color, const String& model,  double maxStorage, double maxAirTime);

	Vehicle* clone() const override;
	AirType getType() const override;
	void display() const override;

	double getMaxStorage() const;
	void setMaxStorage(double);

	double getMaxAirtime() const;
	void setMaxAirtime(double);

};

