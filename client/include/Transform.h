#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp> 

class Transform
{
    Transform();
    Transform(const glm::vec3 &position, const glm::quat &rotation, const glm::vec3 &scale);
    Transform(const Transform &transform);

    glm::vec3 Position() const;
    glm::quat Rotation() const;
    glm::vec3 Euler() const;
    glm::vec3 Scale() const;

    glm::mat4 Matrix() const;

    void SetPosition(const glm::vec3 &position);
    void SetRotation(const glm::quat &rotation);
    void SetEulerAngles(const glm::vec3 &rotation);

    void SetScale(const glm::vec3 &scale);

    void SetPositionAndRotation(const glm::vec3 &position, const glm::quat &rotation);
    void SetPositionAndRotationAndScale(const glm::vec3 &position, const glm::quat &rotation, const glm::vec3 &scale);

  private:
    void UpdateMatrix();

  private:
    glm::vec3 m_position;
    glm::quat m_rotation;
    glm::vec3 m_scale;
    glm::mat4 m_matrix;
};