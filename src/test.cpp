#include <iostream>
#include "../include/register.hpp"

void test_register(){
    Register<int> *reg = new Register<int>();
    std::cout<<"Initial value:"<<reg->get()<<std::endl;
    
    reg->setNext(1);
    reg->simulate();    //1
    std::cout<<reg->name()<<std::endl;
    delete reg;
}

int main(){
    test_register();
    return 0;
}