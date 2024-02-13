#include <iostream>

#include <stdexcept>
#include <string>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "texture.h"


MyTexture::MyTexture() {
    height = width = 0;
}


void MyTexture::from_path(const std::string& texture_path) {
    cv::Mat image = cv::imread(texture_path, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cout << "Could not read the image: " << texture_path << std::endl;
        exit(1);
    }

    this->height = image.rows;
    this->width = image.cols;

    if (this->height > 512 || this->width > 512) {
        throw std::invalid_argument("Texture size should be smaller than 512");
    }

    for (int y = 0, cnt = 0; y < this->height; ++y) {
        uchar* row_ptr = image.ptr<uchar>(y);
        for (int x = 0; x < this->width; ++x) {
            GLubyte b = (GLubyte)row_ptr[x * 3];
            GLubyte g = (GLubyte)row_ptr[x * 3 + 1];
            GLubyte r = (GLubyte)row_ptr[x * 3 + 2];

            data[y][x][0] = r;
            data[y][x][1] = g;
            data[y][x][2] = b;
        }
    }
}
