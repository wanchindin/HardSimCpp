#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <iostream>

template<typename T>
class MyVector
{
private:
    T* data;
    size_t size;
    size_t capacity;
    
public:
    MyVector();
    ~MyVector();

    void push_back(const T& value);
    void pop_back();
    size_t getSize() const;
    size_t getCapacity() const;
    T& operator[](size_t index);    // Access element at index
    void resize();
    void clear();

    // Deep copy
    MyVector(const MyVector<T>& other); // Copy constructor
    MyVector& operator=(const MyVector<T>& other);  // Copy assignment
};

#include "MyVector.tpp"
// Implementation of MyVector methods
#endif