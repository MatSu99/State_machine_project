#pragma once
#include "state_base.h"

class InitializeState: StateBase {
    public:

    bool StartState() override final;
    bool EndState() override final;
    InitializeState();
    InitializeState(int ID);
    ~InitializeState();

    private:
};