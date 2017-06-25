#pragma once

namespace GameObjectManager
{
void Initialize();
void Add(void *gameObject);
void Remove(void *gameObject);
void Update(float deltaTime);
void LateUpdate(float deltaTime);
void Refresh();
void Release();
};