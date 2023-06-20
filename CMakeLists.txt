cmake_minimum_required(VERSION 3.5)

project(coordinator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(coordinator main.cpp
coordinator.hpp coordinator.cpp
node.hpp node.cpp
runnable.hpp runnable.cpp
suites.hpp suites.cpp
tests.hpp tests.cpp
test1.hpp test1.cpp
test2.hpp test2.cpp
test3.hpp test3.cpp
suite1.hpp suite1.cpp
suite2.hpp suite2.cpp
suite_main.hpp suite_main.cpp
suite_first.hpp suite_first.cpp
suite_second.hpp suite_second.cpp
suite_third.hpp suite_third.cpp
add_node.cpp
find_node.cpp
fill_tree.cpp
print_tree.cpp
test_list.hpp test_list.cpp

)
