FILE(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(placing_parentheses placing_parentheses.cpp)
target_link_libraries(placing_parentheses gtest)
