#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include "vec3d.h"
#include "primitives.h"

class MyLight {
public:
    Vec3d position;
    Vec3d color;

    void set_position(const double &, const double &, const double &);

    void set_color(const double &, const double &, const double &);

    Vec3d phong_shading(const Ray&, const MyVertex&);
};

#endif
