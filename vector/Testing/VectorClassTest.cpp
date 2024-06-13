#include <gtest/gtest.h>
#include "Vector.h"

// Test the default constructor
TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 1);
}

// Test push_back and size
TEST(VectorTest, PushBackAndSize) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Test pop_back
TEST(VectorTest, PopBack) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 1);
    EXPECT_THROW(vec[1], std::out_of_range);
}


// Test erase
TEST(VectorTest, Erase) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(vec.begin() + 1, vec.begin() + 2);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
}

// Test clear
TEST(VectorTest, Clear) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 2); 
}

// Test initializer list constructor
TEST(VectorTest, InitializerListConstructor) {
    Vector<int> vec = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
    EXPECT_EQ(vec[4], 5);
}

// Test copy constructor
TEST(VectorTest, CopyConstructor) {
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2 = vec1;
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}

// Test move constructor
TEST(VectorTest, MoveConstructor) {
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2 = std::move(vec1);
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
    EXPECT_EQ(vec1.size(), 0);
}

// Test copy assignment operator
TEST(VectorTest, CopyAssignment) {
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2;
    vec2 = vec1;
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}

// Test move assignment operator
TEST(VectorTest, MoveAssignment) {
    Vector<int> vec1 = { 1, 2, 3 };
    Vector<int> vec2;
    vec2 = std::move(vec1);
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
    EXPECT_EQ(vec1.size(), 0);
}

// Test reserve
TEST(VectorTest, Reserve) {
    Vector<int> vec;
    vec.reserve(10);
    EXPECT_EQ(vec.capacity(), 10);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
