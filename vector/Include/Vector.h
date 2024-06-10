#pragma once

#include <memory>       
#include <iterator>     
#include <cstddef>      

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
public:
    // Member types
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

    // Iterator types
    using iterator = pointer;  
    using const_iterator = const_pointer; 
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    //Constructors / Destructor
    Vector() noexcept;
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

};
