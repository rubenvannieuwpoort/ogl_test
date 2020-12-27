cmake_minimum_required(VERSION 3.5)
project(OpenGL_test LANGUAGES CXX)

add_compile_options(-Wall)

include_directories(/opt/homebrew/include)

set(SOURCES main.cpp)
add_executable(main ${SOURCES})
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories($(GLEW_INCLUDE_DIRS))

if (APPLE)
	target_link_libraries(main ${GLEW_LIBRARY} /opt/homebrew/lib/libglfw.3.dylib)
	target_link_libraries(main "-framework OpenGL")
else()
	target_link_libraries(main ${GLEW_LIBRARY} ${GLFW_STATIC_LIBRARIES})
	target_link_libraries(main glfw OpenGL::GL)
endif (APPLE)
