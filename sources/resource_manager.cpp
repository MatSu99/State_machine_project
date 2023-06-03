#include "../headers/resource_manager.h"
#define NAME_OF_FILE_WITH_COINS "coins.txt"

ResourceManager::ResourceManager() {
    StatusConnectionPayment = false;
}

ResourceManager::~ResourceManager() {

}

std::shared_ptr<Resource> ResourceManager::CreateResourceObject(int ID, std::string Name, int Price, int Amount) {
    std::shared_ptr<Resource> Resource_Ptr(new Resource());
    Resource_Ptr->FetchResoucreData(ID, Name, Price, Amount);
    return Resource_Ptr;
}

bool ResourceManager::PutResourceIntoVector(Resource Res) {
    VectorOfResources.push_back(Res);
    return true;
}

// ! WARNING ! Raw vector here
// Used only to access some methods but still 
void ResourceManager::PrintVectorOfResources() {
    int SizeOfVector = VectorOfResources.size();

    if(SizeOfVector == 0) {
        return;
    }
    
    Resource* ResourcePtr = nullptr;
    std::string to_print = "";

    for(int i=0; i< SizeOfVector; i++) {
        ResourcePtr = &(VectorOfResources[i]);
        to_print += "Resource :";
        to_print += std::to_string(i+1);
        to_print += "\n";
        to_print += ResourcePtr->GetResourceData();
        to_print += "\n";
    }

    ResourcePtr = nullptr;
    std::cout << to_print;

}

//TODO Change hard coded name of file to using input arg
bool ResourceManager::ProcessResources(std::string PathToFile) {
    std::string to_process;
    std::string proccessing_now;
    bool status = true;
    int phase = 0;
    int ID;
    std::string Name;
    int Price;
    int Amount;
    FileHandler FileHandlerInstance;
    to_process = FileHandlerInstance.GetInfoFromFile(PathToFile);
    std::string::iterator it=to_process.begin();
    while (it != to_process.end()){

        //std::cout << *it << std::endl;
        if(*it != '|' && phase == 0){
            proccessing_now += *it;
            it++;
            continue;
        }
        else if(*it == '|' && phase == 0) {
            try{
                ID = std::stoi(proccessing_now);
            }
            catch(const std::invalid_argument& err) {
                std::cerr << "Failed to convert ID";
                status = false;
                break;
            }
            phase = 1;
            it++;
            proccessing_now.clear();
        }

        if(*it != '|' && phase == 1){
            proccessing_now += *it;
            it++;
            continue;
        }
        else if(*it == '|' && phase == 1) {
            Name = proccessing_now;
            phase = 2;
            it++;
            proccessing_now.clear();
        }

        if(*it != '|' && phase == 2){
            proccessing_now += *it;
            it++;
            continue;
        }
        else if(*it == '|' && phase == 2) {
            try{
                Price = std::stoi(proccessing_now);
            }
            catch(const std::invalid_argument& err) {
                std::cerr << "Failed to convert Price";
                status = false;
                break;
            }
            phase = 3;
            it++;
            proccessing_now.clear();
            continue;

        }

        if(*it != '|' && phase == 3){
            proccessing_now += *it;
            it++;
            continue;
        }
        else if(*it == '|' && phase == 3) {
            try{
                Amount = std::stoi(proccessing_now);
            }
            catch(const std::invalid_argument& err) {
                std::cerr << "Failed to convert Amount";
                status = false;
                break;
            }
            phase = 4;
            it++;
            proccessing_now.clear();
        }

        if(phase == 4) {
            std::__shared_ptr<Resource> Resource_ptr = CreateResourceObject(ID, Name, Price, Amount);
            PutResourceIntoVector(*Resource_ptr);
            phase = 0;
            ID = 0;
            Name.clear();
            Price = 0;
            Amount = 0;          
        }
    }
    return status;
}

bool ResourceManager::checkConnectionPayment(bool Connection) {
    //TODO 
    return Connection;
}

bool ResourceManager::updateConnectionPayment(bool ConnectionStatus) {
    StatusConnectionPayment = ConnectionStatus;
    return true;
}

bool ResourceManager::GetCoinsStored(std::string PathToFile) {
    FileHandler FileHandlerInstance;
    std::vector<int> NumbersOfCoins;
    NumbersOfCoins = FileHandlerInstance.GetInfoCoins(PathToFile);

    for(int i = 0; i<8; ++i) {

        switch(i) {

            case 0:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], cent1));

            case 1:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], cent2));

            case 2:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], cent5));

            case 3:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], cent10));

            case 4:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], cent20));

            case 5:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], cent50));

            case 6:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], euro1));

            case 7:
            VectorOfCash.push_back(std::make_tuple(NumbersOfCoins[i], euro2));

            default:
            // ! ERROR !
            return false;
        }
    }
    return true;
}

