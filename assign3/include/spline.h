#ifndef SPLINE_H
#define SPLINE_H

#include <string>
#include <vector>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "vec3f.h"

class Spline {
private:
    std::vector<Vec3f> _control_points;
    std::vector<GLfloat> _segment_lengths;
    GLfloat _total_length;
    size_t _num_points;

    Vec3f _catmull_rom(const size_t&, const GLfloat&);
public:
    std::vector<Vec3f> Ts;
    std::vector<Vec3f> Ns;
    std::vector<Vec3f> Bs;
    std::vector<Vec3f> points;

    void from_path(const std::string&, const size_t &);

    Vec3f get(const GLfloat &t);

    void generate_points_and_orientations(const size_t &);
};

#endif
