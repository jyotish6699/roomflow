#include "occupancy/occupancy_engine.h"

OccupancyEngine::OccupancyEngine()
{
    _occupancyCount = 0;
}

void OccupancyEngine::update(const Event& event)
{
    _stateMachine.update(event);

    OccupancyAction action = _stateMachine.getAction();

    switch(action)
    {
        case OccupancyAction::PERSON_ENTERED:

            _occupancyCount++;

            break;

        case OccupancyAction::PERSON_EXITED:

            if(_occupancyCount > 0)
            {
                _occupancyCount--;
            }

            break;

        default:
            break;
    }
}

int OccupancyEngine::getOccupancyCount() const
{
    return _occupancyCount;
}

OccupancyState OccupancyEngine::getState() const
{
    return _stateMachine.getState();
}