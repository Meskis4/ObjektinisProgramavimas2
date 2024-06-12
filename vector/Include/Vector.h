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
void clear();
Vector(std::initializer_list<T> init);

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

// Add element to the end
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        reserve(2 * _capacity);
    }
    _data[_size++] = value;
}

// Remove element from the end
template <typename T>
void Vector<T>::pop_back() {
    if (_size > 0) {
        _data[--_size].~T();
    }
    else {
        throw std::out_of_range("pop_back() called on empty vector");
    }
}

// Swap function
template <typename T>
void Vector<T>::swap(Vector& other) {
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(_data, other._data);
}

// end() function
template <typename T>
T* Vector<T>::end() {
    return _data + _size;
}

// Access element at index
template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

// Get size of the vector
template <typename T>
size_t Vector<T>::size() const {
    return _size;
}

// Get capacity of the vector
template <typename T>
size_t Vector<T>::capacity() const {
    return _capacity;
}

// Reserve more space
template <typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity > _capacity) {
        T* new_data = new T[new_capacity];
        std::copy(_data, _data + _size, new_data);
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }
}

//Clear vector
template <typename T>
void Vector<T>::clear() {
    delete[] _data;
    _data = new T[_capacity];
    _size = 0;
}
