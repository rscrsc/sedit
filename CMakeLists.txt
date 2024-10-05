cmake_minimum_required(VERSION 3.10)
project(sedit)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find the NCurses library
find_package(Curses REQUIRED)

# Specify the executable target
add_executable(sedit src/main.cpp src/Buffer.cpp)

# Link the NCurses library
target_link_libraries(sedit ${CURSES_LIBRARIES})

# Include the NCurses headers
target_include_directories(sedit PRIVATE ${CURSES_INCLUDE_DIR} include)

include_directories(include)