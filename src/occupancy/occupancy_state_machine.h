#ifndef OCCUPANCY_STATE_MACHINE_H
#define OCCUPANCY_STATE_MACHINE_H

#include "events/event.h"
#include "occupancy/occupancy_state.h"

class OccupancyStateMachine
{
public:
    OccupancyStateMachine();

    void update(const Event& event);

    OccupancyState getState() const;

private:
    OccupancyState _state;
};

#endif