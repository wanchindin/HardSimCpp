#pragma once
#include "component.hpp"
#include <iostream>

// Template class Register simulates a hardware register.
// It stores a current value (`value`) and a next value (`nextValue`),
// which gets updated during the `simulate()` function.

template <typename T>
class Register : public Component{
    private:
        T value;
        T nextValue;
    public:
        Register() : value(), nextValue() {}
        void setNext(T v){ nextValue = v; }
        T get() const { return value; }
        void simulate() override { 
            value = nextValue; 
            std::cout<<"[Register] value = " << value <<std::endl;
        }
        std::string name() const override {
            return "Register";
        }
};