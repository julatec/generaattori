cmake_minimum_required(VERSION 3.17)
project(generaattori_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(BEFORE include)
include_directories(AFTER /usr/local/include)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(lib/)
    add_subdirectory(tests)
endif()

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

# Search for Boost filesystem system program_options
find_package(Boost REQUIRED filesystem system program_options)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else ()
    message(FATAL_ERROR "Failed to find the Boost library.")
endif ()

add_executable(cpp2h src/cpp/cpp2h.cpp)

target_link_libraries(cpp2h
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY})