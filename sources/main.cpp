#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <memory>

#include "../headers/state_base.h"
#include "../headers/state_machine.h"
#include "../headers/resource_manager.h"
#include "../headers/file_handler.h"

int main () {
    std::cout << "Hello World\n";
    StateMachine Test_1;
    std::cout << Test_1.getStateMachineId() << "\n";
    ResourceManager Test_3;

    std::shared_ptr<Resource> A = Test_3.CreateResourceObject(1,"ONE", 1, 1);
    Test_3.PutResourceIntoVector(*A);
    Test_3.PrintVectorOfResources();

    FileHandler Test_4;
    std::string STR = Test_4.GetInfoFromFile("resources.txt");
    std::cout << STR << '\n';

    Test_3.ProcessResources("X");
    Test_3.PrintVectorOfResources();

    Test_3.GetCoinsStored("coins.txt");
    Test_3.PrintVectorOfCash();

    std::string test_string = "TEST";
    Test_4.ModifyFile("test_file.txt", test_string);
    std::cout << Test_3.CurrentCoinsAsString();

    Test_3.UpdateAmountOfCoinsLocally(123, ResourceManager::euro1);
    Test_3.UpdateCoinsStored("coins.txt");

    return 0;
}