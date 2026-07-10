#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "include/viewPass.h"

struct Account {

    std::string platformName;
    std::string accountName;
    std::string accountPassword;

};

std::vector<Account> platformInfo;

void viewPasswords(){

    Account acc;
    std::string decrypted;
    std::vector<std::string> passShift = loadShifts();

    loadPlatforms(acc);

    std::cout << "-----Your Passwords-----" << '\n';

    for(int i = 0; i < platformInfo.size(); i++){

        std::cout << "Platform: " << platformInfo[i].platformName << '\n';
        std::cout << "Account: " << platformInfo[i].accountName << '\n';
        decrypted = decryptPass(platformInfo[i].accountPassword, passShift[i]);
        std::cout << "Password: " << decrypted << '\n';
        std::cout << "------------------------" << '\n';
        

    }

}

void loadPlatforms(struct Account acc){

    std::ifstream infoRead("data/platInfo.txt");

    while(infoRead >> acc.platformName >> acc.accountName >> acc.accountPassword){

        platformInfo.push_back(acc);

    } 

    infoRead.close();

}

std::vector<std::string> loadShifts(){

    std::string shift;
    std::vector<std::string> passShifts;

    std::ifstream shiftRead("data/shift.txt");

    while(shiftRead >> shift){
        passShifts.push_back(shift);
    }

    shiftRead.close();

    return passShifts;

}

std::string decryptPass(std::string encrypted, std::string passShifts){

    int shift;
    char decrypt;
    std::string decryptedPass;

    for(int i = 0; i < passShifts.size(); i++){

        shift = passShifts[i] - '0';
        decrypt = encrypted[i] - shift;
        decryptedPass += decrypt;

    }

    return decryptedPass;

}