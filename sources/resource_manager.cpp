#include "../headers/resource_manager.h"

ResourceManager::ResourceManager() {
    StatusConnectionPayment = false;
}

ResourceManager::~ResourceManager() {

}

std::unique_ptr<Resource> ResourceManager::CreateResourceObject(int ID, std::string Name, int Price, int Amount) {
    std::unique_ptr<Resource> Resource_Ptr(new Resource());
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

    std::cout << to_print;


}