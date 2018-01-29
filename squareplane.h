#ifndef SQUAREPLANE_H
#define SQUAREPLANE_H
#include "shape.h"
#include "globalincludes.h"

class SquarePlane : public Shape
{
public:
    SquarePlane();
    glm::mat4 getTransformMatrix() const;
    bool getIntersection(Ray ray, Intersection *intersect) const;

    Point3f origin;
    float side_length;
    Normal3f normal;
    glm::mat4 transform_matrix;

};

#endif // SQUAREPLANE_H
