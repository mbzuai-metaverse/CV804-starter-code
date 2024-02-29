#include <cmath>
#include "primitives.h"
#include "camera.h"
#include "vec3d.h"


Camera::Camera() {
    lookat(Vec3d(0, 0, 0), Vec3d(0, 0, -1), Vec3d(0, 1, 0));

    // Use a fixed intrinsics matrix
    double focal_length = double(1.0 / (tan(FOV_DEGREES * 3.14159f / 360) * 1.414));
    intrinsics = Matrix(3, 3);

    intrinsics(0, 0) = focal_length;
    intrinsics(0, 1) = 0;
    intrinsics(0, 2) = 0;

    intrinsics(1, 0) = 0;
    intrinsics(1, 1) = focal_length;
    intrinsics(1, 2) = 0;

    intrinsics(2, 0) = 0;
    intrinsics(2, 1) = 0;
    intrinsics(2, 2) = 1;

    inv_intrinsics = intrinsics.inverse();
}


void Camera::lookat(const Vec3d &eye, const Vec3d &lookat, const Vec3d &up_dir) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Create the extrinsics matrix from the eye position, look-at position, and up vector
     *
     * Hints:
     * - Example: https://github.com/NVlabs/eg3d/blob/main/eg3d/camera_utils.py
     *
     */

    cam2world_translation = Matrix(3, 3);
    cam2world_rotation = Vec3d(0, 0, 0);
}


std::vector<Ray> Camera::shoot_rays(const size_t &height, const size_t &width) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * This function generates camera rays from the given intrinsics and extrinsics matrices
     *
     * Hints:
     * - Follow the given steps
     *
     */

    std::vector<Ray> rays;
    std::vector<Vec3d> uv;

    Vec3d world_cam_coord = cam2world_translation;  // Location of the caemra in world coordinate

    // s is equal to max dim divided by min dim
    double aspect_ratio = float(height) / width;

    for (int u = 0; u < height; ++u) {
        for (int v = 0; v < width; ++v) {
            // Step 1: Screen to NDC coordinate

            // Step 2: Lift NDC to camera coordinate

            // Step 3: Cam to world coordinate

            // Step 4: Calculate the ray from the camera to this point
        }
    }

    return rays;
}
