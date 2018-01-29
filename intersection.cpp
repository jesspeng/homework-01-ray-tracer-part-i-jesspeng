#include "intersection.h"
#include "primitive.h"
#include "globalincludes.h"

Intersection::Intersection(Point3f intersectPoint, Normal3f normal, float t, Primitive surface)
{
    this->point = intersectPoint;
    this->normal = normal;
    this->t = t;
    *this->objectHit = surface;
}

Point3f Intersection::getPoint()
{
    return this->point;
}

Normal3f Intersection::getNormal()
{
    return this->normal;
}

float Intersection::getT()
{
    return this->t;
}

std::shared_ptr<Primitive> Intersection::getObject()
{
    return this->objectHit;
}
