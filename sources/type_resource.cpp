#include "../headers/type_resource.h"

Resource::Resource() {

    ResourceId = 0;
    NameOfResource = "";
    PriceOfResource = 0;
}

Resource::~Resource() {

}

int Resource::GetResourceID() {
    return ResourceId;
}

std::string Resource::GetResourceName() {
    return NameOfResource;
}

int Resource::GetReourcePrice() {
    return PriceOfResource;
}

int Resource::GetAmountOfResource(){
    return AmountOfResource;
}

bool Resource::FetchResoucreData( int ID, std::string Name, int Price, int Amount) {
    ResourceId = ID;
    NameOfResource = Name;
    PriceOfResource = Price;
    AmountOfResource = Amount;
    return true;
}

bool Resource::SetPrice(int Price) {
    PriceOfResource = Price;
    return true;
}

void Resource::PrintResourceData() {
    std::string to_print;
    to_print += "Resource ID: ";
    to_print += std::to_string(ResourceId);
    to_print += "\nResource name: ";
    to_print += NameOfResource;
    to_print += "\nPrice: ";
    to_print += std::to_string(PriceOfResource);
    to_print += "\nAmount: ";
    to_print += std::to_string(AmountOfResource);
    std::cout << to_print << "\n";
}

std::string Resource::GetResourceData() {
    std::string to_print;
    to_print += "Resource ID: ";
    to_print += std::to_string(ResourceId);
    to_print += "\nResource name: ";
    to_print += NameOfResource;
    to_print += "\nPrice: ";
    to_print += std::to_string(PriceOfResource);
    to_print += "\nAmount: ";
    to_print += std::to_string(AmountOfResource);
    return to_print;
}