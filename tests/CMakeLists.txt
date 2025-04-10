# Define the test executable
add_executable(logger_tests logger_test.cpp)
# Link against your library (e.g., logger) and Google Test
# gtestmain is the main function for Google Test
target_link_libraries(logger_tests PRIVATE logger gtest gtest_main)

add_executable(calculator_tests calculator_test.cpp)
target_link_libraries(calculator_tests PRIVATE calculator gtest gtest_main)

# Integrate with CTest for automatic test discovery
include(GoogleTest)
gtest_discover_tests(logger_tests)
gtest_discover_tests(calculator_tests)