#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "matrix.h"
#include "primitives.h"
#include "vec3d.h"

class Camera {
private:
    const double FOV_DEGREES = 60;

    Matrix cam2world_rotation;
    Vec3d cam2world_translation;
    Matrix intrinsics, inv_intrinsics;

public:
    Camera();

    void lookat(const Vec3d&, const Vec3d&, const Vec3d&);

    std::vector<Ray> shoot_rays(const size_t&, const size_t&);
};

#endif
