# MyVector

## Introduction
`MyVector` is a custom implementation of a dynamic array in C++, inspired by the standard `std::vector` container. It supports dynamic resizing, random access, and deep copying, and includes exception handling for invalid index access.

## Features
- **Dynamic Resizing**: Automatically expands capacity when needed.
- **Random Access**: Access elements using the `operator[]`.
- **Deep Copy**: Implements a copy constructor and copy assignment operator to ensure independent memory management.
- **Clear Functionality**: Reset the vector to an empty state.
- **Exception Handling**: Throws `std::out_of_range` for invalid index access.

## Implemented Methods
- `push_back(const T& value)`: Adds an element to the end of the vector.
- `pop_back()`: Removes the last element of the vector.
- `getSize() const`: Returns the current number of elements in the vector.
- `getCapacity() const`: Returns the current capacity of the vector.
- `operator[](size_t index)`: Provides random access to elements.
- `resize()`: Doubles the capacity of the vector when needed.
- `clear()`: Clears all elements and resets the vector.

## How to Compile and Run
1. Compile the program:
   ```bash
   g++ -std=c++17 main.cpp -o myVector