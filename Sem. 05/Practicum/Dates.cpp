#include "Dates.h"
#include <iostream>

#pragma region Dates::methods 
int Date::getDaysInMonth(int Month, int Year) const 
{
    (Month < 1) ? Month = 12 : Month;
    switch (Month) 
    {
        case Months::January:
            return 31;
        case Months::February:
            if (isLeapYear(Year))
            {
                return 29;
            }
            else 
            {
                return 28;
            }
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
    }
}
Date::Date() : Day(1), Month(1), Year(2000) {};
Date::Date(int Day, Months Month, int Year) 
{
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
}
bool Date::isLeapYear(int Year) const 
{
    (Year == 0) ? Year = this->Year : Year;
    if (Year % 4 == 0)
    {
        if (Year % 400 == 0)
        {
            return true;
        }
        else if (Year % 100 == 0)
        {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}
void Date::addDays(int DaysCount) 
{
    int DaysInMonth;
    while (true) 
    { 
        DaysInMonth = getDaysInMonth(Month, Year);  
        if ((DaysCount - (DaysInMonth - Day)) <= 0)
        {
            Day += DaysCount;
            break;
        }
        else 
        {
            DaysCount -= (getDaysInMonth(Month, Year) - Day);
            (Month > 11) ? Month = Months::January, Year++ : Month++;
            (Day != 0) ? Day = 0 : Day;
        }
    }
}
void Date::printDate() const 
{
    (Day < 10) ? std::cout << '0' << Day << '.' : std::cout << Day << '.';
    (Month < 10) ? std::cout << '0' << Month << '.' : std::cout << Month << '.';
    std::cout << Year << std::endl;
}
bool Date::isEarlierThan(const Date& date) const 
{
    if(Year < date.getYear() || Month < date.getMonth() || Day < date.getDays()) 
    {
        return true;
    }
    return false;
}
void Date::removeDays(int DaysCount) 
{
    while (true) 
    {   
        int DaysInMonth = getDaysInMonth(Month - 1, Year);
        if ((DaysCount - Day) <= 0)
        {
            ((DaysCount - Day) == 0) ? Day = DaysInMonth, (Month--) : Day -= DaysCount;
            (Month < 1) ? Month = Months::December, (Year--) : Month;
            (Year < 1) ? Day = 0, Month = 0, Year = 0 : Year;
            break;
        }
        else 
        {
            DaysCount -= Day;
            (Month < 2) ? Month = Months::December, Year-- : Month--;
            (Year < 1) ? Day = 0, Month = 0, Year = 0 : Year;
            Day = DaysInMonth;
        }
    }
}
int Date::daysUntilCurrentDate(const Date& other)  
{
    int DaysInMonth;
    int DaysCount = 0;
        int otherDays = other.getDays();
        int otherMonths = other.getMonth();
        int otherYear = other.getYear();
    if(Year > otherYear || (Year == otherYear && otherMonths < Month) || (Year == otherYear && otherMonths == Month && otherDays < Day)) 
    {
        return -1;
    }
        int thisDays = Day;
        int thisMonths = Month;
        int thisYear = Year;
    while ((thisYear != otherYear) || (thisMonths != otherMonths) || (thisDays != otherDays))
    {
        DaysInMonth = getDaysInMonth(thisMonths, thisYear);
        if ((otherMonths == thisMonths) && (otherYear == thisYear))
        {
            return (DaysCount + (otherDays - thisDays));
        }
        (otherMonths > thisMonths || otherYear > thisYear) ? DaysCount += (DaysInMonth - thisDays), thisDays = 0, thisMonths++ : DaysCount;
        (thisMonths > 12) ? thisMonths = Months::January, thisYear++ : thisMonths;
    }
}
int Date::daysToXmas() 
{
    if (Month == December && Day > 25)
    {
        Date temp(25, Months::December, Year + 1);
        return daysUntilCurrentDate(temp);
    }
    else 
    {
        Date temp(25, Months::December, Year);
        return daysUntilCurrentDate(temp);
    }
}
int Date::daysToEndOfTheYear() 
{
    Date temp(1, Months::January, Year + 1);
    return daysUntilCurrentDate(temp);  
}
#pragma endregion