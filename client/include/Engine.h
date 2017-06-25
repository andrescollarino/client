#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <cwchar>

#include "Debug.h"
#include "Memory.h"
#include "KeyCode.h"
#include "GameObject.h"

#define ENGINE_ERROR true

namespace Time
{
	float Scale();
	void SetScale(float scale);
	
	float DeltaTime();
	float UnscaleDeltaTime();
};

namespace Input
{
void EnableInputText();
void DisableInputText();

std::wstring GetInputText();

glm::vec2 GetMousePosition();

bool GetKey(KeyCode code);

bool IsInputTextEnable();
};

namespace Engine
{
bool Initialize(int w, int h, std::string title);
void Run();
void Release();
};
