#ifndef OCCUPANCY_STATE_H
#define OCCUPANCY_STATE_H

enum class OccupancyState
{
    IDLE,

    ENTRY_PENDING,

    EXIT_PENDING
};

const char* occupancyStateToString(OccupancyState state);

#endif