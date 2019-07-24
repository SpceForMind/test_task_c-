cmake_minimum_required(VERSION 3.0)

project(test_task_2)

#define the project
set(SOURCE_FILES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set(CMAKE_CXX_STANDARD 14)

# set the POCO paths and libs
set(POCO_PREFIX      ${CMAKE_CURRENT_SOURCE_DIR}/poco/) # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR ${POCO_PREFIX}/include)
set(POCO_LIB_DIR     ${POCO_PREFIX}/lib)
set(POCO_LIBS        ${POCO_LIB_DIR}/libPocoData.so
                     ${POCO_LIB_DIR}/libPocoDataSQLite.so
                     ${POCO_LIB_DIR}/libPocoFoundation.so)

# find threads library
find_package (Threads)

# set the include path for the app
target_include_directories(${PROJECT_NAME} PRIVATE ${POCO_INCLUDE_DIR})
# link the app against POCO
target_link_libraries(${PROJECT_NAME} ${POCO_LIBS} ${CMAKE_THREAD_LIBS_INIT})


