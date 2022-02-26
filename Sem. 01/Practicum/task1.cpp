#include <iostream>

struct ComplexNumber {
    double realPart;
    double imaginaryPart;
};

ComplexNumber sum(const ComplexNumber& ls, const ComplexNumber& rs) {
    ComplexNumber res;
    res.realPart = ls.realPart + rs.realPart;
    res.imaginaryPart = ls.imaginaryPart + rs.imaginaryPart;
    return res;
}

void printComplexNumber(const ComplexNumber& cn) {
    std::cout << cn.realPart << "+ i*" << cn.imaginaryPart << std::endl;
}



int main()
{
    ComplexNumber c1 = { 1, 1 };
    ComplexNumber c2 = { 2, 2 };
    ComplexNumber c3 = sum(c1, c2);
    printComplexNumber(c3);
}
