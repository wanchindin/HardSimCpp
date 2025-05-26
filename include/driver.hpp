#pragma once
#include "wire.hpp"
#include <vector>
#include <iostream>

template <typename T>
class Driver{
    private:
        std::shared_ptr<Wire<T>> targetWire;
        std::vector<T> testData;
        size_t currentCycle;
    public:
        Driver(std::shared_ptr<Wire<T>> wire, const std::vector<T>& data) 
                : targetWire(wire), testData(data), currentCycle(0){}
        void drive(){
            if(currentCycle < testData.size()){
                targetWire->set(testData[currentCycle]);
                std::cout<<" [Driver] Cycle" << currentCycle << ": Driving value" << testData[currentCycle] <<std::endl;
                ++currentCycle;
            }
        }
};