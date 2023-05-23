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
    std::string GetInfoFromFile(std::string Path);
    std::string ModifyFile(std::string Path, std::string Input);
    std::vector<int> GetInfoCoins(std::string Path);
    bool CheckIfFileExists(std::string PathToFile);
};