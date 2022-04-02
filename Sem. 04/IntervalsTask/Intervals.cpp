#include <iostream>
#include "Interval.h"
using namespace std;

IntervalComponents::IntervalComponents() : a(0), b(0) {}

IntervalComponents::IntervalComponents(int a, int b)
{
	if (a <= b) {
		this->a = a;
		this->b = b;
	}
	else {
		this->a = 0;
		this->b = 0;
	}
}

int IntervalComponents::getLength() const
{
	return b - a;
}

bool IntervalComponents::isInInterval(const int number) const
{
	if ((number > this->a || number < this->b) || number == this->a || number == this->b)
		return true;
	return false;
}

unsigned int IntervalComponents::calcPrimeNumbersInTheInterval() const
{
	int counter = 0;
    bool isPrime = 0;
    for (int i = a; i <= b; i++) {

        if (i == 1 || i == 0)
            continue;

        isPrime = 1;

        for (int j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
            counter++;
    }
	return counter;
}

int IntervalComponents::numberOfPalindroms() const
{ 
    int counter = 0;

    for (int j = a; j <= b; j++) {
        int rev = 0;
        for (int i = j; i > 0; i /= 10) {
            rev = rev * 10 + i % 10;
        }
        if (j == rev) {
            counter++; 
        }
    }
    return counter;
}

int IntervalComponents::noRepeatingDigits() const
{
    int x = a;
    int y = b;
    int counter = 0;
    for (int i = x; i <= y; i++) {
        int res = 0;

        int counterr[10] = {0};
        int number = i; 

        while (number > 0) {

            int lastDigit = number % 10;

            counterr[lastDigit]++;

            number = number / 10;
        }

        for (int j = 0; j < 10; j++) {
            if (counterr[j] > 1) {
                res++;
            }
        }

        if (res == 0) {
            counter++;
        }
    }
    int length = getLength()+1; 
    return length-counter;
}

bool IntervalComponents::isPowerOfTwo()
{
    if (a == 0)
        return false;
    while (a != 1)
    {
        if (a % 2 != 0)
            return false;
        a = a / 2;
    }
    if (b == 0)
        return false;
    while (b != 1)
    {
        if (b % 2 != 0)
            return false;
        b = b / 2;
    }
    return true;
}

IntervalComponents IntervalComponents::section(IntervalComponents& inter)
{
    if (this->a > inter.a)
        inter.a = this->a;
    if (this->b < inter.b)
        inter.b = this->b;
    return inter;
}

bool IntervalComponents::uInterval(const IntervalComponents& intr) const
{
    if (intr.a >= a && intr.b <= b)
        return true;
    return false;
}

