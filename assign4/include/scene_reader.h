#ifndef SCENE_READER_H_INCLUDED
#define SCENE_READER_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include "light.h"
#include "primitives.h"
#include "scene.h"


class SceneReader {
private:
    static void _load_ambient(std::ifstream &, MyLight&);

    static void _load_vertex(std::ifstream &, MyVertex&);

    static void _load_triangle(std::ifstream &, MyTriangle&);

    static void _load_sphere(std::ifstream &, MySphere&);

    static void _load_light(std::ifstream &, MyLight&);

public:
    void static load_scene(const std::string&, Scene&);
};

#endif