std::vector<std::tuple<int,ResourceManager::Coins>> ResourceManager::GetCoinsStoredAsVector(std::string PathToFile) {
    FileHandler FileHandlerInstance;
    std::vector<int> NumbersOfCoins;
    NumbersOfCoins = FileHandlerInstance.GetInfoCoins(PathToFile);
    std::vector<std::tuple<int,Coins>> Vector_to_return;
    for(int i = 0; i<8; ++i) {

        switch(i) {

            case 0:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], cent1));

            case 1:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], cent2));

            case 2:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], cent5));

            case 3:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], cent10));

            case 4:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], cent20));

            case 5:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], cent50));

            case 6:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], euro1));

            case 7:
            Vector_to_return.push_back(std::make_tuple(NumbersOfCoins[i], euro2));

            default:
            // ! ERROR !
            return Vector_to_return;
        }
    }
    return Vector_to_return;
}

bool ResourceManager::UpdateCoinsStored(std::string PathToFile) {
    FileHandler FileHandlerInstance;
    FileHandlerInstance.ModifyFile(PathToFile, CurrentCoinsAsString());
    return true;
}

void ResourceManager::PrintVectorOfCash() {
    for(int i = 0; i < VectorOfCash.size(); ++i) {  
        std::cout   << i
                    << " Amount: "
                    << std::get<0>(VectorOfCash[i])
                    << " Value: "
                    << std::get<1>(VectorOfCash[i])
                    << "\n";
    }
    return;
}

bool ResourceManager::ProcessCashPayment(int PriceOfProduct, std::vector<std::tuple<int,Coins>> EnteredCoins) {
    // TODO
}

bool ResourceManager::ProcessCardPayment(int PriceOfProduct) {
    // TODO
}

// TODO
// Check with return is ok but it should also
// return some details about where there is
// an inconsistence
bool ResourceManager::CheckCompilanceOfCoins(std::string PathToFile) {
    std::vector<std::tuple<int,Coins>> CoinsFromMachine = GetCoinsStoredAsVector(PathToFile);
    if(CoinsFromMachine == VectorOfCash) {
        return true;
    }
    else {
        return false;
    }
}

std::string ResourceManager::CurrentCoinsAsString() {
    std::string result;

    for (const std::tuple<int,Coins>& i : VectorOfCash) {
        result += std::to_string(std::get<0>(i));
        result += '\n';
    }

    if(result.empty() == false) {
        result.pop_back();
    }
    else {
        return "ERROR";
    }

    return result;
}

int ResourceManager::GetAmountOfCoins(Coins Coin) {
    switch (Coin) {

        case cent1:
            return std::get<0>(VectorOfCash[0]);

        case cent2:
            return std::get<0>(VectorOfCash[1]);

        case cent5:
            return std::get<0>(VectorOfCash[2]);

        case cent10:
            return std::get<0>(VectorOfCash[3]);

        case cent20:
            return std::get<0>(VectorOfCash[4]);

        case cent50:
            return std::get<0>(VectorOfCash[5]);

        case euro1:
            return std::get<0>(VectorOfCash[6]);

        case euro2:
            return std::get<0>(VectorOfCash[7]);
        
        default:
            // ! ERROR !
            return -1;

    }
}

bool ResourceManager::UpdateAmountOfCoinsLocally(int Amount, Coins Coin) {
    std::tuple<int,Coins> Temp_Tuple = std::make_tuple(Amount, Coin);
    switch (Coin) {

        case cent1:
            VectorOfCash[0] = Temp_Tuple;
            return true;

        case cent2:
            VectorOfCash[1] = Temp_Tuple;
            return true;

        case cent5:
            VectorOfCash[2] = Temp_Tuple;
            return true;

        case cent10:
            VectorOfCash[3] = Temp_Tuple;
            return true;

        case cent20:
            VectorOfCash[4] = Temp_Tuple;
            return true;

        case cent50:
            VectorOfCash[5] = Temp_Tuple;
            return true;

        case euro1:
            VectorOfCash[6] = Temp_Tuple;
            return true;

        case euro2:
            VectorOfCash[7] = Temp_Tuple;
            return true;
        
        default:
            // ! ERROR !
            return false;

    }
}

Resource* ResourceManager::GetSpecificResourceRP(int Place) {
    Resource *PtrToReturn = nullptr;

    if(Place > VectorOfResources.size() || Place < 0) {
        // Invalid place, return null;
        return PtrToReturn;
    }

    PtrToReturn = &VectorOfResources[Place];
    return PtrToReturn;
}