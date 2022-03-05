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

const int GROUP_SIZE = 5;

struct Group {
    Student students[GROUP_SIZE];
    double groupAverageGrade;
};

double calculateAverage(const Group& group) {
    double sum = 0;
    for (int i = 0; i < GROUP_SIZE; i++) {
        sum += group.students[i].averageGrade;
    }
    return sum / GROUP_SIZE;
}

Group initGroup() {
    Group group;
    for (int i = 0; i < GROUP_SIZE; i++) {
        Student student;
        std::cin >> student.fn;
        int year;
        std::cin >> year;
        switch (year)
        {
        case 1: student.year = first; break;
        case 2: student.year = second; break;
        case 3: student.year = third; break;
        case 4: student.year = fourth; break;
        default: std::cout << "Wrong year";
        }
        std::cin >> student.averageGrade;
        group.students[i] = student;
    }
    group.groupAverageGrade = calculateAverage(group);
    return group;
}

int gettingScholarship(const Group& arg, double lowerBound) {
    int res = 0;
    for (int i = 0; i < GROUP_SIZE; i++)
        res += (arg.students[i].averageGrade >= lowerBound);
    return res;
}

int main()
{
    Group group = initGroup();
    std::cout << group.groupAverageGrade;
    std::cout << gettingScholarship(group, 4.50);
}
