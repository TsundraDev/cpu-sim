cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

project(cpu-sim)

# Add external libraries
add_subdirectory(include/event-sim)

# Create test executable
add_executable(cpu-sim-test
  src/main.cpp

  src/base/BaseBlock.cpp
  src/base/ClockBlock.cpp
  src/base/WireBlock.cpp
  src/base/RegisterBlock.cpp

  src/components/Clock.cpp
  src/components/Register.cpp
  src/components/UpdatePC.cpp
)

include_directories(src)

include_directories(cpu-sim-test include/event-sim)
target_link_libraries(cpu-sim-test event-sim)
