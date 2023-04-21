#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <memory>

#include "type_resource.h"

class ResourceManager {
    private:
    std::vector<Resource> VectorOfResources;
    bool StatusConnectionPayment;
    enum Coins {cent1 = 1,
                cent2 = 2,
                cent5 = 5,
                cent10 = 10,
                cent20 = 20,
                cent50 = 50,
                euro1 = 100, 
                euro2 = 200};
    std::vector<std::tuple<int,Coins>> VectorOfCash;

    public:
    ResourceManager();
    ~ResourceManager();
    bool PutResourceIntoVector(Resource Res);
    std::unique_ptr<Resource> CreateResourceObject(int ID, std::string Name, int Price, int Amount);
    void PrintVectorOfResources();
};