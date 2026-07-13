#include "occupancy/occupancy_state.h"

const char* occupancyStateToString(OccupancyState state)
{
    switch (state)
    {
        case OccupancyState::IDLE:
            return "IDLE";

        case OccupancyState::ENTRY_PENDING:
            return "ENTRY_PENDING";

        case OccupancyState::EXIT_PENDING:
            return "EXIT_PENDING";

        default:
            return "UNKNOWN";
    }
}