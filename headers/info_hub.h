#pragma once
#include <string>

class InfoHub {

    public:

    struct Data{
        std::string Name;
        std::string ID;
        std::string PathToResources;
        std::string PathToCoinsData;
        std::string PathToResourcesData;
        std::string PathToConfigFile;
        bool ErrorFlag;
        bool MaintenanceFlag;
        bool SkipInitFlag;
    }DataHub;

    InfoHub();
    ~InfoHub();
    void SetPathToResources(std::string Path);
    void SetPathToCoinsData(std::string Path);
    void SetPathToResourcesData(std::string Path);
    void SetPathToConfigFile(std::string Path);
    void SetErrorFlag(bool Flag);
    void SetMaintenanceFlag(bool Flag);
    void SetSkipInitFlag(bool Flag);
    void SetName(std::string NameIn);
    void SetID(std::string Id);

    std::string GetPathToResources();
    std::string GetPathToCoinsData();
    std::string GetPathToResourcesData();
    std::string GetPathToConfigFile();
    bool GetErrorFlag();
    bool GetMaintenanceFlag();
    bool GetSkipInitFlag();
    std::string GetName();
    std::string GetID();

    void InitializeDataHub();

};
