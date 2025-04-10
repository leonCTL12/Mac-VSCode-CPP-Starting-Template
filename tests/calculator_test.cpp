#include <gtest/gtest.h>
#include "../src/calculator/calculator.h" // Adjust based on your actual calculator header

TEST(CalculatorTest, Addition)
{
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
    EXPECT_EQ(calc.add(0, 0), 0);
}
