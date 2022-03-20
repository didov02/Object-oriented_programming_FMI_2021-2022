#include <iostream>

enum WeatherDataType
{
	Temperature,
	Wind
};

enum DayOfWeek
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

enum Direction
{
	North,
	North_East,
	East,
	South_East,
	South,
	South_West,
	West,
	North_West
};

struct TempData
{
	unsigned StationId;
	DayOfWeek day;
	double current;
	double max;
	double min;
};

struct WindData
{
	unsigned StationId;
	DayOfWeek day;
	unsigned speed;
	Direction direction;
};

struct Input
{
	WeatherDataType type;
	union
	{
		TempData temp;
		WindData wind;
	};
};

bool Process_Temp(const TempData& t)
{
	return t.current >= 15 && !(t.min < 10 && t.max > 27);
}
bool Process_Wind(const WindData& w)
{
	return w.speed <= 5;
}

int main()
{
	// Container for all the data records
	Input inputs[2];
	size_t size = 2;
	inputs[0].type = WeatherDataType::Temperature;
	inputs[0].temp = { 101, Monday, 27.8, 33.1, 24.9 };

	inputs[1].type = WeatherDataType::Wind;
	inputs[1].wind = { 204, Tuesday, 14, North_West };

	for (size_t i = 0; i < size; i++)
	{
		switch (inputs[i].type)
		{
		case WeatherDataType::Temperature:
			if (Process_Temp(inputs[i].temp))
				std::cout << "Temperature is okay" << std::endl;
			else
				std::cout << "Temperature is uncovenient" << std::endl;
			break;
		case WeatherDataType::Wind:
			if (Process_Wind(inputs[i].wind))
				std::cout << "Wind is okay" << std::endl;
			else
				std::cout << "Wind is unfavorable" << std::endl;
			break;
		default:
			break;
		}
	}
	return 0;
}