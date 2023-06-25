#pragma once
#include <string>

class InfoHub {

    public:

    struct Data{
        std::string PathToResources;
        std::string PathToCoinsData;
        std::string PathToResourcesData;
        std::string PathToConfigFile;
    }DataHub;

    InfoHub();
    ~InfoHub();
    void SetPathToResources(std::string Path);
    void SetPathToCoinsData(std::string Path);
    void SetPathToResourcesData(std::string Path);
    void SetPathToConfigFile(std::string Path);
    std::string GetPathToResources();
    std::string GetPathToCoinsData();
    std::string GetPathToResourcesData();
    std::string GetPathToConfigFile();
};
