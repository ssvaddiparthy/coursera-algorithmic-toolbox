FILE(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(partition3 partition3.cpp)
target_link_libraries(partition3 gtest)
