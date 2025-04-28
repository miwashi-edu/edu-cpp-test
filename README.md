# edu-raspberry-os

> Testing

### Login

```bash
```

## Instructions

### Prepare

```bash
cd ~
cd ws
cd cpp-koans
```

### tests/CMakeLists.txt (GoogleTest and Unit Tests)

```bash
cat > ./tests/CMakeLists.txt << EOF
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(koans1 level0_empty.cpp)
add_executable(koans2 level2_controlflow.cpp)

target_link_libraries(koans1 gtest_main)
target_link_libraries(koans2 gtest_main)

add_test(NAME Koans1 COMMAND koans1)
add_test(NAME Koans2 COMMAND koans2)
EOF
```

### tests/level2_controlflow.cpp

```bash
cat > ./tests/level2_controlflow.cpp << EOF
#include <gtest/gtest.h>
#include <string>

TEST(ControlFlow, IfElse) {
    int a = 5;
    std::string result;
    if (a > 10) {
        result = "greater";
    } else {
        result = "smaller";  // fix
    }
    EXPECT_EQ(result, "greater");
}

TEST(ControlFlow, ForLoopSum) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += i;
    }
    EXPECT_EQ(sum, 6); // fix
}

TEST(ControlFlow, WhileLoopCountDown) {
    int n = 5;
    int counter = 0;
    while (n > 0) {
        n--; 
        counter++;
    }
    EXPECT_EQ(counter, 3); // fix
}

TEST(ControlFlow, NestedIf) {
    int x = 5;
    int y = 10;
    std::string res;
    if (x < y) {
        if (y > 20) {
            res = "big";
        } else {
            res = "small";
        }
    }
    EXPECT_EQ(res, "big"); // fix
}
EOF
```

### Build & Run

```bash
cmake -B build
make -C build
make -C build test
```

### Reset to commit

#### Reset to Commit

```bash
cd ~
cd ws
cd cpp-koans
git reset --hard
git clean -df
```
