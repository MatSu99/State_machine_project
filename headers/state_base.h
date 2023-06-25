#pragma once
#include <string>
#include "info_hub.h"
#include "resource_manager.h"

class StateBase {
    protected:
    std::string NameOfState;
    int Id;



    public:

    enum StateID
    {
        INITIALIZE_STATE = 1,
        MAINTENANCE_STATE = 2,
        CHECK_RESOURCES_STATE = 3,
        START_STATE = 4,
        WAIT_FOR_INPUT_STATE = 5,
        WAIT_FOR_DECISION_PAYMENT_STATE = 6,
        CASH_STATE = 7,
        CARD_STATE = 8,
        ISSUE_PRODUCT = 9
    };

    StateBase();
    ~StateBase();
    virtual bool StartState() = 0;
    virtual int EndState() = 0;
    virtual int GetStateId();
    virtual std::string GetNameOfState();

};