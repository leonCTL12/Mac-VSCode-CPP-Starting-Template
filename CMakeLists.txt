cmake_minimum_required(VERSION 3.13)
project(MyToyDatabase LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Logger library
file(GLOB_RECURSE LOGGER_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/logger/*.cpp")
add_library(logger STATIC ${LOGGER_SOURCES})
target_include_directories(logger PUBLIC ${CMAKE_SOURCE_DIR}/src/logger)

# Calculator library
file(GLOB_RECURSE CALCULATOR_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/calculator/*.cpp")
add_library(calculator STATIC ${CALCULATOR_SOURCES})
target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/src/calculator)

# Main executable
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS 
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/app.cpp")
add_executable(main ${MAIN_SOURCES})
target_link_libraries(main PRIVATE logger calculator)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

target_compile_options(main PRIVATE -g)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(main PRIVATE -fcolor-diagnostics)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(main PRIVATE -fdiagnostics-color=always)
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