#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "globalincludes.h"
class Primitive;

class Intersection
{
public:
    Intersection();
    //Intersection(Point3f intersectPoint, Normal3f normal, float t, Primitive *surface);
    float get_t();
    Normal3f get_surfaceNormal();
    Point3f get_intersection();

    Point3f point; // point on surface (in world space) at which the intersection occurred
    Normal3f normal; // surface normal at point of intersection (world space)
    float t; //distance along ray
    //std::shared_ptr<const Primitive> objectHit; // pointer to the primitive whose surface we are
        // intersecting

};

#endif // INTERSECTION_H
