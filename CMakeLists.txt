CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(ASCIIAnimator VERSION 0.0.1)

include(DownloadProject.cmake)
download_project(
    PROJ googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

FILE(GLOB _SOURCES src/*.cpp)

ADD_EXECUTABLE(${PROJECT_NAME} ${_SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} gtest mock_main)

ADD_CUSTOM_TARGET(run
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
    DEPENDS ${PROJECT_NAME}
)
