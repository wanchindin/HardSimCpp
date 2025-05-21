#include <iostream>
#include <memory>
#include "../include/wire.hpp"
#include "../include/register.hpp"
#include "../include/alu.hpp"
#include "../include/mux.hpp"

void test_wire(){
    std::cout<<"===================Wire====================="<<std::endl;
    Wire<int> *wire = new Wire<int>();
    std::cout<<"Initial value:"<<wire->get()<<std::endl;

    wire->set(1);
    wire->simulate();
    std::cout<<wire->name()<<std::endl;
    delete wire;
}

void test_register(){
    std::cout<<"===================Register====================="<<std::endl;
    Wire<int>* value = new Wire<int>;
    Wire<int>* nextValue = new Wire<int>;
    Register<int> *reg = new Register<int>(value, nextValue);
    std::cout<<"Initial value:"<<reg->get()<<std::endl;
    
    reg->setNext(1);
    reg->simulate();    //1
    std::cout<<reg->name()<<std::endl;
    
    delete value;
    delete nextValue;
    delete reg;
}

void test_alu(){
    std::cout<<"===================ALU====================="<<std::endl;
    // 建立 Wire 物件
    Wire<int> lhs;
    Wire<int> rhs;
    Wire<int> output;

    // 設定輸入值
    lhs.set(10);
    rhs.set(5);

    // 測試 ADD 操作
    Alu<int> alu(&lhs, &rhs, &output, ALUOp::ADD);
    alu.simulate();
    std::cout << "ADD Result: " << output.get() << " (Expected: 15)" << std::endl;

    // 測試 SUB 操作
    alu.setOp(ALUOp::SUB);
    alu.simulate();
    std::cout << "SUB Result: " << output.get() << " (Expected: 5)" << std::endl;

    // 測試 AND 操作
    alu.setOp(ALUOp::AND);
    alu.simulate();
    std::cout << "AND Result: " << output.get() << " (Expected: " << (10 & 5) << ")" << std::endl;

    // 測試 OR 操作
    alu.setOp(ALUOp::OR);
    alu.simulate();
    std::cout << "OR Result: " << output.get() << " (Expected: " << (10 | 5) << ")" << std::endl;

    // 測試 XOR 操作
    alu.setOp(ALUOp::XOR);
    alu.simulate();
    std::cout << "XOR Result: " << output.get() << " (Expected: " << (0xA ^ 5) << ")" << std::endl;

    // 測試 CMP_EQ 操作
    alu.setOp(ALUOp::CMP_EQ);
    alu.simulate();
    std::cout << "CMP_EQ Result: " << output.get() << " (Expected: 0)" << std::endl;

    // 測試 CMP_LT 操作
    alu.setOp(ALUOp::CMP_LT);
    alu.simulate();
    std::cout << "CMP_LT Result: " << output.get() << " (Expected: 0)" << std::endl;

    // 測試 PASS_A 操作
    alu.setOp(ALUOp::PASS_A);
    alu.simulate();
    std::cout << "PASS_A Result: " << output.get() << " (Expected: 10)" << std::endl;

    // 測試未知操作碼
    alu.setOp(static_cast<ALUOp>(999)); // 非法操作碼
    alu.simulate();
    std::cout << "Unknown Operation Result: " << output.get() << " (Expected: 0 or default behavior)" << std::endl;
}

void test_mux(){
    std::cout<<"===================MUX====================="<<std::endl;
    Wire<int> in0, in1;
    Wire<bool> sel;
    Wire<int> out;

    in0.set(1);
    in1.set(2);

    Mux<int> mux(&in0, &in1, &sel, &out);
    mux.name();
    mux.simulate();
    std::cout<<"excepted 1"<<std::endl;
    sel.set(true);
    mux.simulate();
    std::cout<<"excepted 2"<<std::endl;
}

void test_reg2alu2reg(){
    std::cout<<"===================Reg to Alu to Reg====================="<<std::endl;
    
    Wire<int> reg1value;
    Wire<int> reg1next;
    Register<int> reg1(&reg1value, &reg1next);
    
    reg1.setNext(5);
    reg1.simulate();
    std::cout << "Register 1 Output: " << reg1value.get() << " (Expected: 5)" << std::endl;

    Wire<int> aluOutput;
    Alu<int> alu(&reg1value, &reg1value, &aluOutput, ALUOp::ADD);
    alu.simulate();
    std::cout<< "ALU Output: " << aluOutput.get() <<" (Expected:10)" << std::endl;

    Wire<int> reg2Value;
    Register<int> reg2(&reg2Value, &aluOutput);
    reg2.simulate();
    std::cout<< "Register 2 Output: "<< reg2Value.get() << " (Expected:10) "<< std::endl;
}


int main(){
    test_wire();
    test_register();
    test_alu();
    test_reg2alu2reg();
    test_mux();
    return 0;
}