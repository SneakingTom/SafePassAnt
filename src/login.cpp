#include <iostream>
#include <fstream>
#include <limits>
#include <filesystem>
#include <string>
#include <ctime>
#include "include/login.h"

int authUser(std::filesystem::path filePath){

    if(!std::filesystem::exists(filePath)){

        signUpUser();

    } else {

        loginUser();
    }

    return 0;
}

void signUpUser(){

    std::string inputPassword;
    std::string confirmedPassword;
    std::string encryptedPassword;
    bool confirmed = false;

    std::cout << "Enter new password: ";
    std::getline(std::cin, inputPassword);

    do{
        std::cout << "Confirm password: ";
        std::getline(std::cin, confirmedPassword);

        if(inputPassword == confirmedPassword){

            encryptedPassword = encryptMainPassword(confirmedPassword);

            std::ofstream saveUserPassword("data/mainPass.txt");
            saveUserPassword << encryptedPassword;
            saveUserPassword.close();

            confirmed = true;

        } else {

            std::cout << "Password not the same as first!" << '\n';

        }

    } while(confirmed != true);

}

void loginUser(){

    std::string userPassword;
    std::string userPassInput;
    std::string decryptedPassword;
    bool correct = false;

    userPassword = loadPassword();
    decryptedPassword = decryptMainPassword(userPassword);

    do{

        std::cout << "Enter password: ";
        std::getline(std::cin, userPassInput);

        if(userPassInput == decryptedPassword){

            std::cout << "Successful login!" << '\n';
            correct = true;

        } else {

            //clearInput();
            std::cout << "Incorrect Password, Try Again!" << '\n';

        }

    } while(correct != true);

}

std::string loadPassword(){

    std::string userPassword;

    std::ifstream loadUserPassword("data/mainPass.txt");

    std::getline(loadUserPassword, userPassword);

    loadUserPassword.close();

    return userPassword;
}

std::string encryptMainPassword(std::string confirmedPassword){

    srand(time(NULL));
    std::string encrypted;
    std::string shiftPatt;
    char passElement;
    int shift;

    for(int i = 0; i < confirmedPassword.size(); i++){

        shift = (rand() % 9) + 1;
        passElement = confirmedPassword[i] + shift;
        encrypted += passElement;
        shiftPatt += std::to_string(shift);

    }

    saveMainShiftToFile(shiftPatt);

    return encrypted;

}

std::string decryptMainPassword(std::string userPassword){

    std::string shiftPatt = loadMainShift();
    std::string decrypted;
    char decryptElement;
    int shift;

    for(int i = 0; i < shiftPatt.size(); i++){

        shift = shiftPatt[i] - '0';
        decryptElement = userPassword[i] - shift;
        decrypted += decryptElement;

    }

    return decrypted;

}

void saveMainShiftToFile(std::string shiftPatt){

    std::ofstream mainShiftWrite("data/mainShift.txt");

    mainShiftWrite << shiftPatt;

    mainShiftWrite.close();

}

std::string loadMainShift(){

    std::string shiftPatt;

        std::ifstream mainShiftRead("data/mainShift.txt");

        mainShiftRead >> shiftPatt;

        mainShiftRead.close();

    return shiftPatt;

}

void clearInput(){

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}