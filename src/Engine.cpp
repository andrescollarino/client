#include <Engine.h>

namespace {

GLFWwindow* g_window = nullptr;

// Input
};

namespace {

	void InputCharacterCallBack(GLFWwindow* window,unsigned int key)
	{
		DEBUG_LOG("Input Text : " + std::to_string((char)key));
	}

	void InputKeyCallBack(GLFWwindow* window,int key,int scanCode,int action,int mods)
	{
		DEBUG_LOG("Input Key : " + std::to_string((char)key));
	}

	void InputMousePositionCallBack(GLFWwindow* window,double x, double y)
	{
		DEBUG_LOG("Mouse Position : " + std::to_string((int)x) + "," + std::to_string((int)y));
	}

	void InputMouseEnterCallBack(GLFWwindow* window,int entered)
	{
		DEBUG_LOG("Mouse Enter");
	}

	void InpuMouseButtonCallBack(GLFWwindow* window,int button,int action,int mods)
	{
		DEBUG_LOG("Mouse Button");
	}

	void InputMouseScrollCallBack(GLFWwindow* window,double xoffset,double yoffset)
	{
		DEBUG_LOG("Mouse Scrool");
	}
};

bool Engine::Initialize(int w, int h, std::string title) {
	if (!glfwInit()) {
		DEBUG_ERROR("Failed initialize GLFW3.");
		return ENGINE_ERROR;
	}

	// Antialiasing x4
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Opengl V3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Requerido por mac OSX
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Creo la Ventana
	g_window = nullptr;
	g_window = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);

	if (g_window == nullptr) {
		DEBUG_ERROR("Failed created window.");
		glfwTerminate();
		return ENGINE_ERROR;
	}

	glfwMakeContextCurrent(g_window);

	// Initialize glew
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		DEBUG_ERROR("Failed Initialize glew.");
		glfwTerminate();
		return ENGINE_ERROR;
	}

	// Initialize Input
	glfwSetCharCallback(g_window ,InputCharacterCallBack);
	glfwSetKeyCallback(g_window,InputKeyCallBack);
	glfwSetCursorPosCallback(g_window,InputMousePositionCallBack);
	glfwSetCursorEnterCallback(g_window,InputMouseEnterCallBack);
	glfwSetMouseButtonCallback(g_window,InpuMouseButtonCallBack);
	glfwSetScrollCallback(g_window,InputMouseScrollCallBack);

	return !ENGINE_ERROR;
}

void Engine::Run() {
	do {
		glfwSwapBuffers(g_window);
		glfwPollEvents();

	} while (glfwWindowShouldClose(g_window) == 0);

	Release();
}

void Engine::Release() {
	glfwTerminate();
}

