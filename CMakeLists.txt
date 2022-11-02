cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(DS-Algorithm)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(glog REQUIRED libglog)

link_libraries(${glog_LIBRARIES})


add_subdirectory(src/backtracking)
# add_subdirectory(dynamic-programming)
# add_subdirectory(graph)
add_subdirectory(src/linked-list)
# add_subdirectory(sorting)
# add_subdirectory(searching)
