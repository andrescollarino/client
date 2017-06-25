#include "RenderManager.h"

namespace
{

};

bool RenderManager::Initialize()
{
    glClearColor(0.19f, 0.3f, 0.5f, 1.0f); // blue
    glClearDepth(1.0f);   
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL); 
    glFrontFace(GL_CW);

    return false;
}

void RenderManager::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Culling

    // Render
}

void RenderManager::Release()
{

}
