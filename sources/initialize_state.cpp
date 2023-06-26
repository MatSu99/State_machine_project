#include "../headers/initialize_state.h"

InitializeState::InitializeState(InfoHub& Hub, ResourceManager& Manager)
                                : InfHub(Hub), ResManager(Manager)
{
    Id = INITIALIZE_STATE;
}

InitializeState::~InitializeState() {

}


bool InitializeState::StartState() {

}

int InitializeState::EndState() {
    
}

void InitializeState::ManualEnterFilesPaths() {
    //TODO Add manual
}

bool InitializeState::AutomaticEnterFilesPaths() {

    return false;
}

bool InitializeState::EstablishPaymentConnection() {

    return false;
}

bool InitializeState::EvaluateCurrentStatus() {

    return false;
}