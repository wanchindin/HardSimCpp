#include <iostream>
#include "MyVector.hpp"
using namespace std;
template<typename T>
MyVector<T>::MyVector() : size(0), capacity(10)
{
    data = new T[capacity];
    cout<<"Constructor"<<endl;
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete[] data;
    cout<<"Destructor"<<endl;
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