#ifndef SHAPE_H
#define SHAPE_H
#include "transform.h"
#include "ray.h"
class Intersection;

class Shape
{
public:
    Shape();
    virtual bool getIntersection(Ray ray, Intersection *intersect) const; // purely virtual
    Shape(Transform transform);
    ~Shape();

    Transform objTransform;
};

#endif // SHAPE_H
