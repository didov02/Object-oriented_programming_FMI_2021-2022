#pragma once

enum Months 
{
    January = 1, 
    February, 
    March, 
    April, 
    May, 
    Jun,
    July, 
    August, 
    September, 
    October, 
    November, 
    December
};
class Date 
{
    public: 
        Date();
        Date(int Day, Months Month, int Year); 
        void addDays(int DaysCount); 
        int getDays() const { return Day; };
        int getMonth() const { return Month; };
        int getYear() const { return Year; };
        void removeDays(int DaysCount); 
        int daysToXmas();
        bool isLeapYear(int Year = 0) const;
        bool isEarlierThan(const Date& date) const;
        int daysToEndOfTheYear();
        void printDate() const;
        int daysUntilCurrentDate(const Date& date);
    private: 
        int Day;
        int Month;
        int Year;
        int getDaysInMonth(int, int) const;
};