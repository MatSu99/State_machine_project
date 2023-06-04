#include "../headers/state_base.h"

StateBase::StateBase() {

};

StateBase::~StateBase() {

};

 int StateBase::GetStateId() {
    return StateId;
}

std::string StateBase::GetNameOfState() {
    return NameOfState;
}