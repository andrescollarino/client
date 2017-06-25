#include "Bounds.h"

Bounds::Bounds()
{
    m_center = glm::vec3(0, 0, 0);
    m_radio = 1.0f;
}

Bounds::Bounds(const glm::vec3 &center, float radio)
{
    m_center = center;
    m_radio = radio;
}

Bounds::Bounds(const Bounds &bounds)
{
    m_center = bounds.m_center;
    m_radio = bounds.m_radio;
}

bool Bounds::Contain(const glm::vec3 &point) const
{
    auto x = point.x - m_center.x;
    auto y = point.y - m_center.y;
    auto z = point.z - m_center.z;

    return x * x + y * y + z * z <= m_radio * m_radio;
}

bool Bounds::Intersect(const Bounds &bounds) const
{
    return Intersect(bounds.m_center , bounds.m_radio);
}

bool Bounds::Intersect(const glm::vec3 &center, float radio) const
{
    auto l = glm::length(center - m_center);

    return l <= radio * 2 && l <= m_radio * 2;
}

float Bounds::Radio() const
{
    return m_radio;
}

glm::vec3 Bounds::Center() const
{
    return m_center;
}

void Bounds::SetRadio(float radio)
{
    m_radio = radio;
}

void Bounds::SetCenter(const glm::vec3 &center)
{
    m_center = center;
}

void Bounds::Set(const glm::vec3 &center, float radio)
{
    m_center = center;
    m_radio = radio;
}