#include <cassert>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "primitives.h"
#include "light.h"
#include "scene.h"


MyVertex Scene::get_ray_intersection(const Ray &ray) {
    MyVertex intersection;
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Calculate the closest intersection between the ray and the primitives (spheres and triangles).
     *
     * Hints:
     * - You can return a special value if the ray does not hit anything. For example, you can return a MyVertex with normal vector equal to 0.
     * - Note that in this assignment, the size of light source is assumed
     * to be infinitesimal, therefore we do not need to consider its intersection with the ray
     */


    return intersection;
}


Vec3d Scene::get_ray_color(const Ray &ray) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Get the ray color using Phong illumination model and shadow ray test.
     *
     * Hints:
     * - Use BACKGROUND_COLOR for background color.
     * - For shadow ray, you should shift the origin torward the direction vector a bit.
     * - shadow ray test is segment-intersection test, not ray-intersection test.
     * - Use the get_ray_intersection for both calculating the color and shadow ray test.
     */

    return BACKGROUND_COLOR;
}


uint8_t Scene::unnormalize_color(const double &c) {
    double clamped = std::max(0.0, std::min(255.0, c));
    double rounded = std::round(clamped);
    return static_cast<uint8_t>(rounded);
}


void Scene::render(const size_t &height, const size_t &width, const std::string &save_path) {
    std::vector<Ray> all_rays = camera.shoot_rays(height, width);

    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);
    uint8_t bg_x = uint8_t(BACKGROUND_COLOR[0] * 255);
    uint8_t bg_y = uint8_t(BACKGROUND_COLOR[1] * 255);
    uint8_t bg_z = uint8_t(BACKGROUND_COLOR[2] * 255);
    image.setTo(cv::Scalar(bg_x, bg_y, bg_z));

    size_t cur_row = 0;
    size_t cur_col = 0;
    for (auto ray : all_rays) {
        Vec3d color = get_ray_color(ray);
        uint8_t x = unnormalize_color(color[0] * 255.);
        uint8_t y = unnormalize_color(color[1] * 255.);
        uint8_t z = unnormalize_color(color[2] * 255.);

        image.at<cv::Vec3b>(cur_row, cur_col) = cv::Vec3b(z, y, x);
        cur_col += 1;
        if (cur_col == width) {
            cur_row += 1;
            cur_col = 0;
        }

        size_t pixel_idx = cur_col + cur_row * width;
        if (pixel_idx % 1000 == 0) {
            std::cerr << "Rendering pixel #" << pixel_idx << "/" << all_rays.size() << '\n';
        }
    }

    if (!save_path.empty()) {
        cv::imwrite(save_path, image);
    }
    else {
        cv::imshow("Ray tracer", image);
        cv::waitKey(0); // Wait for a keystroke in the window
    }
}
