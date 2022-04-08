#include <iostream>
#include "Dates.h"

const short DEFAULT = 1;
const short DEFAULT_YEAR = 2000;

//Constructors
Date::Date()
{
	days = month = DEFAULT;
	year = DEFAULT_YEAR;
}

Date::Date(const int _days, const int _month, const int _year)
{
	days = _days;
	month = _month;
	year = _year;
}

//Methods to Add/Remove days
void Date::addDays(const int _days)
{
	int dd = days + _days;
	int DaysInMonth = NumDaysInMonth(month,year);
	while (dd > DaysInMonth)
	{
		dd -= DaysInMonth;
		month++;
		if (month > 12)
		{
			year++;
			month = 1;
		}
	DaysInMonth = NumDaysInMonth(month, year);
	}
	days = dd;
}

void Date::substractDays(const int _days)
{
	if (_days < days)
		days -= _days;
	else
	{
		int dd = abs(days - _days);
		month--;
		if (month < 1)
		{
			year--;
			month = 12;
		}

		int DaysInMonth = NumDaysInMonth(month, year);
		while (dd >= DaysInMonth)
		{
			dd -= DaysInMonth;
			month--;
			if (month < 1)
			{
				year--;
				month = 12;
			}
			DaysInMonth = NumDaysInMonth(month, year);
		}
		days = DaysInMonth - dd;
	}
}

//Methods calculating days - Date to Date
long long Date::daysBetweenDates(const Date& _other) const
{
	return abs(sumOfDays(*this) - sumOfDays(_other));
}
long long Date::daysToXmas() const
{
	int temp_year = (month == 12 && days > 25) ? year + 1 : year;
	const Date Xmas(25, 12,year);
	return(daysBetweenDates(Xmas));
}
long long Date::daysToNewYear() const
{
	const Date NewYear(1, 1, year + 1);
	return(daysBetweenDates(NewYear));
}

//Flags
bool Date::isLeapYear() const
{
	return isLeap(year);
}

bool Date::isLaterThan(const Date& _other) const
{
	if (sumOfDays(*this) - sumOfDays(_other) < 0)
		return true;

	return false;
}

//Accessors
int Date::getDays() const
{
	return days;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}

void Date::Display() const
{
	if (days < 10)
		std::cout << "Current Date is: 0" << days;
	else
		std::cout << "Current Date is: " << days;

	if (month < 10)
		std::cout << "/0" << month << "/" << year;
	else
		std::cout << month << "/" << year;
}

//Private functions
long long Date::sumOfDays(const Date& _other) const
{
	long long sum = 0;
	sum += _other.days;
	for (size_t i = 0; i < _other.month - 1; i++)
		sum += NumDaysInMonth(_other.month, _other.year);
	sum += _other.year * 365;
	
	return sum;
}
int Date::isLeap(int year) const
{
	return (year % 100 == 0) ? ((year % 400) == 0) : (year % 4 == 0);
}
int Date::NumDaysInMonth(int month, int year) const
{
	if (month <= 7)
	{
		if(month != 2)
				return 30 + (month % 2);
			else
				return (isLeap(year)) ? 29 : 28;
	}
	else
		return 30 + ((month + 1) % 2);
}
