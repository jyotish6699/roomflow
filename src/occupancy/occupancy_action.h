#ifndef OCCUPANCY_ACTION_H
#define OCCUPANCY_ACTION_H

enum class OccupancyAction
{
    NONE,

    PERSON_ENTERED,

    PERSON_EXITED
};

const char* occupancyActionToString(
    OccupancyAction action
);

#endif