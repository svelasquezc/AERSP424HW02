cmake_minimum_required(VERSION 3.0.0)
project(
    AERSP424HW02
    VERSION 0.1.0
    LANGUAGES C CXX
    DESCRIPTION "AERSP 424 Homework 02: University Park Airport Traffic Control Simulator"    
)


# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

     find_package(OpenGL REQUIRED)
     include(FetchContent)
     FetchContent_Declare(
         SDL2
         GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
         GIT_TAG release-2.28.5
     )
     set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
     FetchContent_MakeAvailable(SDL2)

endif()


add_subdirectory(src)

add_subdirectory(tests)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
