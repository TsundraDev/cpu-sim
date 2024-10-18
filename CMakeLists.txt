cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

project(cpu-sim)

# Create library
add_subdirectory(include/event-sim)

# Create test executable
add_executable(cpu-sim-test
  src/main.cpp
  src/Clock.cpp
  src/RegisterBlock.cpp
  src/Register.cpp
)
include_directories(cpu-sim-test include/event-sim)
target_link_libraries(cpu-sim-test event-sim)
