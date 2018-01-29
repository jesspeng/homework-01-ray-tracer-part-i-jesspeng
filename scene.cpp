#include "scene.h"

Scene::Scene(QList<std::shared_ptr<Primitive>> primitives, Camera cam)
{
this->primitives = primitives;
this->cam = cam;
}

bool Scene::getIntersection(Ray ray, Intersection *intersect) const
{
    //intersection with smallest non-negative t value

    return false;
}
