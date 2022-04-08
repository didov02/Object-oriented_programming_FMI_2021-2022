#include <iostream>
#include "Interval.h"
using namespace std;

int main()
{
    IntervalComponents t1(3, 10);
    IntervalComponents t2(4, 14); 
    IntervalComponents t3; // [0, 0]
    IntervalComponents t4(4, 10);

   // cout << t1.getLength() << endl;
   // cout << boolalpha << t1.isInInterval(4);
   // cout << t2.calcPrimeNumbersInTheInterval();
   // cout << t4.numberOfPalindroms() << endl;
   //cout << t2.noRepeatingDigits();
   //cout << boolalpha << t2.isPowerOfTwo();

   //IntervalComponents t5 = t1.section(t2); 
   //cout << t5.a << t5.b << endl;
   // cout << boolalpha << t2.uInterval(t4);
}