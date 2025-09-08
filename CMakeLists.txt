cmake_minimum_required(VERSION 3.25)
project(DarkStar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_subdirectory(src)
add_subdirectory(test)