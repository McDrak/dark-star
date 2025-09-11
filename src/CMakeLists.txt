# Temporal grab of .cpp files
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(DarkStarEngine ${ENGINE_SOURCES})

# Include the Include Folder
target_include_directories(DarkStarEngine PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link SFML
target_link_libraries(DarkStarEngine PUBLIC sfml-system sfml-window sfml-graphics)

#Link SPDLOG
target_link_libraries(DarkStarEngine PUBLIC spdlog)