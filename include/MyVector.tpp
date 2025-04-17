#include <iostream>
#include "MyVector.hpp"
using namespace std;
template<typename T>
MyVector<T>::MyVector() : size(0), capacity(10)     //Constructor
{
    data = new T[capacity];
}

template<typename T>
MyVector<T>::~MyVector()    //Destructor
{
    delete[] data;
}

template <typename T>
void MyVector<T>::push_back(const T& value)
{
    if(size >= capacity)
    {
        resize();
    }
    data[size++] = value;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if(size > 0)
    {
        --size;
    }
}

template <typename T>
size_t MyVector<T>::getSize() const
{
    return size;
}

template <typename T>
size_t MyVector<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
T& MyVector<T>::operator[](size_t index)
{
    if(index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void MyVector<T>::resize()
{
    capacity *= 2;
    T* newData = new T[capacity];
    for(size_t i=0; i<size; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    cout<<"Resizing to capacity: "<<capacity<<endl;
}

template <typename T>
void MyVector<T>::clear()
{
    delete[] data;
    data = new T[capacity];
    size = 0;
    cout<<"Cleared vector"<<endl;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other): size(other.size), capacity(other.capacity)
{
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]; 
    }
    std::cout << "Copy Constructor Called" << std::endl;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
    if (this != &other) {
        delete[] data; // Free existing resource
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]; 
        }
    }
    std::cout << "Copy Assignment Operator Called" << std::endl;
    return *this;
}