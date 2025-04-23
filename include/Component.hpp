#pragma once

class Component{
    public:
        virtual void simulate() = 0;
        virtual ~Component() = default;
};