#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#include "assign4.h"
#include "scene_reader.h"


void Assign4::load_scene(const std::string& path) {
    SceneReader::load_scene(path, scene);
}


void Assign4::main(int argc, char* argv[]) {
    std::string save_path;
    if (argc == 2) {
        load_scene(argv[1]);
        save_path = "";
    }
    else if (argc == 3) {
        load_scene(argv[1]);
        save_path = argv[2];
    }
    else {
        throw std::invalid_argument("Expected a scene path");
    }

    scene.render(IMAGE_HEIGHT, IMAGE_WIDTH, save_path);
}
