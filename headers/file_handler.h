#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
    private:

    public:
    FileHandler();
    ~FileHandler();
    std::string GetInfoFromFile(std::string NameOfFile);
    std::string ModifyFile(std::string NameOfFile);
};