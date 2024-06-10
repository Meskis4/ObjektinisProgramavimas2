#pragma once

#include <memory>       
#include <iterator>     
#include <cstddef>      

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
     //  Member types
    using value_type = T;
    using size_type = size_t;
    using iterator = T*;
    using const_iterator = const T*;

// Constructors / destructor
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

};

// Constructor
template <typename T>
Vector<T>::Vector() : _size(0), _capacity(1), _data(new T[_capacity]) {}

// Destructor
template <typename T>
Vector<T>::~Vector() { delete[] _data; }
