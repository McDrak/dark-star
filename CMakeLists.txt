cmake_minimum_required(VERSION 3.25)
project(DarkStar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_subdirectory(src)
add_subdirectory(test)