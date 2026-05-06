cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)
project(parallel_executor VERSION 1.0.0 DESCRIPTION "Синхронизация нескольких потоков исполнения через очередь сообщений на C++")

enable_testing()

find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

# set(SOURCE_EXE main.cpp)
# add_executable(main ${SOURCE_EXE})
add_subdirectory(src)
add_subdirectory(test)
# target_link_libraries(main device)
