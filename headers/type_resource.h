#pragma once
#include <string>
#include <iostream>


class Resource {
    private:
    int ResourceId;
    std::string NameOfResource;
    int PriceOfResource;
    int AmountOfResource;

    public:
    Resource();
    ~Resource();

    int GetResourceID();
    std::string GetResourceName();
    int GetReourcePrice();
    int GetAmountOfResource();
    bool FetchResoucreData(int ID, std::string Name, int Price, int Amount);
    bool SetPrice(int Price);
    void PrintResourceData();
    std::string GetResourceData();

};