#include "vec3f.h"
#include <limits>
#include <numeric>
#include <stdexcept>
#include <string>
#include <fstream>

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "spline.h"


void Spline::from_path(const std::string &path, const size_t &num_samples) {
    std::ifstream spline_file(path);

    if (!spline_file.is_open()) {
        throw std::invalid_argument("Error loading " + path);
        return;
    }

    size_t temp;
    spline_file >> _num_points >> temp;

    GLfloat min_x, min_y, min_z, max_coord;
    min_x = min_y = min_z = std::numeric_limits<GLfloat>::max();

    for (size_t i = 0; i < _num_points; ++i) {
        GLfloat x, y, z;
        spline_file >> x >> y >> z;
        _control_points.emplace_back(x, y, z);

        min_x = std::min(min_x, x);
        min_y = std::min(min_y, y);
        min_z = std::min(min_z, z);

        max_coord = std::max(max_coord, x);
        max_coord = std::max(max_coord, y);
        max_coord = std::max(max_coord, z);

        if (i == 0 or i == _num_points - 1) {
            _control_points.emplace_back(x, y, z);
        }
    }

    /*
     * ----------------------------Insert your code here----------------------------------
     * Hint: You may need to rescale the control points to match your coordinate system
     */
}


Vec3f Spline::_catmull_rom(const size_t &start_idx, const GLfloat &t) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * This function will infer the value of the catmull-rom splines with four points   
     * _control_points[start_idx] ... _control_points[start_idx + 3]                    
     *
     * Hint: Check README to find the equation for catmull-rom splines                  
     */
    return Vec3f(0, 0, 0);
}


Vec3f Spline::get(const GLfloat &t) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Hint: First, find which four points does t lie in, then you can use _catmull_rom     
     */
    return _catmull_rom(0, 0);
}


void Spline::generate_points_and_orientations(const size_t &num_samples) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * This function will infer the value of the catmull-rom splines with four points
     * _control_points[start_idx] ... _control_points[start_idx + 3]                    
     *
     * Hint: Check README to find the equation for catmull-rom splines
     */
}
