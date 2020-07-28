FILE(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(different_summands different_summands.cpp)
target_link_libraries(different_summands gtest)
