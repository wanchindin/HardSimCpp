# HardSimCpp

## Introduction
`HardSimCpp` is a C++ simulation framework designed for modeling and verifying hardware components such as CPUs, circuits, and finite state machines (FSMs). The framework provides a modular and extensible architecture, making it easy to add new components and verification modules.

## Features
- **Abstract Base Class (`Component`)**:  
  A generic interface for all hardware components, ensuring consistency and extensibility. All components must implement the `simulate()` and `name()` methods.
  
- **Wire Simulation (`Wire`)**:  
  A template-based class for simulating signal wires, supporting value propagation and updates.

- **Register Simulation (`Register`)**:  
  A template-based class for simulating hardware registers, with support for storing current and next values, and simulating clock cycle updates.

- **Arithmetic Logic Unit (`ALU`)**:  
  A flexible and extensible ALU implementation that supports various operations such as addition, subtraction, bitwise operations, and comparisons. The ALU uses an `ALUOp` enum to specify operations and integrates seamlessly with `Wire` for input and output.

- **Extensibility**:  
  Designed to easily integrate new components like multiplexers, decoders, and custom hardware modules.

## Current Progress
- Implemented the **`Component`** base class to provide a unified interface for all hardware components.
- Developed **`Wire`** for simulating signal propagation between components.
- Added **`Register`** for simulating hardware registers with support for value updates and clock cycles.
- Completed **`ALU`** with support for operations such as ADD, SUB, AND, OR, XOR, comparisons (CMP_EQ, CMP_LT), and pass-through (PASS_A). Includes handling of unknown operations with a default behavior.
