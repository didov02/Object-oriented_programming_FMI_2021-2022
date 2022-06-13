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

void ClearSyncIgnore();

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

	void createCar(int maxPassengers, int maxSpeed, const String& name, int year, const String& color, size_t doorsCount,
		const String& brand, const String& model, const String& fuelType);

	void createTruck(int maxPassengers, int maxSpeed, const String& name, int year, const String& color, size_t doorsCount,
		const String& brand, size_t capacity);

	void createMotorcycle(int maxPassengers, int maxSpeed, const String& name, int year, const String& color, size_t doorsCount,
		const String& brand, const String& model, const String& frameType);

	void createPlane(int maxPassengers, int maxSpeed, const String& name, int year, double wingspan,
		double maxAltitude, const String& color, const String& model, double maxStorage, double maxAirTime);

	void createPrivateJet(int maxPassengers, int maxSpeed, const String& name, int year, double wingspan,
		double maxAltitude, const String& color, const String& model, bool hasDrinkBar, bool hasSleepingRoom);

	void createJacht(int maxPassengers, int maxSpeed, const String& name, int year, double width, double length,
		int crewSize, const String& color, const String& model, bool hasSwimmingPool, int roomCount);

	void createSail(int maxPassengers, int maxSpeed, const String& name, int year, double width, double length,
		int crewSize, const String& color, const String& model, bool hasEngine, int sailsCount);

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

