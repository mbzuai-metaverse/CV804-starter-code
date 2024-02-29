#include <cassert>
#include <stdexcept>
#include <cmath>
#include "primitives.h"
#include "vec3d.h"


MyVertex::MyVertex() {}


MyVertex::MyVertex(
    const Vec3d& position,
    const Vec3d& color_diffuse,
    const Vec3d& color_specular,
    const Vec3d& normal, const double& shininess):
        position(position), color_diffuse(color_diffuse),
        color_specular(color_specular), normal(normal), shininess(shininess) {
    }


void MyVertex::set_position(const double &x, const double &y, const double &z) {
    this->position = Vec3d(x, y, z);
}


void MyVertex::set_diffuse(const double &x, const double &y, const double &z) {
    this->color_diffuse = Vec3d(x, y, z);
}


void MyVertex::set_specular(const double &x, const double &y, const double &z) {
    this->color_specular = Vec3d(x, y, z);
}


void MyVertex::set_normal(const double &x, const double &y, const double &z) {
    this->normal = Vec3d(x, y, z).normalize();
}


void MyVertex::set_shininess(const double &shi) {
    this->shininess = shi;
}


void MyTriangle::add_vertex(const MyVertex &vertex) {
    if (this->vertices.size() >= 3) {
        throw std::invalid_argument("Number of vertices exceeded 3");
    }
    this->vertices.push_back(vertex);
}


void MySphere::set_position(const double &x, const double &y, const double &z) {
    this->position = Vec3d(x, y, z);
}


void MySphere::set_diffuse(const double &x, const double &y, const double &z) {
    this->color_diffuse = Vec3d(x, y, z);
}


void MySphere::set_specular(const double &x, const double &y, const double &z) {
    this->color_specular = Vec3d(x, y, z);
}


void MySphere::set_radius(const double &rad) {
    this->radius = rad;
}


void MySphere::set_shininess(const double &shi) {
    this->shininess = shi;
}


double Ray::get_sphere_intersection(const MySphere &sphere) const {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * This function calculates the closest intersection of the ray with the input sphere 
     *
     * Hints:
     * - If the ray does not intersect with the sphere, return a special value, for example t = -1
     * - You can use C++ reference variable to make the code cleaner
     */

    return -1;
}


Vec3d MyTriangle::get_barycentric_coordinate(Vec3d P) const {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Calculate the barycentric coordinate of P with respect to the triangle.
     *
     * Hints:
     * - Use cross product to calculate triangle areas.
     * - This one can be used for triangle interpolation and check if a point is inside a triangle or not.
     */

    return Vec3d(0, 0, 0);
}


MyVertex MyTriangle::get_vertex_illumination(const Vec3d& position) const {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Use Barycentric coordinates to interpolate the normal, diffuse, specular, etc of the given position based on the three vertices of the triangle.
     *
     * Hints:
     * - If you use Vec3d operators, the code will be super clean and short.
     */

    return MyVertex();
}


double Ray::get_triangle_intersection(const MyTriangle &triangle) const {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * This function calculates the closest intersection of the ray with the input triangle
     *
     * Hints:
     * - If the ray does not intersect with the triangle, return a special value, for example t = -1
     * - You can use C++ reference variable to make the code cleaner
     */
    const Vec3d& A = triangle.vertices[0].position;
    const Vec3d& B = triangle.vertices[1].position;
    const Vec3d& C = triangle.vertices[2].position;

    return -1;
}
