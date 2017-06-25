#include "GameObject.h"

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

bool GameObject::IsActive() const
{
    return m_isActive;
}

void GameObject::SetActive(float value)
{
    m_isActive = value;
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