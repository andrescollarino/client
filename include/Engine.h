#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

#include "Debug.h"
#include "Memory.h"

#define ENGINE_ERROR	true

enum class KeyCode
{

};

namespace Input
{

};

namespace Engine
{
	bool Initialize(int w,int h, std::string title);
	void Run();
	void Release();
};
