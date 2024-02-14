#ifndef TEXTURE_H
#define TEXTURE_H

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>

#endif
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class MyTexture {
public:
    int height, width;
    unsigned int id;
    GLubyte data[512][512][3];

    MyTexture();

    void from_path(const std::string&);
};

#endif
