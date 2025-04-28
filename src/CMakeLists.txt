add_library(calculator Calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(hello main.cpp)
target_link_libraries(hello calculator)
