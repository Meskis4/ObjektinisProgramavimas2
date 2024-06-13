#pragma once

#include <cstddef> 
#include <stdexcept>
#include <algorithm> 
#include <iterator>  

template <typename T>
class Vector {
public:
    // Public member types
    using value_type = T;
    using size_type = size_t;
    using iterator = T*;
    using const_iterator = const T*;

    // Constructors and destructor
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    // Assignment operators
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    // Public member functions
    void push_back(const T& value);
    void pop_back();
    void swap(Vector& other);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    void erase(iterator first, iterator last);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    size_t capacity() const;
    void clear();
    Vector(std::initializer_list<T> init);
    void reserve(size_t new_capacity);

private:
    // Private member variables
    size_t _size;
    size_t _capacity;
    T* _data;

};

// std::swap specialization for Vector
template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs) {
    lhs.swap(rhs);
}

// Implementation

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

// Begin iterator
template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return _data;
}

// End iterator
template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return _data + _size;
}

// Const begin iterator
template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
    return _data;
}

// Const end iterator
template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const {
    return _data + _size;
}



// Erase range of elements
template <typename T>
void Vector<T>::erase(iterator first, iterator last) {
    if (first < begin() || last > end() || first > last) {
        throw std::out_of_range("Invalid iterator range");
    }

    iterator new_end = std::move(last, end(), first);
    size_t num_erased = last - first;
    _size -= num_erased;

    // Destroy the moved-from elements at the end
    for (iterator it = new_end; it != end(); ++it) {
        it->~T();
    }
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
        std::move(_data, _data + _size, new_data);
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

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) : _size(init.size()), _capacity(init.size()), _data(new T[init.size()]) {
    std::copy(init.begin(), init.end(), _data);
}
