# edu-raspberry-os

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
mkdir src
mkdir include
mkdir tests
mkdir build
touch ./CMakeLists.txt
touch ./tests/CMakeLists.txt
touch ./tests/level0_empty.cpp
```

### CMakeLists.txt (Project Structure)

```bash
cat > CMakeLists.txt << EOF
cmake_minimum_required(VERSION 3.16)
project(cpp-koans LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

add_subdirectory(tests)
EOF
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

### tests/level0_empty.cpp

```bash
cat > ./tests/level0_empty.cpp << EOF
#include <gtest/gtest.h>

// Nothing here yet! 
// Progress to level-1!
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
