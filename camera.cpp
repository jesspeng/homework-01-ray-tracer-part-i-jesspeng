#include "camera.h"

Camera::Camera()
{

}

Camera::Camera(float eye_x, float eye_y, float eye_z, float ref_x, float ref_y, float ref_z,
               float up_x, float up_y, float up_z, float fov, float width, float height,
               float near, float far)
{
    this->eye_x = eye_x;
    this->eye_y = eye_y;
    this->eye_z = eye_z;
    this->ref_x = ref_x;
    this->ref_y = ref_y;
    this->ref_z = ref_z;
    this->up_x = up_x;
    this->up_y = up_y;
    this->up_z = up_z;
    this->fov = fov;
    this->width = width;
    this->height = height;
    this->near = near;
    this->far = far;
}

Ray Camera::rayCast(float px, float py) {
   // compute view matrix
    //glm::mat4 ViewMatrix = glm::transpose(Camera::compute_viewMatrix());
    glm::mat4 ViewMatrix = compute_viewMatrix();
   float sx = (2.f * px/this->width) - 1.0f;
   float sy = 1.0f - (2.f * py/this->height);

   glm::vec4 eye = glm::vec4(this->eye_x, this->eye_y, this->eye_z, 1);
   float t = 5.f;

   glm::vec4 ref = eye + t * ViewMatrix[2];
   float len =  (float)glm::length(ref - eye);
   float alpha = this->fov / 2.0;
   float radians = tanf(alpha * M_PI / 180.0);
   glm::vec4 V = ViewMatrix[1] * len * radians;
   glm::vec4 H = ViewMatrix[0] * len * (this->width/this->height) * radians;
   glm::vec4 p = ref + (sx * H) + (sy * V);

   glm::vec4 ray_origin = eye;
   glm::vec4 ray_direction = glm::vec4(glm::normalize(glm::vec3(p) - glm::vec3(eye)), 0);

   Ray result;
   result.origin.x = ray_origin.x;
   result.origin.y = ray_origin.y;
   result.origin.z = ray_origin.z;

   result.direction.x = ray_direction.x;
   result.direction.y = ray_direction.y;
   result.direction.z = ray_direction.z;
   return result;
}

glm::mat4 Camera::compute_viewMatrix()
{
    glm::vec3 F = glm::vec3(this->ref_x - this->eye_x,
                            this->ref_y - this->eye_y,
                            this->ref_z - this->eye_z);
    glm::vec3 normF = glm::normalize(F);
    glm::vec3 UP = glm::vec3(this->up_x, this->up_y, this->up_z);
    glm::vec3 normUP = glm::normalize(UP);

    // compute cross product
    glm::vec3 right = glm::normalize(glm::cross(normF, normUP));
    glm::vec3 u = glm::normalize(glm::cross(right, normF));

    // construct orientation matrix
    glm::vec4 col1 = glm::vec4(right[0], u[0], normF[0], 0);
    glm::vec4 col2 = glm::vec4(right[1], u[1], normF[1], 0);
    glm::vec4 col3 = glm::vec4(right[2], u[2], normF[2], 0);
    glm::vec4 col4 = glm::vec4(0, 0, 0, 1);
    glm::mat4 Orientation_Matrix = glm::mat4(col1, col2, col3, col4);

    // construct translation matrix
    glm::vec4 c1 = glm::vec4(1, 0, 0, 0);
    glm::vec4 c2 = glm::vec4(0, 1, 0, 0);
    glm::vec4 c3 = glm::vec4(0, 0, 1, 0);
    glm::vec4 c4 = glm::vec4(-this->eye_x, -this->eye_y, -this->eye_z, 1.f);
    glm::mat4 Translation_Matrix = glm::mat4(c1, c2, c3, c4);
    glm::mat4 ViewMatrix = Translation_Matrix * Orientation_Matrix;
    this->ViewMatrix = ViewMatrix;
    return ViewMatrix;
}

glm::mat4 Camera::compute_projMatrix()
{
float A = this->width / this->height;
float firstval = A * tanf(this->fov / 2);
float secondval = tanf(this->fov / 2);
glm::vec4 c1 = glm::vec4(1/firstval, 0, 0, 0);
glm::vec4 c2 = glm::vec4(0, 1/secondval, 0, 0);
glm::vec4 c3 = glm::vec4(0, 0, this->far / (this->far - this->near), 0);
glm::vec4 c4 = glm::vec4(0, 0, (-this->far * this->near) / (this->far - this->near), 0);
glm::mat4 projMatrix = glm::mat4(c1, c2, c3, c4);
this->ProjectionMatrix = projMatrix;
return projMatrix;
}

glm::mat4 Camera::compute_projMatrixInverse()
{
    return glm::inverse(this->ProjectionMatrix);
}

glm::mat4 Camera::compute_viewMatrixInverse()
{
    return glm::inverse(this->ViewMatrix);
}
