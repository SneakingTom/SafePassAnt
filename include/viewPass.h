#ifndef VIEWPASS_H
#define VIEWPASS_H

#include <vector>

void viewPasswords();

void loadPlatforms(struct Account acc);

std::vector<std::string> loadShifts();

std::string decryptPass(std::string encrypted, std::string passShifts);

#endif