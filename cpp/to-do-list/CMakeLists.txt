cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(lib STATIC lib/list.cpp)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

project(Todolist VERSION 1.0)
add_executable(main src/main.cpp)
# target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main PUBLIC lib)
