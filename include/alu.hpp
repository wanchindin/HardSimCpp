#pragma once
#include "wire.hpp"
#include "component.hpp"
#include "control.hpp"
#include <iostream>

template <typename T>
class Alu : public Component{
    private:
        Wire<T>* lhs, *rhs;
        Wire<T>* output;
        ALUOp op;
    public:
        Alu(Wire<T>* lhs, Wire<T>* rhs, Wire<T>* output, ALUOp op)
            : lhs(lhs), rhs(rhs), output(output), op(op) {};
        
            void setOp(ALUOp newop){
                op = newop;
            }

            void simulate() override {
                T a = lhs->get();
                T b = rhs->get();
                T result = T();

                switch(op){
                    case ALUOp::ADD : result = a + b; break;
                    case ALUOp::SUB : result = a - b; break;
                    case ALUOp::AND : result = a & b; break;
                    case ALUOp::OR : result = a | b;  break;
                    case ALUOp::XOR : result = a ^ b; break;
                    case ALUOp::CMP_EQ : result = (a == b) ? 1 : 0; break;
                    case ALUOp::CMP_LT : result = (a < b) ? 1 : 0; break;
                    case ALUOp::PASS_A : result = a; break;
                    default : 
                        std::cout<< "Unknown operation, peforming NOP" <<std::endl; 
                        break;
                }
                output->set(result);
                std::cout<< "[ALU] result = "<<result<<std::endl;
            }
            std::string name() const override{
                return "ALU";
            }
};