cmake_minimum_required(VERSION 3.17)
project(generaattori)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(BEFORE include)
include_directories(AFTER /usr/local/include)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    add_subdirectory(lib/googletest)
    enable_testing()
    include_directories(SYSTEM
            ${gtest_SOURCE_DIR}
            ${gtest_SOURCE_DIR}/include)

    file(GLOB_RECURSE test_cases src/test/*.cpp)
    foreach(case_file ${test_cases})
        get_filename_component( case_name ${case_file} NAME_WE )
        set (case_name test_${case_name})
        add_executable(${case_name} ${case_file})
        target_link_libraries(${case_name}
                ${LINK_LIBS} gtest_main pthread)
        add_test(NAME ${case_name}
                COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${case_name}
                WORKING_DIRECTORY
                ${PROJECT_BINARY_DIR})
    endforeach()

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