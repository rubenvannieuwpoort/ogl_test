#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	GLFWwindow *window;
	
	if (!glfwInit()) return -1;
	
	window = glfwCreateWindow(1920, 1080, "Hello there", NULL, NULL);
	
	if (!window) {
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		// TODO: render stuff here
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}
