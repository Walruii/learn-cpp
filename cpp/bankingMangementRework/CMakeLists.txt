cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(bankManagement VERSION 1.0)

# Include directories for the project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

# Add libraries
add_library(lib1 STATIC lib/bank.cpp)
add_library(lib2 STATIC lib/user.cpp)
add_library(lib3 STATIC lib/gui.cpp)
add_library(lib4 STATIC lib/log.cpp)

# Link dependencies between libraries
target_link_libraries(lib3 PUBLIC lib1 lib2) # Assuming gui.cpp depends on bank and user
target_link_libraries(lib1 PUBLIC lib2) # Assuming bank depends on user

# Add executable
add_executable(main src/main.cpp)

# Link libraries to the executable
target_link_libraries(main PUBLIC lib1 lib2 lib3 lib4)
