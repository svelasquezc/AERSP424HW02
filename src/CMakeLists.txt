 file(GLOB VISUALIZATION_HEADERS CMAKE_CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/Visualization/*.hpp")
 add_library(SDLVisualization HW2_Visualizer.cpp ${VISUALIZATION_HEADERS})
 # We need this directory, and users of our library will need it too
 target_include_directories(SDLVisualization PRIVATE ../include)
 target_compile_features(SDLVisualization PUBLIC cxx_std_17)
 target_link_libraries(SDLVisualization SDL2::SDL2 SDL2::SDL2main)
 target_link_libraries(SDLVisualization OpenGL::GL)


file(GLOB AIRPORT_HEADERS CMAKE_CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/TrafficControl/*.hpp")

add_library(airportControl INTERFACE)

# We need this directory, and users of our library will need it too
target_include_directories(airportControl INTERFACE ../include)

# All users of this library will need at least C++17
target_compile_features(airportControl INTERFACE cxx_std_17)


add_executable(${PROJECT_NAME} main.cpp ${AIRPORT_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE airportControl)
target_link_libraries(${PROJECT_NAME} PRIVATE SDLVisualization)


# Copy the resource image to the same folder as the executable file.
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD    # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different       # which executes "cmake - E copy_if_different..."
        "${CMAKE_SOURCE_DIR}/resources/map.bmp" # <--this is also in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)             # <--this is out-file path

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${AIRPORT_HEADERS} ${VISUALIZATION_HEADERS}
  )