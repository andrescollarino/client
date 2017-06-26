#pragma once

#include <GL/glew.h>

#include "Color.h"
#include "Memory.h"
#include "Bounds.h"
/*
class IRenderer
{
    public:

    IRenderer();
    virtual ~IRenderer();

    protected:

    Bounds* m_bounds;
};*/


namespace RenderManager
{
bool Initialize();
void Draw();
void Release();
};