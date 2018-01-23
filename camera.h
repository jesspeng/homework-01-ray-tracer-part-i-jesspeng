#ifndef CAMERA_H
#define CAMERA_H
#include "ray.h"
#include "globalincludes.h"

class Camera
{
public:
    Camera();
    Camera(float eye_x, float eye_y, float eye_z, float ref_x, float ref_y, float ref_z,
           float up_x, float up_y, float up_z, float fov, float width, float height,
           float near, float far);

    Ray rayCast(float px, float py);
    // takes in pixel coord and returns a Ray in world space that corresponds
                                       // to the input pixel

    glm::mat4 ViewMatrix;
    glm::mat4 ProjectionMatrix;

    glm::mat4 InverseViewMatrix;
    glm::mat4 InverseProjMatrix;

    glm::mat4 compute_viewMatrix();
    glm::mat4 compute_projMatrix();

    glm::mat4 compute_viewMatrixInverse();
    glm::mat4 compute_projMatrixInverse();

    float near, far;
    float eye_x, eye_y, eye_z;
    float up_x, up_y, up_z;
    float fov;
    float width, height;
    float ref_x, ref_y, ref_z;


};

#endif // CAMERA_H
