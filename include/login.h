#ifndef LOGIN_H
#define LOGIN_H

#include <filesystem>

int authUser(std::filesystem::path filePath);

void signUpUser();

void loginUser();

std::string loadPassword();

std::string encryptMainPassword(std::string confirmedPassword);

std::string decryptMainPassword(std::string userPassword);

void saveMainShiftToFile(std::string shiftPatt);

std::string loadMainShift();

void clearInput();

#endif