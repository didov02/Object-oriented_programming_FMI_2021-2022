#include "VehicleManager.h"

void VehicleManager::copy(const VehicleManager& other)
{
	size_t size = other.list.getSize();

	for (size_t i = 0; i < size; i++) {
		list.pushBack(other.list[i]->clone());
	}

	size = other.log.getSize();

	for (size_t i = 0; i < size; i++) {
		log.pushBack(other.log[i]);
	}
}

void VehicleManager::free()
{
	size_t size = list.getSize();

	for (size_t i = 0; i < size; i++) {
		delete[] list[i];
	}

	list.clear();

	log.clear();
}

VehicleManager::VehicleManager()
{
	
}

VehicleManager::VehicleManager(const Vector<Vehicle*>& other)
{
	size_t size = other.getSize();

	for (size_t i = 0; i < size; i++) {
		list.pushBack(other[i]->clone());
	}
}

VehicleManager::VehicleManager(const VehicleManager& other)
{
	copy(other);
}

VehicleManager& VehicleManager::operator=(const VehicleManager& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

VehicleManager::~VehicleManager()
{
	free();
}

void VehicleManager::print() const
{
	size_t size = list.getSize();

	for (size_t i = 0; i < size; i++) {
		list[i]->display();
		std::cout << std::endl;
	}
}

void VehicleManager::createCar(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
	const String& brand, const String& model, const String& fuelType)
{
	list.pushBack(new Car(maxPassengers, maxSpeed, name, year, color, doorsCount, brand, model, fuelType));

	String newCar = "Car, ";
	newCar += name;
	newCar += " ,is added.\n";
	log.pushBack(newCar);
}

void VehicleManager::createTruck(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
	const String& brand, size_t capacity)
{
	list.pushBack(new Truck(maxPassengers, maxSpeed, name, year, color, doorsCount, brand, capacity));

	String newTruck = "Truck, ";
	newTruck += name;
	newTruck += " ,is added.\n";
	log.pushBack(newTruck);
}

void VehicleManager::createMotorcycle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
	const String& brand, const String& model, const String& frameType)
{
	list.pushBack(new Motorcycle(maxPassengers, maxSpeed, name, year, color, doorsCount,
		brand, model, frameType));

	String newMotorcycle = "Motorcycle, ";
	newMotorcycle += name;
	newMotorcycle += " ,is added.\n";
	log.pushBack(newMotorcycle);
}

void VehicleManager::createPlane(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan, double maxAltitude,
	const String& color, const String& model, double maxStorage, double maxAirTime)
{
	list.pushBack(new Plane(maxPassengers, maxSpeed, name, year, wingspan, maxAltitude, color, model, maxStorage, maxAirTime));

	String newPlane = "Plane, ";
	newPlane += name;
	newPlane += " ,is added.\n";
	log.pushBack(newPlane);
}

void VehicleManager::createPrivateJet(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan, double maxAltitude,
	const String& color, const String& model, bool hasDrinkBar, bool hasSleepingRoom)
{
	list.pushBack(new PrivateJet(maxPassengers, maxSpeed, name, year, wingspan, maxAltitude, color, model, hasDrinkBar, hasSleepingRoom));

	String newPrivateJet = "Private jet, ";
	newPrivateJet += name;
	newPrivateJet += " ,is added.\n";
	log.pushBack(newPrivateJet);
}

void VehicleManager::createJacht(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double width, double length, size_t crewSize, const String& color,
	const String& model, bool hasSwimmingPool, size_t roomCount)
{
	list.pushBack(new Jacht(maxPassengers, maxSpeed, name, year, length, width, crewSize, color, model, hasSwimmingPool, roomCount));

	String newJacht = "Jacht, ";
	newJacht += name;
	newJacht += " ,is added.\n";
	log.pushBack(newJacht);
}

void VehicleManager::createSail(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double width, double length, size_t crewSize, const String& color,
	const String& model, bool hasEngine, size_t sailsCount)
{
	list.pushBack(new Jacht(maxPassengers, maxSpeed, name, year, length, width, crewSize, color, model, hasEngine, sailsCount));

	String newSail = "Sail, ";
	newSail += name;
	newSail += " ,is added.\n";
	log.pushBack(newSail);
}

void VehicleManager::sellVehicle(size_t index)
{
	if (index >= list.getSize())
		throw "Unavailable index!";

	delete list[index];
	list.popAt(index);

	log.pushBack(String("A vehicle was deleted.\n"));
}

void VehicleManager::showNewestVehicle() const
{
	size_t newestVehicleIndex = 0;
	int newestYear = 0;
	size_t size = list.getSize();

	for (size_t i = 0; i < size; i++) {
		if (list[i]->getYear() > newestYear) {
			newestYear = list[i]->getYear();
			newestVehicleIndex = i;
		}
	}

	list[newestVehicleIndex]->display();
}

void VehicleManager::showOldestVehicle() const
{
	size_t oldestVehicleIndex = 0;
	int oldestYear = BIG_NUMBER;
	size_t size = list.getSize();

	for (size_t i = 0; i < size; i++) {
		if (list[i]->getYear() < oldestYear) {
			oldestYear = list[i]->getYear();
			oldestVehicleIndex = i;
		}
	}

	list[oldestVehicleIndex]->display();
}

void VehicleManager::showFastestVehicle() const
{
	size_t maxSpeed = 0;
	size_t maxSpeedIndex;

	size_t size = list.getSize();

	for (size_t i = 0; i < size; i++)
	{
		if (list[i]->getMaxSpeed() > maxSpeed)
		{
			maxSpeed = list[i]->getMaxSpeed();
			maxSpeedIndex = i;
		}
	}

	list[maxSpeedIndex]->display();
}

void VehicleManager::printCount() const
{
	std::cout << "Vehicles count: " << list.getSize() << std::endl;
}

void VehicleManager::save() const
{
	std::fstream file("actions.txt", std::ios::out);

	if (!file.is_open())
	{
		throw "Undefined behaviour!";
	}

	size_t logSize = log.getSize();

	for (size_t i = 0; i < logSize; i++) {
		file << log[i];
	}

	std::cout << "Actions.txt is successufully saved!" << std::endl;

	file.close();
}
