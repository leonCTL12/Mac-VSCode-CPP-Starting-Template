# Define the test executable 
# The reason why I have combine all the tests into one executable is that for easy vscode debugging
add_executable(all_tests logger_test.cpp calculator_test.cpp)
# Link against your library (e.g., logger) and Google Test
# gtestmain is the main function for Google Test
target_link_libraries(all_tests PRIVATE logger calculator gtest gtest_main)

# Integrate with CTest for automatic test discovery
include(GoogleTest)
gtest_discover_tests(all_tests)