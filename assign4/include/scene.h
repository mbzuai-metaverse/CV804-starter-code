#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <cstdint>
#include "vec3d.h"
#include "primitives.h"
#include "camera.h"
#include "light.h"


class Scene {
public:
    const Vec3d BACKGROUND_COLOR = Vec3d(1.0, 1.0, 1.0);
    const double _EPS = 1e-6;

    MyLight ambient_light;
    std::vector<MyTriangle> all_triangles;
    std::vector<MySphere> all_spheres;
    std::vector<MyLight> all_lights;
    Camera camera;

    MyVertex get_ray_intersection(const Ray &);

    Vec3d get_ray_color(const Ray &);

    uint8_t unnormalize_color(const double&);

    void render(const size_t &, const size_t &, const std::string&);
};

#endif
