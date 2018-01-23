#ifndef SPHERE_H
#define SPHERE_H
#include "QList"
//#include "camera.h"
//#include "intersection.h"

class Sphere
{
public:
    Sphere();
    //bool getIntersection(Ray ray, Intersection * intersect) const;

//QList std::shared_ptr<const Primitive> primitives;
//Camera cam;
};
/*public:
    Sphere(QString name, glm::mat4 transform_mat, Material material, QString type);
    ~Sphere();

    Intersection getIntersection(ray inputRay);

    glm::mat4 computeTextureToObjectMatrix();

//    Material getMaterial();
private:
   // glm::mat4 transform_mat;
   // QString name;
   // Material material;
};*/

#endif // SPHERE_H
