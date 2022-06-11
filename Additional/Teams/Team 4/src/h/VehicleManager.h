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

const int BIG_NUMBER = 1000000;\

void ClearSyncIgnore();

class VehicleManager
{
private:
	Vector<Vehicle*> list;
	Vector<MyString> log;
public:
	VehicleManager();
	VehicleManager(Vector<Vehicle*>);
	VehicleManager(const VehicleManager&);
	VehicleManager& operator=(const VehicleManager&);

	void print() const;

	void createCar(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount,
		const MyString& brand, const MyString& model, const MyString& fuelType);

	void createTruck(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount,
		const MyString& brand, size_t capacity);

	void createMotorcycle(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount,
		const MyString& brand, const MyString& model, const MyString& frameType);

	void createPlane(int maxPassengers, int maxSpeed, const MyString& name, int year, double wingspan,
		double maxAltitude, const MyString& color, const MyString& model, double maxStorage, double maxAirTime);

	void createPrivateJet(int maxPassengers, int maxSpeed, const MyString& name, int year, double wingspan,
		double maxAltitude, const MyString& color, const MyString& model, bool hasDrinkBar, bool hasSleepingRoom);

	void createJacht(int maxPassengers, int maxSpeed, const MyString& name, int year, double width, double length,
		int crewSize, const MyString& color, const MyString& model, bool hasSwimmingPool, int roomCount);

	void createSail(int maxPassengers, int maxSpeed, const MyString& name, int year, double width, double length,
		int crewSize, const MyString& color, const MyString& model, bool hasEngine, int sailsCount);

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

