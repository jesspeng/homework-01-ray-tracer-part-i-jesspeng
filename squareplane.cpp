#include "squareplane.h"

SquarePlane::SquarePlane()
{

}
/*
 * SquarePlane::SquarePlane(QString name, glm::mat4 transform_mat, Material material, QString type) : Geometry()
{
    //this->transform_mat = transform_mat;
    this->setMat(transform_mat);
    //this->name = name;
    //this->material = material;
    this->setMaterial(material);
    this->setName(name);
    this->setType(type);
}

//Material SquarePlane::getMaterial() {
//    return this->material;
//}

Intersection SquarePlane::getIntersection(ray inputRay) {
    float t;
    glm::vec4 p;
    glm::vec4 normal;

    glm::mat4 tmat = *this->getTransformMat();
    glm::mat4 invMat = glm::inverse(tmat);
    ray transformedRay = inputRay.getTransformedCopy(invMat);

    glm::vec4 plane_normal = glm::vec4(0, 0, 1, 0);
    t = (glm::dot(plane_normal, (-1.f  * transformedRay.getOrigin()))/
         (glm::dot(plane_normal, transformedRay.getDirection())));
    p = transformedRay.getOrigin() + t * transformedRay.getDirection();
    normal = plane_normal;

//    //calculate normal at intersection point p
//    float px = p[0];
//    float py = p[1];
//    float pz = p[2];
//    float max = -INFINITY;
//    if (fabs(px) > max) {
//        max = px;
//    }
//    if (fabs(py) > max) {
//        max = py;
//    }
//    if (fabs(pz) > max) {
//        max = pz;
//    }

//    if (max == px) {
//        normal = glm::vec4(1, 0, 0, 0);
//    }
//    else if (max == py) {
//        normal = glm::vec4(0, 1, 0, 0);
//    }
//    if (max == pz) { // should this be pz?
//        normal = glm::vec4(0, 0, 1, 0);
//    }

    //if point is not within boundaries of our square plane, there is no intersection
    if (p.operator [](0) < -.5 || p.operator [](1) < -.5 || p.operator [](0) > .5 || p.operator [](1) > .5) {
        return Intersection(glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), -1, this);
    }


    //convert p and normal to world space
    glm::mat4 inverse = glm::inverse(*this->getTransformMat());
    glm::mat4 inverse_transpose = glm::transpose(inverse);

    p = p * inverse;
    normal = normal * inverse_transpose;

    return Intersection(p, glm::normalize(normal), t, this);
}

glm::mat4 SquarePlane::computeTextureToObjectMatrix() {

}
*/
