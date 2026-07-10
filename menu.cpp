#include <iostream>
#include "include/menu.h"
#include "include/login.h"
#include "include/storePass.h"
#include "include/viewPass.h"
#include "include/passGenerator.h"

void showMenu(){

    std::string menuOptionCatcher;
    char menuOption;
    int passLength = 0;
    bool isRunning = true;

    do{

        std::cout << '\n';
        std::cout << "   _____        __     _____                             _   " << '\n';
        std::cout << "  / ____|      / _|   |  __ \\                /\\         | |  " << '\n';
        std::cout << " | (___   __ _| |_ ___| |__) |_ _ ___ ___   /  \\   _ __ | |_ " << '\n';
        std::cout << "  \\___ \\ / _` |  _/ _ \\  ___/ _` / __/ __| / /\\ \\ | '_ \\| __|" << '\n';
        std::cout << "  ____) | (_| | ||  __/ |  | (_| \\__ \\__ \\/ ____ \\| | | | |_ " << '\n';
        std::cout << " |_____/ \\__,_|_| \\___|_|   \\__,_|___/___/_/    \\_\\_| |_|\\__|" << '\n';
        std::cout << '\n';
        std::cout << "A simple password manager." << '\n';
        std::cout << "[A] Store Passwords [B] View Passwords [C] Generate Passwords [D] Exit" << '\n';
        std::getline(std::cin, menuOptionCatcher);
        //std::cin >> menuOption;

        menuOption = menuOptionCatcher[0];

        switch(menuOption){
            case 'A':
            case 'a':
                storePassword();
                break;
            case 'B':
            case 'b':
                viewPasswords();
                break;
            case 'C':
            case 'c':
                std::cout << "Enter the length of the password: ";
                std::cin >> passLength;

                generatePassword(passLength);
                clearInput();
                break;
            case 'D':
            case 'd':
                isRunning = false;
                break;
            default:
                std::cout << "Unknown Command" << '\n';
        }

    } while(isRunning != false);

}