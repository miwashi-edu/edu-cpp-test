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

add_executable(koans
    level0_empty.cpp
)

target_link_libraries(koans gtest_main)

add_test(NAME Koans COMMAND koans)
EOF
```

### tests/level1_variables.cpp

```bash
cat > ./tests/level0_empty.cpp << EOF
#include <gtest/gtest.h>#include <gtest/gtest.h>
#include <string>

TEST(Variables, Integers) {
    int x = 5;
    EXPECT_EQ(x, 10); // ❌ Fix: make this test pass
}

TEST(Variables, FloatingPoints) {
    double y = 3.14;
    EXPECT_NEAR(y, 6.28, 0.01); // ❌ Fix: make this test pass
}

TEST(Variables, Strings) {
    std::string s = "Hello";
    EXPECT_EQ(s, "Goodbye"); // ❌ Fix: make this test pass
}

TEST(Variables, Arithmetic) {
    int result = (2 + 2) * 2;
    EXPECT_EQ(result, 10); // ❌ Fix: make this test pass
}

TEST(Variables, BooleanLogic) {
    bool b = (5 > 10);
    EXPECT_TRUE(b); // ❌ Fix: make this test pass
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
