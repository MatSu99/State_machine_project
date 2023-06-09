#pragma once
#include "state_base.h"

class InitializeState: StateBase {
    public:

    bool StartState() override final;
    bool EndState() override final;
    InitializeState();
    InitializeState(int ID);
    ~InitializeState();

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

    private:
};