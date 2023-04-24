#include "../headers/resource_manager.h"

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
bool ResourceManager::ProcessResources(std::string ResourcesInput) {
    std::string to_process;
    std::string proccessing_now;
    bool status = true;
    int phase = 0;
    int ID;
    std::string Name;
    int Price;
    int Amount;
    FileHandler FileHandlerInstance;
    to_process = FileHandlerInstance.GetInfoFromFile("resources.txt");
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
            // Resource_ptr->PrintResourceData();

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

bool ResourceManager::GetCoinsStored(std::string ResourceInput) {
    //TODO Implementation similar to ProcessResources
    return true;
}

bool ResourceManager::UpdateCoinsStored(std::string ResourceInput) {
    //TODO This will modify coins.txt
    return true;
}