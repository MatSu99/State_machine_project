#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <memory>

#include "type_resource.h"
#include "file_handler.h"

class ResourceManager {
    private:
    std::vector<Resource> VectorOfResources;
    bool StatusConnectionPayment;

    public:
    ResourceManager();
    ~ResourceManager();
        enum Coins {cent1 = 1,
                cent2 = 2,
                cent5 = 5,
                cent10 = 10,
                cent20 = 20,
                cent50 = 50,
                euro1 = 100, 
                euro2 = 200};

    bool PutResourceIntoVector(Resource Res);
    std::shared_ptr<Resource> CreateResourceObject(int ID, std::string Name, int Price, int Amount);
    void PrintVectorOfResources();
    bool ProcessResources(std::string PathToFile);

    bool checkConnectionPayment(bool Connection);
    bool updateConnectionPayment(bool ConnectionStatus);

    bool GetCoinsStored(std::string PathToFile);
    std::vector<std::tuple<int,Coins>> GetCoinsStoredAsVector(std::string PathToFile);
    bool UpdateCoinsStored(std::string PathToFile);
    bool CheckCompilanceOfCoins(std::string PathToFile);
    void PrintVectorOfCash();

    bool ProcessCashPayment(int PriceOfProduct, std::vector<std::tuple<int,Coins>> EnteredCoins);
    // TODO Card Payment
    bool ProcessCardPayment(int PriceOfProduct);

    std::string CurrentCoinsAsString();
    int GetAmountOfCoins(Coins Coin);
    bool UpdateAmountOfCoinsLocally(int Amount, Coins Coin);

    private:
    std::vector<std::tuple<int,Coins>> VectorOfCash;
};