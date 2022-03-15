cmake_minimum_required(VERSION 3.16)
# -------------------------------

# Project settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(PROJECT_UNIT_TESTS_NAME ${PROJECT_NAME_STR}_unit_tests)


include_directories(
    ../libs/doctest/doctest
)
# Dependencies
# Gather the header and source files
set(UNIT_TESTS_SRC_FILES 
    LinkedListTests.cpp 
    QueueTests.cpp 
    StackTests.cpp 
    BinaryTreeTests.cpp
    Main.cpp)

# Include paths
set(UNIT_TESTS_INCLUDES ${PROJECT_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/src)

# Assign the include directories
include_directories(${UNIT_TESTS_INCLUDES})

# Build unit tests
add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} doctest)
enable_testing()
# doctest_discover_tests(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES})