#pragma once
#include "state_base.h"
#include "info_hub.h"
#include "resource_manager.h"


class InitializeState: StateBase {
    public:
    InfoHub& InfHub;
    ResourceManager& ResManager;
    InitializeState(InfoHub& Hub, ResourceManager& Manager);
    InitializeState() = delete;
    ~InitializeState();
    bool StartState() override final;
    int EndState() override final;
    void ManualEnterFilesPaths();
    bool AutomaticEnterFilesPaths();
    bool EstablishPaymentConnection();
    bool EvaluateCurrentStatus();


    private:
};