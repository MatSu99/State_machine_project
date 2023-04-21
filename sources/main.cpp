#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <memory>

#include "../headers/state_base.h"
#include "../headers/state_machine.h"
#include "../headers/resource_manager.h"

int main () {
    std::cout << "Hello World\n";
    StateMachine Test_1;
    std::cout << Test_1.getStateMachineId() << "\n";
    ResourceManager Test_3;

    std::shared_ptr<Resource> A = Test_3.CreateResourceObject(1,"ONE", 1, 1);
    Test_3.PutResourceIntoVector(*A);
    Test_3.PrintVectorOfResources();

    return 0;
}