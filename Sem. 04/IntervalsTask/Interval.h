#pragma once

class IntervalComponents {
public:
	int a;
	int b;

	IntervalComponents();
	IntervalComponents(int, int);

	int getLength() const;
	bool isInInterval(const int) const;
	unsigned int calcPrimeNumbersInTheInterval()const;
	int numberOfPalindroms() const;
	int noRepeatingDigits()const;
	bool isPowerOfTwo();
	IntervalComponents section(IntervalComponents&);
	bool uInterval(const IntervalComponents&) const;
};