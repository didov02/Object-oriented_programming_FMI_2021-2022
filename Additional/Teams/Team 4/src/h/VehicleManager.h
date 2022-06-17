#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Sail.h"
#include "Jacht.h"
#include "Plane.h"
#include "PrivateJet.h"
#include "Vector.hpp"
#include <fstream>

const int BIG_NUMBER = 1000000;

class VehicleManager
{
private:
	Vector<Vehicle*> list;
	Vector<String> log;
public:
	VehicleManager();
	VehicleManager(const Vector<Vehicle*>&);
	VehicleManager(const VehicleManager&);
	VehicleManager& operator=(const VehicleManager&);
	~VehicleManager();

	void print() const;

	void createCar(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
		const String& brand, const String& model, const String& fuelType);

	void createTruck(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
		const String& brand, size_t capacity);

	void createMotorcycle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
		const String& brand, const String& model, const String& frameType);

	void createPlane(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan,
		double maxAltitude, const String& color, const String& model, double maxStorage, double maxAirTime);

	void createPrivateJet(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan,
		double maxAltitude, const String& color, const String& model, bool hasDrinkBar, bool hasSleepingRoom);

	void createJacht(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double width, double length,
		size_t crewSize, const String& color, const String& model, bool hasSwimmingPool, size_t roomCount);

	void createSail(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double width, double length,
		size_t crewSize, const String& color, const String& model, bool hasEngine, size_t sailsCount);

	void sellVehicle(size_t);
	void showNewestVehicle() const;
	void showOldestVehicle() const;
	void showFastestVehicle() const;
	void printCount() const;
	void save() const;

private:
	void copy(const VehicleManager&);
	void free();
};

