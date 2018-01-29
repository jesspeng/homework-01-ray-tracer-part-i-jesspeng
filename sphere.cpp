#include "sphere.h"
#include "globalincludes.h"

Sphere::Sphere() : Shape()
{
//The Sphere should have a radius of 0.5 and should be centered at the origin.
this->origin = glm::vec3(0, 0, 0);
this->radius = 0.5;
}

glm::mat4 Sphere::getTransformMatrix() const
{
    return this->transform_matrix;
}

float Sphere::getT()
{
    return this->t;
}

bool Sphere::getIntersection(Ray ray, Intersection *intersect) const {
    float t;
    Point3f p;
    Normal3f normal;
    glm::mat4 inverseMatrix = glm::inverse(this->getTransformMatrix());
    glm::vec4 new_origin = (glm::vec4) (ray.origin, 0) * inverseMatrix;
    glm::vec4 new_direction = (glm::vec4) (ray.direction, 0) * inverseMatrix;
    Ray *transformedRay = new Ray((Point3f) new_origin, (Vector3f) new_direction);

    float x0 = transformedRay->origin[0];
    float y0 = transformedRay->origin[1];
    float z0 = transformedRay->origin[2];

    float xd = transformedRay->direction[0];
    float yd = transformedRay->direction[1];
    float zd = transformedRay->direction[2];

    float A = pow(xd, 2.0) + pow(yd, 2.0) + pow(zd, 2.0);
    float B = 2 * (xd*x0 + yd*y0 + zd*z0);
    float C = pow(x0, 2.0) + pow(y0, 2.0) + pow(z0, 2.0) - 0.25;

    float discriminant = pow(B, 2.0) - (4.0 * A * C);
    if (discriminant < 0) { // discriminant is negative and there is no intersection
        Point3f zeroPoint = Point3f(0, 0, 0);
        Normal3f zeroNormal = Normal3f(0, 0, 0);
        intersect->normal = zeroNormal;
        intersect->point = zeroPoint;
        intersect->t = -1.0;
        //intersect->objectHit
        //*intersect= new Intersection(noPoint, noNormal, -1.0, this);
        return false;
    } else {
        float t0 = ((B * -1.0) - (sqrtf(discriminant)))/(2 * A);
        float t1 = ((B * -1.0) + (sqrtf(discriminant)))/(2 * A);

        if (t0 > 0) {
            if (t0 < t1) {
                t = t0;
                //this->t = t0;
            } else {
                t = t1;
                //this->t = t1;
            }
        } else {
            t = t1;
           //this->t = t1;
        }

        p = (transformedRay->origin) + (t * (transformedRay->direction));
        normal = (Normal3f) glm::normalize(p);
        glm::mat4 inverse = glm::inverse(this->getTransformMatrix());
        glm::mat4 inverse_transpose = glm::transpose(inverse);

        glm::vec4 temp_p = inverse * (glm::vec4) (p, 0);
        glm::vec4 temp_normal = inverse_transpose * (glm::vec4) (normal, 0);
        intersect->normal = (Normal3f) glm::normalize(temp_normal);
        intersect->point = (Point3f) temp_p;
        intersect->t = t;
        //intersect->objectHit->surface = this;
        //Intersection((Point3f) temp_p, (Normal3f) glm::normalize(temp_normal), t, this)
    }
    return true;
}
