#include "occupancy/occupancy_state_machine.h"

OccupancyStateMachine::OccupancyStateMachine()
{
    _state = OccupancyState::IDLE;
    _action = OccupancyAction::NONE;
}

void OccupancyStateMachine::update(const Event& event)
{

    _action = OccupancyAction::NONE;

    switch (_state)
    {
        case OccupancyState::IDLE:

            switch (event.type)
            {
                case EventType::ENTRY_LEFT_DETECTED:
                case EventType::ENTRY_CENTER_DETECTED:
                case EventType::ENTRY_RIGHT_DETECTED:

                    _state = OccupancyState::ENTRY_PENDING;
                    break;

                case EventType::EXIT_DETECTED:

                    _state = OccupancyState::EXIT_PENDING;
                    break;

                default:
                    break;
            }

            break;

        case OccupancyState::ENTRY_PENDING:

            if(event.type == EventType::EXIT_DETECTED)
            {
                _state = OccupancyState::IDLE;

                _action = OccupancyAction::PERSON_ENTERED;
            }

            break;

        case OccupancyState::EXIT_PENDING:

            if(event.type == EventType::ENTRY_LEFT_DETECTED ||
               event.type == EventType::ENTRY_CENTER_DETECTED ||
               event.type == EventType::ENTRY_RIGHT_DETECTED)
            {
                _state = OccupancyState::IDLE;

                _action = OccupancyAction::PERSON_EXITED;
            }

            break;
    }
}

OccupancyState OccupancyStateMachine::getState() const
{
    return _state;
}

OccupancyAction OccupancyStateMachine::getAction() const
{
    return _action;
}