FILE(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(points_and_segments points_and_segments)
target_link_libraries(points_and_segments gtest)
