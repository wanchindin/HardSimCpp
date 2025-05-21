#pragma once
#include <iostream>
#include "component.hpp"
#include "wire.hpp"

template<typename T>
class Mux : public Component{
    private:
        Wire<T>* input0;
        Wire<T>* input1;
        Wire<bool>* select; // false = input0 ; true = input1
        Wire<T>* output;
    public:
        Mux(Wire<T>* input0, Wire<T>* input1, Wire<bool>* select, Wire<T>* output)
            : input0(input0), input1(input1), select(select), output(output) {}
        
        void simulate() override {
            T result =  select->get() ? input1->get() : input0->get();
            output->set(result);
            std::cout<<"[Mux] output: "<<result<<std::endl;
        }

        std::string name() const override { return "MUX"; }
};