#ifndef RAY_H
#define RAY_H
#include "globalincludes.h"

class Ray
{
public:
    Ray();
    Ray(Point3f origin, Vector3f direction);
    Ray* transformRay(glm::mat4 transform_matrix);

    Point3f origin;
    Vector3f direction;
};

#endif // RAY_H
