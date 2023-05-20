#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileHandler {
    private:

    public:
    FileHandler();
    ~FileHandler();
    std::string GetInfoFromFile(std::string NameOfFile);
    std::string ModifyFile(std::string NameOfFile, std::string Input);
    std::vector<int> GetInfoCoins(std::string NameOfFile);
    bool CheckIfFileExists(std::string PathToFile);
};