#pragma once

#include <vector>

#include "Memory.h"
#include "Transform.h"

namespace GameObjectManager
{
void Initialize();
void Add(void *gameObject);
void Remove(void *gameObject);
void Update(float deltaTime);
void LateUpdate(float deltaTime);
void Release();
};

class GameObject
{
  public:

    static void Destroy(GameObject *&gameObject)
    {
        GameObjectManager::Remove(gameObject);
        Memory::Delete(gameObject);
    };

    template <class T>
    static T *Instantiate()
    {
        T *tmp = new T();

        GameObjectManager::Add(tmp);

        return tmp;
    };

  public:
    GameObject();
    virtual ~GameObject();

    glm::vec3 Position() const;
    glm::quat Rotation() const;
    glm::vec3 Euler() const;
    glm::vec3 Scale() const;

    // Callbacks
    virtual void Update(float deltaTime);
    virtual void LateUpdate(float deltaTime);
    virtual void OnRelease();

  protected:
    Transform *m_transform;

  private:
};