#include "intersection.h"

Intersection::Intersection()
{

}

/*Intersection::Intersection(Point3f intersectPoint, Normal3f normal, float t, Primitive *surface)
{
    this->point = intersectPoint;
    this->normal = normal;
    this->t = t;

}*/

float Intersection::get_t() {
    return this->t;
}


Normal3f Intersection::get_surfaceNormal() {
    return this->normal;
}


Point3f Intersection::get_intersection() {
    return this->point;
}


