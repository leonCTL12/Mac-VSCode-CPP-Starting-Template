cmake_minimum_required(VERSION 3.13)
project(MyToyDatabase LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
add_executable(main ${SOURCES})

target_compile_options(main PRIVATE -g)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(main PRIVATE -fcolor-diagnostics)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(main PRIVATE -fdiagnostics-color=always)
endif() 

# Set up Google Test
# Add Google Test submodule
add_subdirectory(external/googletest EXCLUDE_FROM_ALL)

# Test executable with glob for tests/
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/*.cpp")
add_executable(unit_test ${TEST_SOURCES})
target_include_directories(unit_test PRIVATE 
    ${CMAKE_SOURCE_DIR}/include  # If your headers are here
    ${CMAKE_SOURCE_DIR}/src/key_value_store_internal  # For KeyValueStore (optional)
    external/googletest/googletest/include  # GTest headers
)
target_link_libraries(unit_test PRIVATE 
    gtest 
    gtest_main  # Provides main()
)

# Apply same compile options to tests for consistency
target_compile_options(unit_test PRIVATE -g)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(unit_test PRIVATE -fcolor-diagnostics)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(unit_test PRIVATE -fdiagnostics-color=always)
endif()

# Enable testing and add test
enable_testing()
add_test(NAME HelloWorldTests COMMAND unit_test)