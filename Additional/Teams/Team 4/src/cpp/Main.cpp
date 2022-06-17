#include <iostream>
#include "String.h"
#include "VehicleManager.h"
#include <cstring>

#pragma warning (disable:4996)

const int MAX_SIZE = 50;

void Menu()
{
	std::cout << "1. Buy" << std::endl;
	std::cout << "2. Sell" << std::endl;
	std::cout << "3. Show newest vehicle" << std::endl;
	std::cout << "4. Show oldest vehicle" << std::endl;
	std::cout << "5. Show fastest vehicle" << std::endl;
	std::cout << "6. Show all vehicles" << std::endl;
	std::cout << "7. Count of vehicles" << std::endl;
	std::cout << "8. Save garage" << std::endl;
	std::cout << "9. Quit" << std::endl << std::endl;
}

int main()
{
	Menu();

	VehicleManager garage;

	while (true)
	{
		std::cout << "Your option: ";

		char* option = new char[MAX_SIZE];
		std::cin.getline(option, MAX_SIZE);

		if (strcmp(option, "Buy") == 0)
		{
			std::cout << "What type of vehicle do you want to buy: Ground, Air, Water" << std::endl;

			String typeOfVehicle;
			std::cin >> typeOfVehicle;
			std::cin.ignore();

			if (typeOfVehicle == "Ground")
			{
				std::cout << "What ground vehicle do you want to buy: Car, Motorcycle, Truck" << std::endl;

				String vehicle;
				std::cin >> vehicle;

				if (vehicle == "Car")
				{
					std::cout << "Car's name: ";
					String carsPersonalName;
					std::cin >> carsPersonalName;

					std::cout << "Brand: ";
					String brand;
					std::cin >> brand;

					std::cout << "Model: ";
					String model;
					std::cin >> model;

					std::cout << "Fuel: ";
					String fuel;
					std::cin >> fuel;

					std::cout << "Color: ";
					String color;
					std::cin >> color;

					std::cout << "Max speed: ";
					size_t maxSpeed;
					std::cin >> maxSpeed;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					std::cout << "Doors count: ";
					size_t doors;
					std::cin >> doors;

					std::cout << "Max passengers: ";
					size_t maxPassengers;
					std::cin >> maxPassengers;
					std::cin.ignore();

					garage.createCar(maxPassengers, maxSpeed, carsPersonalName, year, color, doors, brand, model, fuel);
				}
				else if (vehicle == "Motorcycle")
				{
					std::cout << "Motorcycle's name: ";
					String motorcyclePersonalName;
					std::cin >> motorcyclePersonalName;

					std::cout << "Brand: ";
					String brand;
					std::cin >> brand;

					std::cout << "Model: ";
					String model;;
					std::cin >> model;

					std::cout << "Frame type: ";
					String frameType;
					std::cin >> frameType;

					std::cout << "Color: ";
					String color;
					std::cin >> color;

					std::cout << "Max speed: ";
					size_t maxSpeed;
					std::cin >> maxSpeed;
					
					std::cout << "Max passengers: ";
					size_t maxPassengers;
					std::cin >> maxPassengers;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;
					std::cin.ignore();

					garage.createMotorcycle(maxPassengers, maxSpeed, motorcyclePersonalName, year, color, 0, brand, model, frameType);
				}
				else if (vehicle == "Truck")
				{
					std::cout << "Truck's name: ";
					String truckPersonalName;
					std::cin >> truckPersonalName;

					std::cout << "Brand: ";
					String brand;
					std::cin >> brand;

					std::cout << "Color: ";
					String color;
					std::cin >> color;

					std::cout << "Capacity: ";
					size_t capacity;
					std::cin >> capacity;

					std::cout << "Max speed: ";
					size_t maxSpeed;
					std::cin >> maxSpeed;

					std::cout << "Max passengers: ";
					size_t maxPassengers;
					std::cin >> maxPassengers;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					std::cout << "Doors count: ";
					size_t doors;
					std::cin >> doors;
					std::cin.ignore();

					garage.createTruck(maxPassengers, maxSpeed, truckPersonalName, year, color, doors, brand, capacity);
				}
				else
				{
					std::cout << "You can't buy such type of vehicle. Try again!" << std::endl;
				}
			}
			else if (typeOfVehicle == "Air")
			{
				std::cout << "What air vehicle do you want to buy: Plane, PrivateJet" << std::endl;
				String vehicle;
				std::cin >> vehicle;

				if (vehicle == "Plane")
				{
					std::cout << "Plane's name: ";
					String planeName;
					std::cin >> planeName;

					std::cout << "Plane's max passengers: ";
					size_t planePassengers;
					std::cin >> planePassengers;

					std::cout << "Plane's max speed: ";
					size_t planeSpeed;
					std::cin >> planeSpeed;

					std::cout << "Plane's wingspan: ";
					double planeWingspan;
					std::cin >> planeWingspan;

					std::cout << "Plane's max altitude: ";
					double planeAltitude;
					std::cin >> planeAltitude;

					std::cout << "Plane's year of creation: ";
					size_t planeYear;
					std::cin >> planeYear;

					std::cout << "Plane's color: ";
					String planeColor;
					std::cin >> planeColor;

					std::cout << "Plane's model: ";
					String planeModel;
					std::cin >> planeModel;

					std::cout << "Plane's max storage: ";
					double planeStorage;
					std::cin >> planeStorage;
					
					std::cout << "Plane's max air time: ";
					double planeAirtime;
					std::cin >> planeAirtime;
					std::cin.ignore();
					
					garage.createPlane(planePassengers, planeSpeed, planeName, planeYear, planeWingspan, planeAltitude, planeColor, planeModel, planeStorage, planeAirtime);
				}
				else if (vehicle == "PrivateJet")
				{
					std::cout << "PrivateJet's name: ";
					String PrivateJetName;
					std::cin >> PrivateJetName;

					std::cout << "PrivateJet's max passengers: ";
					size_t PrivateJetPassengers;
					std::cin >> PrivateJetPassengers;

					std::cout << "Plane's max speed: ";
					size_t PrivateJetSpeed;
					std::cin >> PrivateJetSpeed;

					std::cout << "PrivateJet's wingspan: ";
					double PrivateJetWingspan;
					std::cin >> PrivateJetWingspan;

					std::cout << "Privatejet's max altitude: ";
					double PrivateJetAltitude;
					std::cin >> PrivateJetAltitude;

					std::cout << "Privatejet's year of creation: ";
					size_t PrivateJetYear;
					std::cin >> PrivateJetYear;

					std::cout << "Privatejet's color: ";
					String PrivateJetColor;
					std::cin >> PrivateJetColor;

					std::cout << "Privatejet's model: ";
					String PrivateJetModel;
					std::cin >> PrivateJetModel;

					std::cout << "Privatejet's drinkbar: ";
					bool hasDrinkBar;
					std::cin >> hasDrinkBar;

					std::cout << "Privatejet's sleeping room: ";
					double sleepingRoom;
					std::cin >> sleepingRoom;
					std::cin.ignore();

					garage.createPrivateJet(PrivateJetPassengers, PrivateJetSpeed, PrivateJetName, PrivateJetYear, PrivateJetWingspan, PrivateJetAltitude, PrivateJetColor, PrivateJetModel, hasDrinkBar, sleepingRoom);
				}
				else
				{
					std::cout << "No such vehicle found here\n";
				}
			}
			else if (typeOfVehicle == "Water")
			{

				std::cout << "What water vehicle do you want to buy: Jacht, Sail" << std::endl;
				String vehicle;
				std::cin >> vehicle;

				if (vehicle == "Jacht")
				{
					std::cout << "Jacht's name: ";
					String jachtName;
					std::cin >> jachtName;

					std::cout << "Jacht's max passengers: ";
					size_t jachtPassengers;
					std::cin >> jachtPassengers;

					std::cout << "Jacht's max speed: ";
					size_t jachtSpeed;
					std::cin >> jachtSpeed;

					std::cout << "Jacht's year of creation: ";
					size_t jachtYear;
					std::cin >> jachtYear;

					std::cout << "Jacht's color: ";
					String jachtColor;
					std::cin >> jachtColor;

					std::cout << "Jacht's model: ";
					String jachtModel;
					std::cin >> jachtModel;

					std::cout << "Jacht's length: ";
					double jachtLength;
					std::cin >> jachtLength;

					std::cout << "Jacht's width: ";
					double jachtWidth;
					std::cin >> jachtWidth;

					std::cout << "Jacht's crew size: ";
					size_t jachtCrew;
					std::cin >> jachtCrew;

					std::cout << "Jacht's swimming pool?: ";
					bool jachtSwimmingPool;
					std::cin >> jachtSwimmingPool;

					std::cout << "Jacht's rooms count: ";
					size_t jachtRooms;
					std::cin >> jachtRooms;
					std::cin.ignore();

					garage.createJacht(jachtPassengers, jachtSpeed, jachtName, jachtYear, jachtWidth, jachtLength, jachtCrew, jachtColor, jachtModel, jachtSwimmingPool, jachtRooms);

				}
				else if (vehicle == "Sail")
				{
					std::cout << "Sail's name: ";
					String sailName;
					std::cin >> sailName;

					std::cout << "Sail's max passengers: ";
					size_t sailPassengers;
					std::cin >> sailPassengers;

					std::cout << "Sail's max speed: ";
					size_t sailSpeed;
					std::cin >> sailSpeed;

					std::cout << "Sail's year of creation: ";
					size_t sailYear;
					std::cin >> sailYear;

					std::cout << "Sail's color: ";
					String sailColor;
					std::cin >> sailColor;

					std::cout << "Sail's model: ";
					String sailModel;
					std::cin >> sailModel;

					std::cout << "Sail's length: ";
					double sailLength;
					std::cin >> sailLength;

					std::cout << "Sail's width: ";
					double sailWidth;
					std::cin >> sailWidth;

					std::cout << "Sail's crew size: ";
					size_t sailCrew;
					std::cin >> sailCrew;

					std::cout << "Sail's has engine?: ";
					bool sailEngine;
					std::cin >> sailEngine;

					std::cout << "Sail's sail count: ";
					size_t sailsCount;
					std::cin >> sailsCount;
					std::cin.ignore();

					garage.createJacht(sailPassengers, sailSpeed, sailName, sailYear, sailWidth, sailLength, sailCrew, sailColor, sailModel, sailEngine, sailsCount);

				}

			}
			else
			{
				std::cout << "No such vehicle found here." << std::endl;
			}
		}
		else if (strcmp(option, "Sell") == 0)
		{
			std::cout << "Which vehicle do you want to sell: ";
			size_t index;
			std::cin >> index;
			std::cin.ignore();

			garage.sellVehicle(index-1);
		}
		else if (strcmp(option, "Show newest vehicle") == 0)
		{
			garage.showNewestVehicle();
		}
		else if (strcmp(option, "Show oldest vehicle") == 0)
		{
			garage.showOldestVehicle();
		}
		else if (strcmp(option, "Show fastest vehicle") == 0)
		{
			garage.showFastestVehicle();
		}	
		else if (strcmp(option, "Show all vehicles") == 0)
		{
			garage.print();
		}
		else if (strcmp(option, "Count of vehicles") == 0)
		{
			garage.printCount();
		}
		else if (strcmp(option, "Save garage") == 0)
		{
			garage.save();
		}
		else if (strcmp(option, "Quit") == 0)
		{
			std::cout << "Have a nice day! Goodbye!" << std::endl;
			delete[] option;
			break;
		}
		else
		{
			std::cout << "No such option!" << std::endl;
		}

		delete[] option;
	}

	return 0;
}