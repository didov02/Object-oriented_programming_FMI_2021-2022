#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning (disable: 4996)

const int MAX_BUFFER_SIZE = 1024;
const int MAX_SIZE = 128;
const int MAX_USERS_SIZE = 100;
const int MAX_COMMAND_SIZE = 32;

struct User {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char password[MAX_SIZE];
};

void initUser(User& user, const char* name, const char* email, const char* pass) {
    strcpy(user.name, name);
    strcpy(user.email, email);
    strcpy(user.password, pass);
}

void writeUserToFile(std::ofstream& outFile, const User& user) {
    outFile << user.name << "," << user.email << "," << user.password << std::endl;
}

User readUser(const char* line) {
    User toReturn;
    int size = strlen(line);
    char buff[MAX_SIZE];
    int field = 1;
    for (size_t i = 0, j = 0; i <= size; i++) {
        if (line[i] == ',' || line[i] == '\n') {
            buff[j] = '\0';
            switch (field)
            {
            case 1: strcpy(toReturn.name, buff); break;
            case 2: strcpy(toReturn.email, buff); break;
            }
            field++;
            j = 0;
        }
        else {
            buff[j] = line[i];
            j++;
        }
    }
    strcpy(toReturn.password, buff);
    return toReturn;
}

struct System {
    User users[MAX_USERS_SIZE];
    size_t size = 0;
};

void addUserToSystem(System& sys, const User& user) {
    sys.users[sys.size++] = user;
}

int countLinesInFile(const char* filePath) {
    std::ifstream is(filePath);
    int ctr = 0;
    char buff[MAX_BUFFER_SIZE];
    while (!is.eof()) {
        is.getline(buff, MAX_BUFFER_SIZE);
        ctr++;
    }
    return ctr - 1;
}

void loadSystemFromFile(System& sys, const char* filePath) {
    int size = countLinesInFile(filePath);
    std::ifstream inFile(filePath);
    char line[MAX_SIZE];
    for (size_t i = 0; i < size;i++) {
        inFile.getline(line, 1024);
        sys.users[sys.size++] = readUser(line);
    }
}

void saveSystemToFile(const System& sys, const char* filePath) {
    std::ofstream os(filePath);
    for (size_t i = 0; i < sys.size; i++) {
        writeUserToFile(os, sys.users[i]);
    }
}
bool login(const System& sys, const char* email, const char* pass) { 
    for (size_t i = 0; i < sys.size; i++) {
        if (strcmp(sys.users[i].email, email) == 0) {
            return (strcmp(sys.users[i].password, pass) == 0);
        } 
    }
    return false;
}

void registerUser(System& sys, const char* name, const char* email, const char* pass) {
    User user;
    initUser(user, name, email, pass);
    addUserToSystem(sys, user);
}

void start() {
    System s;
    loadSystemFromFile(s, "database.txt");
    std::cout << "Enter command:\n";
    char command[MAX_COMMAND_SIZE];
    std::cin.getline(command, MAX_COMMAND_SIZE);
    while (true) {
        if (strcmp(command, "login") == 0) {
            std::cout << "Enter email:\n";
            char buff1[MAX_SIZE];
            std::cin.getline(buff1, MAX_SIZE);
            std::cout << "Enter password:\n";
            char buff2[MAX_SIZE];
            std::cin.getline(buff2, MAX_SIZE);
            if (login(s, buff1, buff2)) {
                std::cout << "login successful\n";
            }
            else {
                std::cout << "login unsuccessful\n";
            }
        }
        else if (strcmp(command, "register") == 0) {
            std::cout << "Enter name:\n";
            char buff[MAX_SIZE];
            std::cin.getline(buff, MAX_SIZE);
            std::cout << "Enter email:\n";
            char buff1[MAX_SIZE];
            std::cin.getline(buff1, MAX_SIZE);
            std::cout << "Enter password:\n";
            char buff2[MAX_SIZE];
            std::cin.getline(buff2, MAX_SIZE);
            registerUser(s, buff, buff1, buff2);
            std::cout << "Registration successful\n";
        }
        else if (strcmp(command, "exit") == 0) {
            std::cout << "Exitting...\n";
            break;
        }
        else {
            std::cout << "Unknown command\n";
        }
        std::cout << "Enter command:\n";
        std::cin.getline(command, 32);
    }
    saveSystemToFile(s, "database.txt");
}

int main()
{
    start();
}
