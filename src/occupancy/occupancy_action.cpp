#include "occupancy/occupancy_action.h"

const char* occupancyActionToString(
    OccupancyAction action)
{
    switch(action)
    {
        case OccupancyAction::PERSON_ENTERED:
            return "PERSON_ENTERED";

        case OccupancyAction::PERSON_EXITED:
            return "PERSON_EXITED";

        default:
            return "NONE";
    }
}