cmake_minimum_required(VERSION 2.6)
project(test_task_1)

find_package (Threads)
add_executable(main main.cpp)
target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT})