#ifndef MY_PRIMITIVES_H_INCLUDED
#define MY_PRIMITIVES_H_INCLUDED

#include <ctime>
#include <string>
#include <vector>
#include "vec3d.h"


class MyVertex {
public:
    Vec3d position;
    Vec3d color_diffuse;
    Vec3d color_specular;
    Vec3d normal;
    double shininess;
    
    MyVertex();

    MyVertex(const Vec3d&, const Vec3d&, const Vec3d&, const Vec3d&, const double&);

    void set_position(const double&, const double&, const double&);

    void set_diffuse(const double&, const double&, const double&);

    void set_specular(const double&, const double&, const double&);

    void set_normal(const double&, const double&, const double&);

    void set_shininess(const double&);
};


class MyTriangle {
private:
    inline static const double _EPS = 1e-6;

public:
    std::vector<MyVertex> vertices;   

    void add_vertex(const MyVertex&);

    Vec3d get_barycentric_coordinate(Vec3d) const;

    MyVertex get_vertex_illumination(const Vec3d&) const;
};


class MySphere {
public:
    Vec3d position;
    double radius;
    Vec3d color_diffuse;
    Vec3d color_specular;
    double shininess;

    void set_position(const double&, const double&, const double&);

    void set_radius(const double&);

    void set_diffuse(const double&, const double&, const double&);

    void set_specular(const double&, const double&, const double&);

    void set_shininess(const double&);
};


class Ray {
private:
    const double _EPS = 1e-6;
public:
    Vec3d origin;
    Vec3d direction;

    Ray();
    Ray(const Vec3d &origin, const Vec3d &direction): origin(origin), direction(direction) {}

    double get_sphere_intersection(const MySphere&) const;

    double get_triangle_intersection(const MyTriangle&) const;
};


#endif
