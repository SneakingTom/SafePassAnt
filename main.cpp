#include <iostream>
#include <filesystem>
#include "include/login.h"
#include "include/menu.h"

int main(){

    const std::filesystem::path filePath = "data/mainPass.txt";
    
    authUser(filePath);

    showMenu();

    return 0;
}