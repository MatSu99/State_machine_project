#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <memory>

#include "../headers/state_base.h"
#include "../headers/state_machine.h"
#include "../headers/resource_manager.h"
#include "../headers/file_handler.h"
#include "../headers/initialize_state.h"
#include "../headers/info_hub.h"

int main () {
    std::cout << "Hello World\n";
    StateMachine Test_1;
    std::cout << Test_1.getStateMachineId() << "\n";
    ResourceManager Test_3;

    std::shared_ptr<Resource> A = Test_3.CreateResourceObject(1,"ONE", 1, 1);
    Test_3.PutResourceIntoVector(*A);
    Test_3.PrintVectorOfResources();

    std::cout << "step 0" << std::endl;

    FileHandler Test_4;
    std::string STR = Test_4.GetInfoFromFile("/home/nox/Dev/cpp_projects/state_machine_proj/res/resources.txt");
    std::cout << STR << '\n';

    std::cout << "step 1" << std::endl;

    Test_3.ProcessResources("/home/nox/Dev/cpp_projects/state_machine_proj/res/resources.txt");
    Test_3.PrintVectorOfResources();

    std::cout << "step 2" << std::endl;

    Test_3.GetCoinsStored("/home/nox/Dev/cpp_projects/state_machine_proj/res/coins.txt");
    Test_3.PrintVectorOfCash();
    std::cout << "result> " << Test_3.CheckCompilanceOfCoins("/home/nox/Dev/cpp_projects/state_machine_proj/res/coins.txt") << "\n";

std::cout << "step 3" << std::endl;
    std::string test_string = "TEST";
    Test_4.ModifyFile("/home/nox/Dev/cpp_projects/state_machine_proj/res/test_file.txt", test_string);
    std::cout << Test_3.CurrentCoinsAsString();

    Test_3.UpdateAmountOfCoinsLocally(123, ResourceManager::euro1);
    Test_3.UpdateCoinsStored("/home/nox/Dev/cpp_projects/state_machine_proj/res/coins.txt");
    std::cout << "\nresult> " << Test_3.CheckCompilanceOfCoins("/home/nox/Dev/cpp_projects/state_machine_proj/res/coins.txt") << "\n";

    InfoHub TestInfoHub;
    InitializeState TestInitState(TestInfoHub, Test_3);

    return 0;
}