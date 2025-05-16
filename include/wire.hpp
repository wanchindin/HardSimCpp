#pragma once
#include <iostream>
#include "component.hpp"

template <typename T>
class Wire : public Component{
    private:
        T value;
    public:
        Wire() : value() {}

        void simulate() override{
            std::cout<<"[Wire] value = "<<value<<std::endl;
        }
        std::string name() const override { return "Wire"; }

        void set(T v){ value = v; }
        T get() const { return value; }
};