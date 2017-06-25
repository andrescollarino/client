#pragma once

#include <GL/glew.h>

#include "Color.h"
#include "Memory.h"

/*
class IRenderer
{
    public:

    IRenderer();
    virtual ~IRenderer();

};*/


namespace RenderManager
{
bool Initialize();
void Draw();
void Release();
};