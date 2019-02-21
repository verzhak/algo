
cmake_minimum_required(VERSION 3.12)

find_package(PkgConfig)
#find_package(Boost)

set(CXX_FLAGS "-Wall -std=c++17")

add_executable(binary_tree main_binary_tree.cpp)
# target_link_libraries(rb ${BOOST_LIBRARIES})

