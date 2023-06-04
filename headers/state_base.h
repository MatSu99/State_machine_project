#pragma once
#include <string>

class StateBase {
    protected:
    std::string NameOfState;
    int StateId;


    public:
    StateBase();
    ~StateBase();
    virtual bool StartState() = 0;
    virtual bool EndState() = 0;
    virtual int GetStateId();
    virtual std::string GetNameOfState();
};