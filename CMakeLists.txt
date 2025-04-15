cmake_minimum_required(VERSION 3.13)
project(StartingTemplate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/debug)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/release)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/release)
else()
    message(WARNING "Unknown build type '${CMAKE_BUILD_TYPE}', defaulting to output/other")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/other)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/other)
endif()

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Include directories


# Logger library
file(GLOB_RECURSE LOGGER_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/logger/*.cpp")
add_library(logger STATIC ${LOGGER_SOURCES})
# this need to be public
# for private the include directory are added only to the target itself
# for public the include directory are added to the target and any target that link against this target
target_include_directories(logger PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)


# Calculator library
file(GLOB_RECURSE CALCULATOR_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/calculator/*.cpp")
add_library(calculator STATIC ${CALCULATOR_SOURCES})
target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# Main executable
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS 
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/app.cpp")
add_executable(main ${MAIN_SOURCES})
target_link_libraries(main PRIVATE logger calculator)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)


if(CMAKE_BUILD_TYPE MATCHES Debug)
    # -g includes debug symbols, increasing binary size but not affecting runtime performance
    target_compile_options(main PRIVATE -g -O0)
    target_compile_options(logger PRIVATE -g -O0)
target_compile_options(calculator PRIVATE -g -O0)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(main PRIVATE -O3 -DNDEBUG)
    target_compile_options(logger PRIVATE -O3 -DNDEBUG)
    target_compile_options(calculator PRIVATE -O3 -DNDEBUG)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(main PRIVATE -fcolor-diagnostics)
    target_compile_options(logger PRIVATE -fcolor-diagnostics)
target_compile_options(calculator PRIVATE -fcolor-diagnostics)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(main PRIVATE -fdiagnostics-color=always)
    target_compile_options(logger PRIVATE -fdiagnostics-color=always)
    target_compile_options(calculator PRIVATE -fdiagnostics-color=always)
endif()


# Option to build tests (enabled by default)
option(BUILD_TESTS "Build the unit tests" ON)
if(BUILD_TESTS)
    # Add Google Test from the external/googletest directory
    add_subdirectory(external/googletest)
    
    # Enable CTest for test management
    enable_testing()
    
    # Include the tests subdirectory
    # Tell CMake to look for another CMakeLists.txt file in the tests directory
    add_subdirectory(tests) 
endif()

option(BUILD_BENCHMARKS "Build the benchmarks" ON)
if(BUILD_BENCHMARKS)
    # Include the benchmarks subdirectory
    # Tell CMake to look for another CMakeLists.txt file in the benchmarks directory
    add_subdirectory(external/benchmark)

    add_subdirectory(bench)
endif()