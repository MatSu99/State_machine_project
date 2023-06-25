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