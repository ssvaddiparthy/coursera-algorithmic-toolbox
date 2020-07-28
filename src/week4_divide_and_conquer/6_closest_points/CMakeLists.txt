FILE(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(closest closest.cpp)
target_link_libraries(closest gtest)
