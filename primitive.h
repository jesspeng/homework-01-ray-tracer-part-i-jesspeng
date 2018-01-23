#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "QString.h"
#include "shape.h"
class Intersection;

class Primitive
{
public:
    Primitive();
QString name;
std::shared_ptr<const Shape> surface;
bool getIntersection(Ray ray, Intersection *intersect) const;//implement this

};

#endif // PRIMITIVE_H
