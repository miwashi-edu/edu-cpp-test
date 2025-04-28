#include <gtest/gtest.h>
#include "Calculator.h"

TEST(CalculatorTest, Addition) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
}

TEST(CalculatorTest, Subtraction) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(5, 3), 2);
}
