cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(lib STATIC lib/employee.cpp)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

project(Classes VERSION 1.0)
add_executable(main src/classes.cpp)
# target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
target_link_libraries(main PUBLIC lib)
