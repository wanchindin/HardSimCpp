#pragma once
#include <iostream>

// Abstract base class Component
// Represents a generic hardware component in the simulation framework.
// All derived classes must implement the `simulate()` and `name()` methods.

class Component{
    public:
        virtual void simulate() = 0; // Pure virtual function
        virtual std::string name() const = 0;
        virtual ~Component() = default; 
};