cmake_minimum_required(VERSION 3.5)
project(OpenGL_test LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH "C:/glew")
list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/GLFW")

add_compile_options(-Wall)

set(SOURCES main.cpp)
add_executable(main ${SOURCES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)
include_directories(${GLFW3_INCLUDE_DIRS})
link_libraries(${GLFW3_LIBRARIES})
target_link_libraries(main ${OPENGL_gl_LIBRARY} glfw)

if (APPLE)
	include_directories(/opt/homebrew/include)
	link_directories(/opt/homebrew/lib)
	target_link_libraries(main "-framework OpenGL")
endif (APPLE)

