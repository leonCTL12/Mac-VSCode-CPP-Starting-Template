file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/*.cpp")
add_executable(unit_test ${TEST_SOURCES})
target_include_directories(unit_test PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/key_value_store_internal
    ${CMAKE_SOURCE_DIR}/external/googletest/googletest/include
)
target_link_libraries(unit_test PRIVATE gtest gtest_main)

target_compile_options(unit_test PRIVATE -g)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(unit_test PRIVATE -fcolor-diagnostics)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(unit_test PRIVATE -fdiagnostics-color=always)
endif()

enable_testing()
add_test(NAME HelloWorldTests COMMAND unit_test)