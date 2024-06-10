#include "Vector.h"

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector() noexcept 
    : data_(nullptr), size_(0), capacity_(0), allocator_(Allocator()) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector& other) 
    : data_(nullptr), size_(0), capacity_(0), allocator_(std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.allocator_)) {
    reallocate(other.capacity_);
    for (typename Vector<T, Allocator>::size_type i = 0; i < other.size_; ++i) {
        std::allocator_traits<allocator_type>::construct(allocator_, data_ + i, other.data_[i]);
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
}

template <typename T, typename Allocator>
Vector<T, Allocator>& Vector<T, Allocator>::operator=(const Vector& other) {
    if (this != &other) {
        for (size_type i = 0; i < size_; ++i) {
            std::allocator_traits<allocator_type>::destroy(allocator_, data_ + i);
        }
        allocator_.deallocate(data_, capacity_);

        allocator_ = std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.allocator_);
        reallocate(other.capacity_);
        for (size_type i = 0; i < other.size_; ++i) {
            std::allocator_traits<allocator_type>::construct(allocator_, data_ + i, other.data_[i]);
        }
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
    return *this;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() {
    for (size_type i = 0; i < size_; ++i) {
        std::allocator_traits<allocator_type>::destroy(allocator_, data_ + i);
    }
    allocator_.deallocate(data_, capacity_);
}
