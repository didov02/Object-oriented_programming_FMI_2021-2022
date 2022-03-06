#include <iostream>
#include <fstream>

int lengthOfFile(const char* fileName) {
    std::ifstream inFile(fileName);
    int ctr = 0;
    while (!inFile.eof()) {
        inFile.get();
        ctr++;
    }

    return ctr;
}

int main()
{
    std::cout << lengthOfFile("result.txt"); // from task 1
}
