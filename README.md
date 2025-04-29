# edu-cpp-koans

> Testing

### Login

```bash
```

## Instructions

### Scaffold Project

```bash
cd ~
cd ws
mkdir -p cpp-koans
cd cpp-koans
touch ./tests/level3_parameters.cpp
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

add_executable(koans0 level0_empty.cpp)
add_executable(koans1 level1_variables.cpp)
add_executable(koans2 level2_controlflow.cpp)
add_executable(koans3 level3_parameters.cpp)

target_link_libraries(koans0 gtest_main)
target_link_libraries(koans1 gtest_main)
target_link_libraries(koans2 gtest_main)
target_link_libraries(koans3 gtest_main)

add_test(NAME Koans0 COMMAND koans0)
add_test(NAME Koans1 COMMAND koans1)
add_test(NAME Koans2 COMMAND koans2)
add_test(NAME Koans3 COMMAND koans3)
EOF
```

### tests/level0_empty.cpp

```bash
cat > ./tests/level3_parameters.cpp << EOF
#include <gtest/gtest.h>
#include <string>

// Pass by value: copies
void modifyByValue(int x) {
    x += 10;
}

// Pass by reference: modifies caller
void modifyByReference(int& x) {
    x += 10;
}

// Pass by const reference: cannot modify
int readByConstReference(const int& x) {
    return x + 5;
}

// Modify string by reference
void appendExclamation(std::string& s) {
    s += "!";
}

TEST(Parameters, ModifyByValue) {
    int a = 5;
    modifyByValue(a);
    EXPECT_EQ(a, 15); // ❌ Fix: should pass
}

TEST(Parameters, ModifyByReference) {
    int a = 5;
    modifyByReference(a);
    EXPECT_EQ(a, 5); // ❌ Fix: should pass
}

TEST(Parameters, ReadByConstReference) {
    int a = 10;
    int result = readByConstReference(a);
    EXPECT_EQ(result, 10); // ❌ Fix: should pass
}

TEST(Parameters, ModifyStringByReference) {
    std::string s = "Hello";
    appendExclamation(s);
    EXPECT_EQ(s, "Hello"); // ❌ Fix: should pass
}
EOF
```

### Build & Run

```bash
cmake -B build
make -C build
make -C build test
```

### Reset to commit or delete zero-project

#### Delete Project

```bash
cd ~
cd ws
rm -rf cpp-koans
```

#### Reset to Commit

```bash
cd ~
cd ws
cd cpp-koans
git reset --hard
git clean -df
```
