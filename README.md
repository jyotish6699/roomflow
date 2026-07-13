# RoomFlow

RoomFlow is an embedded occupancy detection and room automation system designed to monitor room usage through doorway-based sensing.

The system detects people entering and leaving a room, maintains an accurate occupancy count, and automatically controls room lighting based on occupancy.

RoomFlow is built using Arduino, PlatformIO, and C++ with a modular, event-driven architecture focused on maintainability, reliability, and incremental development.

---

## Problem

Traditional room automation systems rely primarily on motion sensors.

This creates several limitations:

- Lights remain ON even when the room is empty.
- Lights turn OFF while someone is sitting still.
- The system cannot determine how many people are inside.
- Motion detection cannot distinguish entry from exit.

RoomFlow addresses these limitations by tracking doorway events and maintaining a live occupancy count.

---

## Features

- Entry Gate occupancy detection
- Exit Gate occupancy detection
- Servo-assisted doorway scanning
- Event-driven architecture
- Occupancy state machine
- Live occupancy counter
- Automatic light control
- Modular software architecture

---

## How It Works

```
              Person
                 │
                 ▼
      Entry / Exit Gate Sensors
                 │
                 ▼
        Event Generation Layer
                 │
                 ▼
     Occupancy State Machine
                 │
                 ▼
        Occupancy Engine
                 │
                 ▼
      Automatic Light Controller
                 │
                 ▼
             Relay Output
```

Example:

```
Person Enters
      ↓
Occupancy = 1
Light = ON

Another Person Enters
      ↓
Occupancy = 2
Light = ON

One Person Exits
      ↓
Occupancy = 1
Light = ON

Last Person Exits
      ↓
Occupancy = 0
Light = OFF
```

---

## System Architecture

```
src/
├── actuators/
│   └── servo_scanner
│
├── automation/
│   └── light_controller
│
├── config/
│
├── events/
│   ├── event
│   └── event_type
│
├── gateways/
│   ├── entry_gate
│   └── exit_gate
│
├── occupancy/
│   ├── occupancy_action
│   ├── occupancy_engine
│   ├── occupancy_state
│   └── occupancy_state_machine
│
├── sensors/
│   ├── entry_gate_sensor
│   └── exit_gate_sensor
│
└── main.cpp
```

---

## Software Architecture

```
Sensors
    │
    ▼
Gateways
    │
    ▼
Events
    │
    ▼
Occupancy State Machine
    │
    ▼
Occupancy Engine
    │
    ▼
Automation
```

---

## Technology Stack

- Arduino Uno R3
- PlatformIO
- C++
- Git
- GitHub

---

## Current Status

**Version**

```
v0.1.0
```

**Development Stage**

```
Minimum Viable Product (MVP)
```

**Completed Milestones**

- Hardware sensing layer
- Entry Gate subsystem
- Exit Gate subsystem
- Servo scanning subsystem
- Event engine
- Occupancy state machine
- Occupancy engine
- Live occupancy counter
- Automatic light controller
- End-to-end room automation workflow

---

## Project Principles

### Event-Driven

Hardware signals are converted into events before higher-level processing.

### Modular

Each subsystem has a single responsibility and communicates through well-defined interfaces.

### Layered Architecture

Each layer depends only on the layer directly below it, improving maintainability and scalability.

### Reliability First

The focus is on accurate occupancy detection and robust event processing.

### Incremental Development

Each feature is developed, tested, and integrated independently before moving to the next milestone.
