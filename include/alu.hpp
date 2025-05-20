#pragma once
#include "wire.hpp"
#include "component.hpp"
#include <iostream>

enum class OpCode{
    ADD, SUB,
    AND, OR, XOR,
    CMP_EQ, CMP_LT,
    PASS_A,
    NOP
};

template <typename T>

class Alu : public Component{
    private:
        OpCode op;
        Wire<T> lhs, rhs;
        Wire<T> output;
    public:

};