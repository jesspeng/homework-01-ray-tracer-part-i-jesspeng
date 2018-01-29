#include "primitive.h"
#include "ray.h"
#include "intersection.h"


Primitive::Primitive(QString name, std::shared_ptr<Shape> surface)
{
    this->name = name;
    this->surface = surface;
}

bool Primitive::getIntersection(Ray ray, Intersection *intersect) const
{
    //returns whether or not an intersection with the primitive's shape occurred at all
    // if there was an intersection, set the Intersection's pointer to a primitive to this

   // intersect->objectHit = *this;

    return false;


}
