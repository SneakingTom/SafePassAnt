#include <iostream>
#include <ctime>
#include "include/passGenerator.h"

void generatePassword(int passLength){

    srand(time(NULL));
    char lowercaseLetter = 'a';
    char uppercaseLetter = 'A';
    char randLetter;
    int num = 0;
    int limit = 0;

    while(limit != passLength){
        int numOrLetter = (rand() % 3) + 1;
        switch(numOrLetter){
            case 1:
                randLetter = lowercaseLetter + (rand() % 25) + 1;
                std::cout << randLetter;
                break;
            case 2:
                randLetter = uppercaseLetter + (rand() % 25) + 1;
                std::cout << randLetter;
                break;
            case 3:
                int numRand = (rand() % 10);
                int randNum = num + numRand;
                std::cout << randNum;
                break;
        }  
        limit++;
    }

}
