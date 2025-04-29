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

// Pass by value: copies (mutation does NOT affect original)
void modifyByValue(int x) {
    x += 10;
}

// Pass by reference: modifies caller (mutation DOES affect original)
void modifyByReference(int& x) {
    x += 10;
}

// Pass by const reference: cannot modify caller
int readAndTryModifyByConstReference(const int& x) {
    // x++;  // illegal: would not compile if uncommented
    return x + 5;
}

// Modify string by reference (mutation DOES affect original)
void appendExclamation(std::string& s) {
    s += "!";
}

// Try to modify string passed by const reference (should not modify)
std::string copyAndAppend(const std::string& s) {
    return s + "!";
}

TEST(Parameters, ModifyByValue_ShouldNotChangeOriginal) {
    int a = 5;
    modifyByValue(a);
    EXPECT_EQ(a, 15); // ❌ Fix: a did not change, still 5
}

TEST(Parameters, ModifyByReference_ShouldChangeOriginal) {
    int a = 5;
    modifyByReference(a);
    EXPECT_EQ(a, 5); // ❌ Fix: a actually became 15
}

TEST(Parameters, ReadConstReference_ShouldNotChangeOriginal) {
    int a = 10;
    int result = readAndTryModifyByConstReference(a);
    EXPECT_EQ(a, 5); // ❌ Fix: a remains 10
    EXPECT_EQ(result, 10); // ❌ Fix: result is 15
}

TEST(Parameters, ModifyStringByReference_ShouldChangeOriginal) {
    std::string s = "Hello";
    appendExclamation(s);
    EXPECT_EQ(s, "Hello"); // ❌ Fix: s actually became "Hello!"
}

TEST(Parameters, CopyStringByConstReference_ShouldNotChangeOriginal) {
    std::string s = "Hi";
    std::string newString = copyAndAppend(s);
    EXPECT_EQ(s, "Hi!"); // ❌ Fix: s remains "Hi"
    EXPECT_EQ(newString, "Hi"); // ❌ Fix: newString is "Hi!"
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
