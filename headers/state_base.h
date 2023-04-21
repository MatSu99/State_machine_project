#pragma once
#include <string>

class StateBase {
    std::string NameOfState;
    unsigned int StateId;


    public:
    StateBase();
    ~StateBase();
    virtual bool StartState() = 0;
    virtual bool EndState() = 0;
    unsigned int GetStateId();
    std::string GetNameOfState();
};