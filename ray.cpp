#include "ray.h"

Ray::Ray()
{

}

Ray Ray::transformRay(glm::mat4 transform_matrix) {
glm::vec4 origin_vec4(this->origin, 1.0);
glm::vec4 direction_vec4(this->direction, 0.0);
glm::vec4 transformed_origin(origin_vec4 * transform_matrix);
glm::vec4 transformed_direction(direction_vec4 * transform_matrix);
Ray result;
result.origin.x = transformed_origin.x;
result.origin.y = transformed_origin.y;
result.origin.z = transformed_origin.z;
result.direction.x = transformed_direction.x;
result.direction.y = transformed_direction.y;
result.direction.z = transformed_direction.z;
return result;
}
