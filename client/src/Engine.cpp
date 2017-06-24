#include <Engine.h>

#define MAX_KEY 500
#define MAX_MOUSE_BUTTON 50

namespace
{

GLFWwindow *g_window = nullptr;

// Input
bool g_enableTextInput = false;
bool *g_keys = nullptr;
glm::vec2 g_mousePosition;
bool *g_mouseButton = nullptr;
glm::vec2 g_scrollOffset;
std::wstring g_inputText;
};

namespace
{

void InputCharacterCallBack(GLFWwindow *window, unsigned int key)
{
	if (g_enableTextInput)
		g_inputText.push_back(static_cast<wchar_t>(key));
}

void InputKeyCallBack(GLFWwindow *window, int key, int scanCode, int action, int mods)
{
	if (action == GLFW_PRESS)
		g_keys[key] = true;

	if (action == GLFW_RELEASE)
		g_keys[key] = false;

	if (g_enableTextInput)
	{
		if (key == GLFW_KEY_BACKSPACE && (action == GLFW_PRESS || action == GLFW_RELEASE))
			g_inputText.pop_back();
	}
}

void InputMousePositionCallBack(GLFWwindow *window, double x, double y)
{
	g_mousePosition.x = static_cast<int>(x);
	g_mousePosition.y = static_cast<int>(y);
}

void InputMouseEnterCallBack(GLFWwindow *window, int entered)
{
	//DEBUG_LOG("Mouse Enter");
}

void InpuMouseButtonCallBack(GLFWwindow *window, int button, int action, int mods)
{
	//DEBUG_LOG("Mouse Button");
}

void InputMouseScrollCallBack(GLFWwindow *window, double xoffset, double yoffset)
{
	g_scrollOffset.x = static_cast<float>(xoffset);
	g_scrollOffset.y = static_cast<float>(yoffset);
}

void ClearInput()
{
	g_keys = new bool[MAX_KEY];
	g_mouseButton = new bool[MAX_MOUSE_BUTTON];

	// Clear Keys
	for (auto i = 0; i < MAX_KEY; i++)
		g_keys[i] = false;

	// Clear Mouse Buttons
	for (auto i = 0; i < MAX_MOUSE_BUTTON; i++)
		g_mouseButton[i] = false;

	Input::DisableInputText();
}
};

void Input::EnableInputText()
{
	g_enableTextInput = true;
	g_inputText.clear();
}

void Input::DisableInputText()
{
	g_enableTextInput = false;
}

std::wstring Input::GetInputText()
{
	return g_inputText;
}

glm::vec2 Input::GetMousePosition()
{
	return g_mousePosition;
}

bool Input::GetKey(KeyCode code)
{
	return g_keys[static_cast<int>(code)];
}

bool Input::IsInputTextEnable()
{
	return g_enableTextInput;
}

bool Engine::Initialize(int w, int h, std::string title)
{

	DEBUG_LOG("Initialize Engine");

	if (!glfwInit())
	{
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

	if (g_window == nullptr)
	{
		DEBUG_ERROR("Failed created window.");
		glfwTerminate();
		return ENGINE_ERROR;
	}

	glfwMakeContextCurrent(g_window);

	// Initialize glew
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		DEBUG_ERROR("Failed Initialize glew.");
		glfwTerminate();
		return ENGINE_ERROR;
	}

	// Initialize Input
	g_keys = new bool[MAX_KEY];
	g_mouseButton = new bool[MAX_MOUSE_BUTTON];

	ClearInput();

	// Initialize Input Callbaks
	glfwSetCharCallback(g_window, InputCharacterCallBack);
	glfwSetKeyCallback(g_window, InputKeyCallBack);
	glfwSetCursorPosCallback(g_window, InputMousePositionCallBack);
	glfwSetCursorEnterCallback(g_window, InputMouseEnterCallBack);
	glfwSetMouseButtonCallback(g_window, InpuMouseButtonCallBack);
	glfwSetScrollCallback(g_window, InputMouseScrollCallBack);

	return !ENGINE_ERROR;
}

void Engine::Run()
{
	do
	{
		glfwSwapBuffers(g_window);
		glfwPollEvents();

	} while (glfwWindowShouldClose(g_window) == 0);

	Release();
}

void Engine::Release()
{

	Memory::DeleteArray(g_keys);
	Memory::DeleteArray(g_mouseButton);

	glfwTerminate();
}
