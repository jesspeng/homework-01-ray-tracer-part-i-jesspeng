#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "globalincludes.h"
#include "primitive.h"

class Intersection {
public:
    Intersection(Point3f intersectPoint, Normal3f normal, float t, Primitive surface);

    Point3f point; // point on surface (in world space) at which the intersection occurred
    Normal3f normal; // surface normal at point of intersection (world space)
    float t; //distance along ray
    std::shared_ptr<Primitive> objectHit; // pointer to the primitive whose surface we are
                                            // intersecting
    Point3f getPoint();
    Normal3f getNormal();
    float getT();
    std::shared_ptr<Primitive> getObject();
};

#endif // INTERSECTION_H
