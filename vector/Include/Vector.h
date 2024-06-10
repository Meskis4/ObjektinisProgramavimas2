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

  Vector& operator=(const Vector& other);
  Vector& operator=(Vector&& other) noexcept;

//Member functions
void push_back(const T& value);
void pop_back();
void swap(Vector& other);
T* end();
T& operator[](size_t index);
const T& operator[](size_t index) const;
size_t size() const;
size_t capacity() const;

private:
    size_t _size;
    size_t _capacity;
    T* _data;

    // Private member functions
    void reserve(size_t new_capacity);
};

};

// Constructor
template <typename T>
Vector<T>::Vector() : _size(0), _capacity(1), _data(new T[_capacity]) {}

// Destructor
template <typename T>
Vector<T>::~Vector() { delete[] _data; }

// Copy Constructor
template <typename T>
Vector<T>::Vector(const Vector& other) : _size(other._size), _capacity(other._capacity), _data(new T[_capacity]) {
    std::copy(other._data, other._data + other._size, _data);
}

// Move Constructor
template <typename T>
Vector<T>::Vector(Vector&& other) noexcept : _size(other._size), _capacity(other._capacity), _data(other._data) {
    other._size = 0;
    other._capacity = 0;
    other._data = nullptr;
}

// Copy Assignment Operator
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        _data = new T[_capacity];
        std::copy(other._data, other._data + other._size, _data);
    }
    return *this;
}

// Move Assignment Operator
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }
    return *this;
}
