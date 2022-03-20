# --------------------------------------
cmake_minimum_required(VERSION 3.20.4)

# Definitions
set(PROJECT_NAME_STR DataStructures)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_STANDARD 17)
# Project title and define versioning
project(${PROJECT_NAME_STR})
# Gather all sources except the main entry point

# Build object files for reuse (e.g. in test)
#ADD_LIBRARY(demo_objects OBJECT ${INC_FILES} ${SRC_FILES})
# Dependencies

# Unit tests
add_subdirectory(tests)
add_subdirectory(libs/doctest)
# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Build
#set(SOURCE_FILES src/main.cpp $<TARGET_OBJECTS:demo_objects>)
set(SOURCE_FILES src/Main.cpp 
    src/Share/DoublyLinkedList.h
    src/Share/LinkedList.h 
    src/Share/LinkedStack.h
    src/Share/LinkedQueue.h
    src/Share/Queue.h 
    src/Share/Stack.h 
    src/Share/BinaryTree.h
    src/Share/RBTree.h
    src/Share/HashTable.h)
add_executable(DataStructures ${SOURCE_FILES})
target_link_libraries(DataStructures ${Boost_LIBRARIES})
