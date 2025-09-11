cmake_minimum_required(VERSION 3.25)
project(DarkStar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# SFML
fetchcontent_declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
)
fetchcontent_makeavailable(SFML)

# SPDLOG
fetchcontent_declare(
        SPDLOG
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.15.3
)
fetchcontent_makeavailable(SPDLOG)

# Windows specific compilation flag
IF (MSVC OR MSYS OR MINGW)
    add_definitions(-DDARKSTAR_BUILD_DLL)
ENDIF ()

add_subdirectory(src)
add_subdirectory(test)