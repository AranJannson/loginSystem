#include <iostream>
#include <fstream>
#include <string>
#include "Register.h"


void registerUser(std::string username, std::string password) {
    std::cout << "Welcome To The Registry System!" << std::endl;

    std::cout << "Enter username: " << std::endl;
    std::cin >> username;

    std::ifstream file("users.txt");

    if (!file.is_open()) {

        std::string filename = "users.txt";

        std::ofstream newFile(filename);
        if (!newFile.is_open()) {
            std::cerr << "Error creating the file." << std::endl;
            return;
        }
        newFile.close();
        file.open(filename);
    }

    std::string fileLine;
    while (getline(file, fileLine)) {
        if (fileLine == username) {
            std::cout << "User already exists!" << std::endl;
            return;
        }
    }
    file.close();

    std::ofstream newFile("users.txt", std::ios::app);
    if (!newFile.is_open()) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return;
    }

    newFile << username << std::endl;
    newFile.close();

    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream filePasswords("passwords.txt");

    if (!filePasswords.is_open()) {
        std::string filename = "passwords.txt";

        std::ofstream newFilePasswords(filename);
        if (!newFilePasswords.is_open()) {
            std::cerr << "Error creating the file." << std::endl;
            return;
        }
        newFilePasswords.close();
        filePasswords.open(filename);
    }

    std::ofstream newFilePasswords("passwords.txt", std::ios::app);

    if (!newFilePasswords.is_open()) {
        std::cerr << "Error opening the file for appending." << std::endl;
        return;
    }


    newFilePasswords << username << "|" << password << std::endl;
    newFilePasswords.close();

    std::cout << "User registered!" << std::endl;


}


int main() {
    std::string username;
    std::string password;

    registerUser(username, password);

    return 0;
}

