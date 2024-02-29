#include <cassert>
#include <cmath>
#include "vec3d.h"
#include "light.h"
#include "primitives.h"


void MyLight::set_color(const double& x, const double &y, const double &z) {
    this->color = Vec3d(x, y, z);
}


void MyLight::set_position(const double& x, const double &y, const double &z) {
    this->position = Vec3d(x, y, z);
}


Vec3d MyLight::phong_shading(const Ray& ray, const MyVertex& vertex) {
    Vec3d color(0, 0, 0); 
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Calculate the color of the ray, intersected at the input vertex using Phong illumination model
     *
     * Hints:
     * - Check the README file for the formula.
     * - For debugging, try to disable either specular or diffuse first to make sure the other one works.
     *
     */

    return color;
}
