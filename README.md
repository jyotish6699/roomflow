# RoomFlow

RoomFlow is an embedded occupancy detection and counting system designed to monitor room usage through doorway-based sensing.

The system detects people entering and leaving a room, maintains an occupancy count, and provides a reliable foundation for room automation systems.

RoomFlow is being developed using Arduino, PlatformIO, and C++ with a strong focus on modular architecture, maintainability, and real-world reliability.

---

## Problem

Many room automation systems depend only on motion sensors.

This creates several problems:

* Lights may remain ON when nobody is present.
* Lights may turn OFF while a person is sitting still.
* The system cannot determine how many people are inside.
* Motion detection alone cannot distinguish entry from exit.

RoomFlow addresses these limitations by tracking room occupancy through doorway events.

---

## How It Works

RoomFlow monitors a doorway using multiple sensors.

When a person crosses the doorway, the system analyzes the sequence of sensor activations to determine whether the person entered or exited.

Based on these events, RoomFlow maintains an occupancy count.

Example:

```text
Person Enters
    ↓
Occupancy Count = 1

Another Person Enters
    ↓
Occupancy Count = 2

One Person Exits
    ↓
Occupancy Count = 1
```

---

## Current Objective

The current objective is to build a reliable occupancy counting engine capable of:

* Detecting room entry
* Detecting room exit
* Maintaining occupancy count
* Handling invalid sensor sequences
* Preventing incorrect counting
* Managing edge cases through state-machine logic

---

## Design Principles

### Event Driven

Sensor readings are converted into events which are processed by the occupancy engine.

### Modular

Hardware, occupancy logic, configuration, diagnostics, and event handling are separated into independent modules.

### Reliability First

The primary focus is reducing counting errors and handling real-world edge cases.

### Incremental Development

Features are added only after the occupancy engine is stable and verified.

---

## Technology Stack

* Arduino Uno R3
* PlatformIO
* C++
* Git
* GitHub

---

## Project Structure

```text
src/
├── config/
├── diagnostics/
├── events/
├── occupancy/
├── sensors/
└── main.cpp
```

---

## Current Status

Version: V0.1

Phase: Architecture Setup

Focus: Occupancy Detection and Counting Engine
