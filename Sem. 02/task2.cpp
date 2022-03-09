#include <iostream>
#include <fstream>

bool copyFile(const char* source, const char* dest)
{
	std::ifstream inputFile(source); //read source file
	std::ofstream outputFile(dest); //write to dest file

	if (!inputFile.is_open() || !outputFile.is_open()) //Check whether files are open/found.
		return false; //Error while copying

	while (!inputFile.eof()) //loop till end of Source file 
	{
		char line[1024];
		inputFile.getline(line, 1024); //line by line of Source file to buffer
		outputFile << line << std::endl; //write line by line to dest file.
	}
	
	//Close both files
	inputFile.close();
	outputFile.close();
	
	return true; //Succesfully copied
}

int main()
{
	if (copyFile("Source.cpp", "AnotherSource.cpp"))
	{
		std::cout << "Succesfully copied!";
	}
	else
	{
		std::cout << "Error while copying!";
	}
	
	return 0;
}