include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator gtest_main calculator)

add_test(NAME CalculatorTests COMMAND test_calculator)
