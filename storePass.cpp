#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "include/storePass.h"

void storePassword(){

    std::string platformName;
    std::string accountName;
    std::string accountPassword;
    std::string encryptPass;

    std::cout << "Enter Platform: ";
    std::getline(std::cin, platformName);

    std::cout << "Enter Account Name: ";
    std::getline(std::cin, accountName);

    std::cout << "Enter Password: ";
    std::getline(std::cin, accountPassword);

    encryptPass = encryptPassword(accountPassword);

    //std::cout << encryptPass << '\n';

    saveInfoToFile(platformName, accountName, encryptPass);

}

std::string encryptPassword(std::string accPassword){

    srand(time(NULL));
    std::string encryptPass;
    std::string shiftPatt;
    char passLetter;
    int shift;

    for(int i = 0; i < accPassword.size(); i++){

        shift = (rand() % 9) + 1;
        passLetter = accPassword[i] + shift;
        encryptPass += passLetter;
        shiftPatt += std::to_string(shift);

    }

    saveShiftToFile(shiftPatt);

    return encryptPass;
}

void saveInfoToFile(std::string platform, std::string account, std::string encrypted){

    std::ofstream infoWrite("data/platInfo.txt", std::ios::app);

    infoWrite << platform << " " << account << " " << encrypted << '\n';

    infoWrite.close();

}

void saveShiftToFile(std::string shiftPattern){

    std::ofstream shiftWrite("data/shift.txt", std::ios::app);

    shiftWrite << shiftPattern << '\n';

    shiftWrite.close();

}