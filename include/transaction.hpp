#pragma once 
#include "control.hpp"

struct ALUTransaction {
    ALUOp op;
    int operand1;
    int operand2;
    int expected;
};