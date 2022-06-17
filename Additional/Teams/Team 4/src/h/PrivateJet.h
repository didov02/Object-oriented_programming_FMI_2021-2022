#pragma once
#include "AirVehicle.h"

class PrivateJet : public AirVehicle
{
private:
	bool hasDrinkBar;
	bool hasSleepingRoom;

public:
	PrivateJet(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan, double maxAltitude, const String& color, const String& model
		, bool hasDrinkBar, bool hasSleepingRoom);

	Vehicle* clone() const override;
	AirType getType() const override;
	void display() const override;

	bool getDrinkBar() const;
	void setDrinkBar(bool);

	bool getSleepingRoom() const;
	void setSleepingRoom(bool);
};

