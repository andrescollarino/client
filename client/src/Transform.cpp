#include "Transform.h"

Transform::Transform()
{
    m_position = glm::vec3(0, 0, 0);
    m_rotation = glm::quat();
    m_scale = glm::vec3(1, 1, 1);

    UpdateMatrix();
}

Transform::Transform(const glm::vec3 &position, const glm::quat &rotation, const glm::vec3 &scale)
{
    SetPositionAndRotationAndScale(position, rotation, scale);
}

Transform::Transform(const Transform &transform)
{
    m_position = transform.m_position;
    m_rotation = transform.m_rotation;
    m_scale = transform.m_scale;

    UpdateMatrix();
}

glm::vec3 Transform::Position() const
{
    return m_position;
}

glm::quat Transform::Rotation() const
{
    return m_rotation;
}

glm::vec3 Transform::Euler() const
{
    return glm::eulerAngles(m_rotation);
}

glm::vec3 Transform::Scale() const
{
    return m_scale;
}

glm::mat4 Transform::Matrix() const
{
    return m_matrix;
}

void Transform::SetPosition(const glm::vec3 &position)
{
    m_position = position;
    UpdateMatrix();
}

void Transform::SetRotation(const glm::quat &rotation)
{
    m_rotation = rotation;
    UpdateMatrix();
}

void Transform::SetEulerAngles(const glm::vec3 &rotation)
{
    m_rotation = glm::quat(rotation);
    UpdateMatrix();
}

void Transform::SetScale(const glm::vec3 &scale)
{
    m_scale = scale;
    UpdateMatrix();
}

void Transform::SetPositionAndRotation(const glm::vec3 &position, const glm::quat &rotation)
{
    m_position = position;
    m_rotation = rotation;
    UpdateMatrix();
}

void Transform::SetPositionAndRotationAndScale(const glm::vec3 &position, const glm::quat &rotation, const glm::vec3 &scale)
{
    m_position = position;
    m_rotation = rotation;
    m_scale = scale;
    UpdateMatrix();
}

void Transform::UpdateMatrix()
{
    m_matrix = glm::translate(m_position) * glm::toMat4(m_rotation) * glm::scale(m_scale);
}