#ifndef SHAPE_H
#define SHAPE_H
#include "transform.h"
#include "ray.h"
#include "globalincludes.h"
class Intersection;

class Shape
{
public:
    Shape();
    //virtual bool getIntersection(Ray ray, Intersection *intersect) const; // purely virtual
    Shape(Transform transform);
    virtual ~Shape();
    Transform objTransform;
};

#endif // SHAPE_H
