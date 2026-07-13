#include "events/event.h"

const char* eventToString(EventType type)
{
    switch (type)
    {
        case EventType::ENTRY_LEFT_DETECTED:
            return "ENTRY_LEFT_DETECTED";

        case EventType::ENTRY_CENTER_DETECTED:
            return "ENTRY_CENTER_DETECTED";

        case EventType::ENTRY_RIGHT_DETECTED:
            return "ENTRY_RIGHT_DETECTED";

        case EventType::EXIT_DETECTED:
            return "EXIT_DETECTED";

        default:
            return "NONE";
    }
}