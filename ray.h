#ifndef RAY_H
#define RAY_H
#include "globalincludes.h"

class Ray
{
public:
    Ray();
    Ray transformRay(glm::mat4 transform_matrix);
    void setOriginValues(Point3f origin);
    void setDirectionValues(Vector3f direction);

    Point3f origin;
    Vector3f direction;
};

#endif // RAY_H
