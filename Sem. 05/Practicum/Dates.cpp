#include "Dates.h"
#include <iostream>

int Date::getDaysInMonth(int Month, int Year) const 
{
        (Month < 1) ? Month = Months::December : Month;
    switch (Month) 
    {
        case Months::January:
            return 31;
        case Months::February:
            if (isLeapYear())
            {
                return 29;
            }
            return 28;
        case Months::March:
            return 31;
        case Months::April:
            return 30;
        case Months::May: 
            return 31;
        case Months::Jun: 
            return 30;
        case Months::July: 
            return 31;
        case Months::August: 
            return 31;
        case Months::September: 
            return 30;
        case Months::October: 
            return 31;
        case Months::November: 
            return 30;
        case Months::December: 
            return 31;
        default: 
            return -1;
    }
}
Date::Date() : Day(1), Month(1), Year(2000) {};
Date::Date(int Day, int Month, int Year) 
{
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
}
bool Date::isLeapYear() const 
{
    if ((Year % 4 == 0))
    {
        if ((Year % 100 == 0) && (Year % 400 != 0))
        {
            return false;
        }
        return true;
    }
    return false;
}
void Date::addDays(int DaysCount) 
{
    int DaysInMonth = getDaysInMonth(Month, Year);
    while ((DaysCount - (DaysInMonth - Day)) > 0) 
    {
        DaysCount -= (DaysInMonth - Day);
        (Month > 11) ? Month = Months::January, Year++ : Month++;
        DaysInMonth = getDaysInMonth(Month, Year); 
        (Day != 0) ? Day = 0 : Day;
    }
        Day += DaysCount;
}
void Date::printDate() const 
{
    (Day < 10) ? std::cout << '0' << Day << '.' : std::cout << Day << '.';
    (Month < 10) ? std::cout << '0' << Month << '.' : std::cout << Month << '.';
    std::cout << Year << std::endl;
}
bool Date::isEarlierThan(const Date& date) const 
{
    if(Year < date.getYear() || (Year == date.getYear() && Month < date.getMonth()) || 
    (Year == date.getYear() && Month == date.getMonth() && Day < date.getDays())) 
    {
        return true;
    }
    return false;
}
void Date::removeDays(int DaysCount) 
{
    while ((DaysCount - Day) > 0) 
    {
        DaysCount -= Day;
        (Month < 2) ? Month = Months::December, Year-- : Month--;
        Day = getDaysInMonth(Month, Year);   
    }
        ((DaysCount - Day) == 0) ? Day = getDaysInMonth(Month - 1, Year), (Month--) : Day -= DaysCount;
        (Month < 1) ? Month = Months::December, (Year--) : Month;
        (Year < 1) ? Day = 0, Month = 0, Year = 0 : Year;
}
long long Date::daysBetweenDates(const Date& other)  
{
    int DaysInMonth;
    int DaysCount = 0;
        int otherDays = other.getDays();
        int otherMonths = other.getMonth();
        int otherYear = other.getYear();
    if((Year > otherYear) || (Year == otherYear && otherMonths < Month) || (Year == otherYear && otherMonths == Month && otherDays < Day)) 
    {
        return -1;
    }
        int thisDays = Day;
        int thisMonths = Month;
        int thisYear = Year;
    while ((Year != otherYear) || (Month != otherMonths) || (Day != otherDays))
    {
        DaysInMonth = getDaysInMonth(Month, Year);
        if ((otherMonths == Month) && (otherYear == Year))
        {
            if (Day == 0) 
            {
                Day = thisDays;
                Month = thisMonths;
                Year = thisYear;
                return (DaysCount + otherDays);   
            }
            return (DaysCount + (otherDays - Day));
        }
        (otherMonths > Month || otherYear > Year) ? DaysCount += (DaysInMonth - Day), Day = 0, Month++ : DaysCount;
        (Month > 12) ? Month = Months::January, Year++ : Month;
    }
}
long long Date::daysToXmas() 
{
    if (Month == December && Day > 25)
    {
        Date temp(25, Months::December, Year + 1);
        return daysBetweenDates(temp);
    }
    else 
    {
        Date temp(25, Months::December, Year);
        return daysBetweenDates(temp);
    }
}
long long Date::daysToNewYear()  
{
    Date temp(1, Months::January, Year + 1);
    return daysBetweenDates(temp);  
}
