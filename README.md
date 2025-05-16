# HardSimCpp

## Introduction
`HardSimCpp` is a C++ simulation framework designed for modeling and verifying hardware components such as CPUs, circuits, and finite state machines (FSMs). The framework provides a modular and extensible architecture, making it easy to add new components and verification modules.

## Features
- **Abstract Base Class (`Component`)**:  
  A generic interface for all hardware components, ensuring consistency and extensibility.
- **Register Simulation (`Register`)**:  
  A template-based class for simulating hardware registers with support for value updates and clock cycles.
- **Extensibility**:  
  Designed to easily integrate new components like ALUs, multiplexers, and wires.

## Project Structure
📁 HardSimCpp/
├── CMakeLists.txt
├── main.cpp
├── include/
│   ├── component.h
│   ├── register.h
│   ├── alu.h
│   ├── mux.h
│   ├── wire.h
│   ├── driver.h
│   ├── monitor.h
│   ├── scoreboard.h
│   ├── env.h
│   ├── test.h
│   ├── netlist_parser.h
│   ├── graph.h
│   └── timing_analyzer.h
├── src/
│   ├── register.cpp
│   ├── alu.cpp
│   ├── mux.cpp
│   ├── wire.cpp
│   ├── driver.cpp
│   ├── monitor.cpp
│   ├── scoreboard.cpp
│   ├── env.cpp
│   ├── test.cpp
│   ├── netlist_parser.cpp
│   ├── graph.cpp
│   └── timing_analyzer.cpp
├── test/
│   ├── sample_test.json
│   └── waveform_output.log