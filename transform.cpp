#include "transform.h"

Transform::Transform()
{
this->transXYZ = glm::vec3(0, 0, 0);
this->rotXYZ = glm::vec3(0, 0, 0);
this->scaleXYZ = glm::vec3(1, 1, 1);

}

Transform::Transform(glm::vec3 t, glm::vec3 r, glm::vec3 s)
{
this->transXYZ = t;
this->rotXYZ = r;
this->scaleXYZ = s;
glm::vec3 x_axis = glm::vec3(1, 0, 0);
glm::vec3 y_axis = glm::vec3(0, 1, 0);
glm::vec3 z_axis = glm::vec3(0, 0, 1);
glm::vec4 col1 = glm::vec4(1, 0, 0, 0);
glm::vec4 col2 = glm::vec4(0, 1, 0, 0);
glm::vec4 col3 = glm::vec4(0, 0, 1, 0);
glm::vec4 col4 = glm::vec4(0, 0, 0, 1);
glm::mat4 identityMatrix = glm::mat4(col1, col2, col3, col4);
this->worldTransform = glm::translate(identityMatrix, t) * glm::rotate(identityMatrix, r.x, x_axis) *
                       glm::rotate(identityMatrix, r.y, y_axis) * glm::rotate(identityMatrix, r.z, z_axis) *
                        glm::scale(identityMatrix, s);
this->worldTransformInverse = glm::inverse(worldTransform);
this->worldTransformTranspose = (glm::mat3) glm::transpose(worldTransformInverse);
}


