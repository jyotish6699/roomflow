#ifndef EVENT_H
#define EVENT_H

#include "events/event_type.h"

struct Event
{
    EventType type = EventType::NONE;
};

const char* eventToString(EventType type);

#endif