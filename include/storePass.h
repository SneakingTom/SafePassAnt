#ifndef STOREPASS_H
#define STOREPASS_H

void storePassword();

std::string encryptPassword(std::string accPassword);

void saveInfoToFile(std::string platform, std::string account, std::string encrypted);

void saveShiftToFile(std::string shiftPattern);

#endif