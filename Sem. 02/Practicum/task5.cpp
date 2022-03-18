#include <iostream>
#include <fstream>
const int MAX_RELATION_SIZE = 25;

struct Pair {
    int x;
    int y;
};

struct Relation {
    Pair pairs[MAX_RELATION_SIZE];
    int size = 0;
};

Pair createPair(int a, int b) {
    return { a, b };
}

void initPair(Pair& pair, int a, int b) {
    pair.x = a;
    pair.y = b;
}

void addPairToRelation(Relation& r, int x, int y) {
    //


    Pair pair = createPair(x, y);
    r.pairs[r.size++] = pair;
}

void writePairToFile(const Pair& pair, std::ofstream& os) {
    os << pair.x << " " << pair.y << std::endl;
}

Pair readPairFromFile(std::ifstream& is) {
    Pair pair;
    int x, y;
    is >> x >> y;
    initPair(pair, x, y);
    return pair;
}

void writeRelationToFile(const Relation& r, const char* fileName) {
    std::ofstream outFile(fileName);

    if (!outFile.is_open()) {
        std::cout << "Error while opening file";
        return;
    }

    outFile << r.size << std::endl;

    for (int i = 0; i < r.size; i++) {
        writePairToFile(r.pairs[i], outFile);
    }
}

Relation readRelationFromFile(const char* fileName) {
    std::ifstream inFile(fileName);
    Relation r;
    if (!inFile.is_open()) {
        std::cout << "Error while opening file";
        return Relation();
    }

    int size;
    inFile >> size;
    for (int i = 0; i < size; i++) {
        int x, y;
        inFile >> x >> y;
        addPairToRelation(r, x, y);
    }

    return r;
}

int main() {
    //A = {1,2,3,4}
    //Relation r; // <
    //addPairToRelation(r, 1, 2);
    //addPairToRelation(r, 1, 3);
    //addPairToRelation(r, 1, 4);
    //addPairToRelation(r, 2, 3);
    //addPairToRelation(r, 2, 4);
    //addPairToRelation(r, 3, 4);

    //writeRelationToFile(r, "relation.txt");

    //Relation r1;
    //r1 = readRelationFromFile("relation.txt");

}