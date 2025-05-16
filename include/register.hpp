#pragma once
#include "component.hpp"
#include "wire.hpp"
#include <iostream>

// Template class Register simulates a hardware register.
// It uses Wire<T> to store the current value and the next value.

template <typename T>
class Register : public Component{
    private:
        Wire<T> value;
        Wire<T> nextValue;
    public:
        Register() : value(), nextValue() {}
        void setNext(T v){ nextValue.set(v); }
        T get() const { return value.get(); }
        void simulate() override { 
            value.set(nextValue.get()); 
            std::cout<<"[Register] value = " << value.get() <<std::endl;
        }
        std::string name() const override {
            return "Register";
        }
};