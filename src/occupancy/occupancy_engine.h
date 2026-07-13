#ifndef OCCUPANCY_ENGINE_H
#define OCCUPANCY_ENGINE_H

#include "events/event.h"
#include "occupancy/occupancy_state_machine.h"
#include "occupancy/occupancy_state.h"

class OccupancyEngine
{
public:
    OccupancyEngine();

    void update(const Event& event);

    int getOccupancyCount() const;

    OccupancyState getState() const;

private:
    OccupancyStateMachine _stateMachine;

    int _occupancyCount;
};

#endif