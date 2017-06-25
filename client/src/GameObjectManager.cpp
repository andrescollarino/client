#include "GameObjectManager.h"

#include <vector>

#include "GameObject.h"

namespace
{
std::vector<GameObject *> *g_gameObjecs = nullptr;

std::vector<GameObject *> *g_newGameObjecs = nullptr;
std::vector<GameObject *> *g_destroyGameObjects = nullptr;
}

namespace
{

void InternalDestroy(GameObject *gameObject)
{
    auto index = 0;
    for (auto g : *g_gameObjecs)
    {
        if (g == gameObject)
        {
            Memory::Delete(g);
            break;
        }

        index++;
    }

    g_gameObjecs->erase(g_gameObjecs->begin() + index);
}
};

void GameObjectManager::Initialize()
{
    g_gameObjecs = new std::vector<GameObject *>();
    g_newGameObjecs = new std::vector<GameObject *>();
    g_destroyGameObjects = new std::vector<GameObject *>();
}

void GameObjectManager::Add(void *gameObject)
{
    g_newGameObjecs->push_back(static_cast<GameObject *>(gameObject));
}

void GameObjectManager::Remove(void *gameObject)
{
    g_destroyGameObjects->push_back(static_cast<GameObject *>(gameObject));
}

void GameObjectManager::Update(float deltaTime)
{
    for (auto g : *g_gameObjecs)
        g->Update(deltaTime);
}

void GameObjectManager::LateUpdate(float deltaTime)
{
    for (auto g : *g_gameObjecs)
        g->LateUpdate(deltaTime);
}

void GameObjectManager::Refresh()
{
     // Add New GameObject
    if (g_newGameObjecs->size() != 0)
    {
        for (auto n : *g_newGameObjecs)
            g_gameObjecs->push_back(n);

        g_newGameObjecs->clear();
    }

    // Destroy Pending GameObjects
    if (g_destroyGameObjects->size() != 0)
    {
        for (auto d : *g_destroyGameObjects)
            InternalDestroy(d);

        g_destroyGameObjects->clear();
    }
}

void GameObjectManager::Release()
{
    Memory::Delete(g_newGameObjecs);
    Memory::Delete(g_destroyGameObjects);
    Memory::Delete(g_gameObjecs);
}