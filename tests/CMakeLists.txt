# Define the test executable (adjust the source file name as needed)
add_executable(logger_tests logger_test.cpp)

# Link against your library (e.g., logger) and Google Test
target_link_libraries(logger_tests PRIVATE logger gtest gtest_main)

# Integrate with CTest for automatic test discovery
include(GoogleTest)
gtest_discover_tests(logger_tests)