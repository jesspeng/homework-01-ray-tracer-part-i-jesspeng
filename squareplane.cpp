#include "squareplane.h"
#include "globalincludes.h"
#include "intersection.h"

SquarePlane::SquarePlane()
{
    this->origin = Point3f(0, 0, 0);
    this->side_length = 1.0;
    this->normal = Normal3f(0, 0, 1);
}

glm::mat4 SquarePlane::getTransformMatrix() const
{
    return this->transform_matrix;
}

bool SquarePlane::getIntersection(Ray ray, Intersection *intersect) const
{
    float t;
    Point3f p;
    Normal3f normal;

    glm::mat4 transform_matrix = this->getTransformMatrix();
    glm::mat4 inverseMatrix = glm::inverse(transform_matrix);
    glm::vec4 new_origin = (glm::vec4) (ray.origin, 0) * inverseMatrix;
    glm::vec4 new_direction = (glm::vec4) (ray.direction, 0) * inverseMatrix;
    Ray *transformedRay = new Ray((Point3f) new_origin, (Vector3f) new_direction);

    glm::vec4 plane_normal = glm::vec4(0, 0, 1, 0);
    t = (glm::dot(plane_normal, (glm::vec4)(-1.f  * transformedRay->origin, 0))/
         (glm::dot((glm::vec3) plane_normal, transformedRay->direction)));
    p = transformedRay->origin + t * transformedRay->direction;
    normal = (Normal3f) plane_normal;

   //calculate normal at intersection point p
    float px = p[0];
    float py = p[1];
    float pz = p[2];
    float max = -INFINITY;
    if (fabs(px) > max) {
        max = px;
    }
    if (fabs(py) > max) {
        max = py;
    }
    if (fabs(pz) > max) {
        max = pz;
    }

    if (max == px) {
       normal = Normal3f(1, 0, 0);
    }
   else if (max == py) {
       normal = Normal3f(0, 1, 0);
    }
    if (max == pz) { // should this be pz?
       normal = Normal3f(0, 0, 1);
    }

    //if point is not within boundaries of our square plane, there is no intersection
    if (p[0] < -0.5 || p[1] < -0.5 || p[0] > 0.5 || p[1] > 0.5) {
        Point3f zeroPoint(0, 0, 0);
        Normal3f zeroNormal(0, 0, 0);
        intersect->normal = zeroNormal;
        intersect->point = zeroPoint;
        intersect->t = -1.0;
        //return Intersection(glm::vec4(0, 0, 0, 0), glm::vec4(0, 0, 0, 0), -1, this);
        return false;
    }
    //convert p and normal to world space
    glm::mat4 inverse = glm::inverse(this->getTransformMatrix());
    glm::mat4 inverse_transpose = glm::transpose(inverse);

    glm::vec4 temp_p = (glm::vec4) (p, 0) * inverse;
    glm::vec4 temp_normal = (glm::vec4) (normal, 0) * inverse_transpose;

    intersect->normal = (Normal3f) glm::normalize(temp_normal);
    intersect->point = (Point3f) temp_p;
    intersect->t = t;
    //return Intersection(p, glm::normalize(normal), t, this);
    return true;
}

