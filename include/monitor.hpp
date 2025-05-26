#pragma once
#include "wire.hpp"
#include <iostream>
#include <vector>

template <typename T>
class Monitor{
    private:
        std::shared_ptr<Wire<T>> targetWire;
        std::vector<T> observedValues;
    public:
        Monitor(std::shared_ptr<Wire<T>> wire)
                : targetWire(wire) {}
        void observe(){
            T value = targetWire->get();
            observedValues.push_back(value);
            std::cout << "[Monitor] Observed value: " << value << std::endl;
        }
        const std::vector<T>& getObservedValues() const {
            return observedValues;
        }
};