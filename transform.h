#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "globalincludes.h"

class Transform
{
public:
    Transform();
    Transform(glm::vec3 t, glm::vec3 r, glm::vec3 s);
    glm::vec3 transXYZ;
    glm::vec3 scaleXYZ;
    glm::vec3 rotXYZ;
    glm::mat4 worldTransform;
    glm::mat4 worldTransformInverse;
    glm::mat3 worldTransformTranspose;
};

#endif // TRANSFORM_H
