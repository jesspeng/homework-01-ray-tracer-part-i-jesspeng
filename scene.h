#ifndef SCENE_H
#define SCENE_H
#include "QList"
#include "camera.h"
#include "primitive.h"
#include "globalincludes.h"

class Scene
{
public:
    Scene(QList<std::shared_ptr<Primitive>> primitives, Camera cam);
    bool getIntersection(Ray ray, Intersection *intersect) const;

    QList<std::shared_ptr<Primitive>> primitives;
    Camera cam;
};

#endif // SCENE_H
