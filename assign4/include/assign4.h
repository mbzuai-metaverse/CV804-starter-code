#ifndef ASSIGN4_H
#define ASSIGN4_H

#include <ctime>
#include <string>

#include "camera.h"
#include "scene.h"
#include "scene_reader.h"


class Assign4 {
private:
    const size_t IMAGE_HEIGHT = 480;
    const size_t IMAGE_WIDTH = 640;

    Scene scene;

public:
    void main(int, char**);

    void load_scene(const std::string&);
};

#endif
