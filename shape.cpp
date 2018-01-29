#include "shape.h"
#include "ray.h"
Shape::Shape()
{

}

Shape::Shape(Transform transform)
{
    this->objTransform = transform;
}

bool Shape::getIntersection(Ray ray, Intersection *intersect) const
{
return false;
}

Shape::~Shape()
{

}

