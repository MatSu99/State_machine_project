#include "../headers/info_hub.h"

InfoHub::InfoHub()
{

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