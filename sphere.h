#ifndef SPHERE_H
#define SPHERE_H
#include "QList"
//#include "camera.h"
#include "intersection.h"
#include "ray.h"
#include "shape.h"
#include "globalincludes.h"

class Sphere : public Shape
{
public:
    Sphere();
    bool getIntersection(Ray ray, Intersection * intersect) const;
    glm::mat4 getTransformMatrix() const;
    float getT();

    glm::mat4 transform_matrix;
    glm::vec3 origin;
    float radius;
    float t;
};

#endif // SPHERE_H
