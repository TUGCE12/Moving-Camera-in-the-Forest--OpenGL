cmake_minimum_required(VERSION 3.24)
project(Forest)

set(CMAKE_CXX_STANDARD 17)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(.)

add_executable(Forest main.cpp)

target_link_libraries(Forest  PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)
