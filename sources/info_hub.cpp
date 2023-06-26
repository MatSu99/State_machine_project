#include "../headers/info_hub.h"

InfoHub::InfoHub()
{
    InitializeDataHub();
}

InfoHub::~InfoHub()
{

}

void InfoHub::SetPathToResources(std::string Path)
{
    DataHub.PathToResources = Path;
}

void InfoHub::SetPathToCoinsData(std::string Path)
{
    DataHub.PathToCoinsData = Path;
}

void InfoHub::SetPathToResourcesData(std::string Path)
{
    DataHub.PathToResourcesData = Path;
}

void InfoHub::SetPathToConfigFile(std::string Path)
{
    DataHub.PathToConfigFile = Path;
}

void InfoHub::SetErrorFlag(bool Flag)
{
    DataHub.ErrorFlag = Flag;
}

void InfoHub::SetMaintenanceFlag(bool Flag)
{
    DataHub.MaintenanceFlag = Flag;
}

void InfoHub::SetSkipInitFlag(bool Flag)
{
    DataHub.SkipInitFlag = Flag;
}

void InfoHub::SetName(std::string NameIn)
{
    DataHub.Name = NameIn;
}

void InfoHub::SetID(std::string Id)
{
    DataHub.ID = Id;
}

std::string InfoHub::GetPathToResources()
{
    return DataHub.PathToResources;
}

std::string InfoHub::GetPathToCoinsData()
{
    return DataHub.PathToCoinsData; 
}

std::string InfoHub::GetPathToResourcesData()
{
    return DataHub.PathToResourcesData;  
}

std::string InfoHub::GetPathToConfigFile()
{
    return DataHub.PathToConfigFile;
}

bool InfoHub::GetErrorFlag()
{
    return DataHub.ErrorFlag;
}

bool InfoHub::GetMaintenanceFlag()
{
    return DataHub.MaintenanceFlag;
}

bool InfoHub::GetSkipInitFlag()
{
    return DataHub.SkipInitFlag;
}

std::string InfoHub::GetName()
{
    return DataHub.Name;
}

std::string InfoHub::GetID()
{
    return DataHub.ID;
}

void InfoHub::InitializeDataHub()
{
     SetPathToResources("");
     SetPathToCoinsData("");
     SetPathToResourcesData("");
     SetPathToConfigFile("");
     SetErrorFlag(0);
     SetMaintenanceFlag(0);
     SetSkipInitFlag(0);
     SetName("");
     SetID("");
}