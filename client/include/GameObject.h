#pragma once

#include "Memory.h"
#include "Transform.h"
#include "GameObjectManager.h"

class GameObject
{
  public:

    template <class T>
    static void Destroy(T& gameObject)
    {
        GameObjectManager::Remove(static_cast<GameObject*>(gameObject));
        gameObject = nullptr;
    };

    template <class T>
    static T *Instantiate()
    {
        T *tmp = new T();

        GameObjectManager::Add(static_cast<GameObject*>(tmp));

        return tmp;
    };

  public:
    GameObject();
    virtual ~GameObject();

    glm::vec3 Position() const;
    glm::quat Rotation() const;
    glm::vec3 Euler() const;
    glm::vec3 Scale() const;

    bool IsActive() const;
    void SetActive(float value);

    // Callbacks
    virtual void Update(float deltaTime);
    virtual void LateUpdate(float deltaTime);
    virtual void OnRelease();

  protected:
    Transform *m_transform;
    bool m_isActive;

};