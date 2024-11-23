#include "Header1.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		glfwSetWindowSize(window, width+10, height+10);
	if (key == GLFW_KEY_O && action == GLFW_PRESS)
		glfwSetWindowSize(window, width-10, height-10);
}

int main() {
	//Инициализация GLFW
	glfwInit();
	//Настройка GLFW
	//Задается минимальная требуемая версия OpenGL. 
	//Мажорная 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//Минорная
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Установка профайла для которого создается контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Выключение возможности изменения размера окна
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// GLFW
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Glew
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// Viewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);

	// Engine (Game cycle)
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		
		//Clear screen
		glClearColor(0.2f, 0.5f, 0.8f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw
		glfwSetKeyCallback(window, key_callback);

		glfwSwapBuffers(window);
	}

	// Clear
	glfwTerminate();

	return 0;
}
