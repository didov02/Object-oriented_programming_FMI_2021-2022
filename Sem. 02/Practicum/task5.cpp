#include <iostream>
#include <fstream>
const int MAX_RELATION_SIZE = 25;

struct Pair
{
	int x;
	int y;
};
Pair createPair(int a, int b)
{
	return { a, b };
}
void initPair(Pair& pair, int a, int b) {
	pair.x = a;
	pair.y = b;
}
void writePairToFile(std::ofstream& os, const Pair& pair)
{
	os << pair.x << " " << pair.y << std::endl;
}
Pair readPairFromFile(std::ifstream& is)
{
	int x, y;
	is >> x >> y;
	return createPair(x, y);
}
void printPair(const Pair& p)
{
	std::cout << p.x << " " << p.y << std::endl;
}

struct Relation
{
	Pair data[MAX_RELATION_SIZE];
	size_t size = 0;
};
bool checkSize(const Relation& r)
{
	return r.size < MAX_RELATION_SIZE;
}
bool addPairToRelation(Relation& r, int x, int y)
{
	if (!checkSize(r))
		return false;

	Pair pair = createPair(x, y);
	r.data[r.size++] = pair;
	return true; //success
}
bool addPairToRelation(Relation& r, const Pair& p)
{
	if (!checkSize(r))
		return false;

	r.data[r.size++] = p;
	return true; //success
}
bool writeRelationToFile(const Relation& r, const char* fileName)
{
	std::ofstream outFile(fileName);

	if (!outFile.is_open()) {
		std::cout << "Error while opening file";
		return false;
	}

	outFile << r.size << std::endl;

	for (size_t i = 0; i < r.size; i++)
	{
		writePairToFile(outFile, r.data[i]);
	}
	return true; //success
}
Relation readRelationFromFile(const char* fileName)
{
	std::ifstream inFile(fileName);

	Relation R;
	if (!inFile.is_open()) {
		std::cout << "Error while opening file";
		return Relation();
	}

	size_t size;
	inFile >> size;
	for (size_t i = 0; i < size; i++)
	{
		addPairToRelation(R, readPairFromFile(inFile));
	}

	inFile.close();
	return R;
}
void printRelation(const Relation& r)
{
	for (size_t i = 0; i < r.size; i++)
		printPair(r.data[i]);
}

int main() {
	Relation example;

	addPairToRelation(example, 1, 2);
	addPairToRelation(example, 1, 3);
	addPairToRelation(example, 1, 4);
	addPairToRelation(example, 2, 3);
	addPairToRelation(example, 2, 4);
	addPairToRelation(example, 3, 4);

	printRelation(example);
	std::cout << std::endl;
	writeRelationToFile(example,"relation.txt");
	printRelation(readRelationFromFile("relation.txt"));
}