#include <gtest/gtest.h>
#include <iostream>
// The simplest test ever
TEST(HelloWorld, SaysHello)
{
    std::cout << "Hello, World Test!" << std::endl;
    EXPECT_EQ(1 + 1, 2); // Basic arithmetic check
}