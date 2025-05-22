#pragma once
#include "component.hpp"
#include "wire.hpp"
#include <iostream>
#include <memory>

// Template class Register simulates a hardware register.
// It uses Wire<T> to store the current value and the next value.

template <typename T>
class Register : public Component {
private:
    std::shared_ptr<Wire<T>> value;
    std::shared_ptr<Wire<T>> nextValue;

public:
    Register(std::shared_ptr<Wire<T>> value, std::shared_ptr<Wire<T>> nextValue)
        : value(value), nextValue(nextValue) {}

    void setNext(T v) { nextValue->set(v); }
    T get() const { return value->get(); }
    void simulate() override {
        value->set(nextValue->get());
        std::cout << "[Register] value = " << value->get() << std::endl;
    }
    std::string name() const override { return "Register"; }
};