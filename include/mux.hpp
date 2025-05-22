#pragma once
#include <iostream>
#include <memory>
#include "component.hpp"
#include "wire.hpp"

template<typename T>
class Mux : public Component{
    private:
        std::shared_ptr<Wire<T>> input0;
        std::shared_ptr<Wire<T>> input1;
        std::shared_ptr<Wire<bool>> select; // false = input0 ; true = input1
        std::shared_ptr<Wire<T>> output;
    public:
        Mux(std::shared_ptr<Wire<T>> input0, std::shared_ptr<Wire<T>> input1, std::shared_ptr<Wire<bool>> select, std::shared_ptr<Wire<T>> output)
            : input0(input0), input1(input1), select(select), output(output) {}
        
        void simulate() override {
            T result =  select->get() ? input1->get() : input0->get();
            output->set(result);
            std::cout<<"[Mux] output: "<<result<<std::endl;
        }

        std::string name() const override { return "MUX"; }
};