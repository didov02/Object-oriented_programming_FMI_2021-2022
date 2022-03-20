#include <iostream>
#include <fstream>

bool checkFile(infstream& file)
{
    return file.is_open();
}

int lengthOfFile(const char* fileName) {
    std::ifstream inFile(fileName);
    
    if(!checkFile(inFile))
        return -1;
    
    int ctr = 0;
    while (!inFile.eof()) {
        inFile.get();
        ctr++;
    }

    return ctr - 1;
}

int main()
{
    std::cout << lengthOfFile("result.txt"); // from task 2
}
