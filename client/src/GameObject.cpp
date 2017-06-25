#include "GameObject.h"
namespace
{
std::vector<GameObject *> *g_gameObjecs = nullptr;
}

void GameObjectManager::Initialize()
{
    g_gameObjecs = new std::vector<GameObject *>();
}

void GameObjectManager::Add(void *gameObject)
{
    g_gameObjecs->push_back(static_cast<GameObject *>(gameObject));
}

void GameObjectManager::Remove(void *gameObject)
{
    auto tmp = g_gameObjecs->begin();
    auto t = static_cast<GameObject *>(gameObject);
    auto index = 0;
    for (auto g : *g_gameObjecs)
    {
        if (g == t)
            break;

        index;
    }

    g_gameObjecs->erase(tmp);
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

void GameObjectManager::Release()
{
    Memory::Delete(g_gameObjecs);
}

GameObject::GameObject()
{
    m_transform = new Transform();
}

GameObject::~GameObject()
{
    OnRelease();
    Memory::Delete(m_transform);
}

glm::vec3 GameObject::Position() const
{
    return m_transform->Position();
}

glm::quat GameObject::Rotation() const
{
    return m_transform->Rotation();
}

glm::vec3 GameObject::Euler() const
{
    return m_transform->Euler();
}

glm::vec3 GameObject::Scale() const
{
    return m_transform->Scale();
}

// Callbacks
void GameObject::Update(float deltaTime)
{
}

void GameObject::LateUpdate(float deltaTime)
{
}

void GameObject::OnRelease()
{
}