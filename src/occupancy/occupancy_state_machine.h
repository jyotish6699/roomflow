#ifndef OCCUPANCY_STATE_MACHINE_H
#define OCCUPANCY_STATE_MACHINE_H

#include "events/event.h"
#include "occupancy/occupancy_state.h"
#include "occupancy/occupancy_action.h"

class OccupancyStateMachine
{
public:
    OccupancyStateMachine();

    void update(const Event& event);

    OccupancyState getState() const;

    OccupancyAction getAction() const;

private:
    OccupancyState _state;

    OccupancyAction _action;
};

#endif