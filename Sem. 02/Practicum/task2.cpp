#include <iostream>
#include <fstream>

bool getDiff(const char* fileName)
{
    std::ifstream inFile(fileName);

    if (!inFile.is_open()) {
        std::cout << "Error while opening the file";
        return 0;
    }

    int sum, product;
    inFile >> sum >> product;
    std::cout << sum - product;
    return 1;
}


int main()
{
    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;
    std::ofstream outFile("result.txt");

    if (!outFile.is_open()) {
        std::cout << "Error while opening the file";
        return -1;
    }

    outFile << num1 + num2 + num3 << " " << num1 * num2 * num3;
    outFile.close();
    getDiff("result.txt");
}
