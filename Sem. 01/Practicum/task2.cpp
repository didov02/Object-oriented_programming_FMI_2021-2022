#include <iostream>

enum Year {
    first,
    second,
    third,
    fourth
};

struct Student {
    int fn;
    Year year;
    double averageGrade;
};

Student initStudent(int fn, Year year, double grade) {
    Student student;
    student.fn = fn;
    student.year = year;
    student.averageGrade = grade;

    return student;
}

void printStudent(const Student& student) {
    std::cout << "Faculty number: " << student.fn << std::endl << "Year: ";
    switch (student.year) {
    case first: std::cout << "first"; break;
    case second: std::cout << "second"; break;
    case third: std::cout << "third"; break;
    case fourth: std::cout << "fourth"; break;
    default: std::cout << "error"; break;
    }
    std::cout << std::endl << "Grade: " << student.averageGrade << std::endl;
}

int main()
{
    Year year = first;
    Student student = initStudent(12345, year, 5.50);
    printStudent(student);
}
