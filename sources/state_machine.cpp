#include "../headers/state_machine.h"

StateMachine::StateMachine() {
    StateMachineId = 0;

}

StateMachine::~StateMachine() {

}

int StateMachine::getStateMachineId() {
    return StateMachineId;
}