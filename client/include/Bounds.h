#pragma once

#include <glm/glm.hpp>

class Bounds
{
public:

    Bounds();
    Bounds(const glm::vec3& center,float radio);
    Bounds(const Bounds& bounds);

    bool Contain(const glm::vec3& point) const;

    bool Intersect(const Bounds& bounds) const;
    bool Intersect(const glm::vec3& center,float radio) const;

    float Radio() const;
    glm::vec3 Center() const;

    void SetRadio(float radio);
    void SetCenter(const glm::vec3& center);
    void Set(const glm::vec3& center,float radio);
    
private:

    float m_radio;
    glm::vec3 m_center;
};