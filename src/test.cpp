#include <iostream>
#include "../include/wire.hpp"
#include "../include/register.hpp"

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
    delete reg;
}


int main(){
    test_wire();
    test_register();
    return 0;
}