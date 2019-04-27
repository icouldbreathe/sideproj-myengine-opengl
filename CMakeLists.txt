# Project definition
cmake_minimum_required(VERSION 3.13)
project(MyEngine)

# Source files

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")


add_executable(${PROJECT_NAME}
  "src/main.cpp"
  "src/Engine.h"
  "src/window.h"
  "src/coreh.h"
  "src/platform/macos/WindowGLFW_GL.cpp"
  "src/platform/macos/WindowGLFW_GL.h"
  "src/Event.h"
  "src/Application.cpp"
  "src/Application.h"
  "src/KeyCodes.h")

target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")


# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
set(GLFW_DIR "${LIB_DIR}/glfw")
add_subdirectory(${GLFW_DIR})
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
