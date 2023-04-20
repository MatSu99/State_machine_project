#include <iostream>

#include "../headers/state_base.h"
#include "../headers/state_machine.h"

int main () {
    std::cout << "Hello World\n";
    StateMachine Test_1;
    std::cout << Test_1.getStateMachineId() << "\n";
    return 0;
}