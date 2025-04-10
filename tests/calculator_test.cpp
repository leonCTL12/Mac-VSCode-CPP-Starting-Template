#include <gtest/gtest.h>
#include "calculator/calculator.h" // This works, coz we have put src in the include path in the CMakeLists.txt

TEST(CalculatorTest, Addition)
{
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
    EXPECT_EQ(calc.add(0, 0), 0);
}

TEST(CalculatorTest, AdditionAgain)
{
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
    EXPECT_EQ(calc.add(0, 0), 0);
}
