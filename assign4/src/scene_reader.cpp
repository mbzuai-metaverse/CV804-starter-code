#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "scene_reader.h"
#include "scene.h"
#include "light.h"
#include "primitives.h"


void SceneReader::_load_ambient(std::ifstream &file, MyLight &ambient_light) {
    std::string property_type;
    double x, y, z;

    file >> property_type >> x >> y >> z;
    property_type.pop_back();  // Remove the last colon character
    if (property_type != "amb") {
        throw std::invalid_argument("Unrecgonized property type: " + property_type);
    }
    ambient_light.set_color(x, y, z);
}


void SceneReader::_load_light(std::ifstream &file, MyLight &light) {
    for (size_t property_idx = 0; property_idx < 2; ++property_idx) {
        std::string property_type;
        file >> property_type;
        property_type.pop_back();  // Remove the last colon character

        if (property_type == "pos") {
            double x, y, z;
            file >> x >> y >> z;
            light.set_position(x, y, z);
        }
        else if (property_type == "col") {
            double x, y, z;
            file >> x >> y >> z;
            light.set_color(x, y, z);
        }
        else {
            throw std::invalid_argument("Unrecognize property: " + property_type);
        }
    }
}


void SceneReader::_load_vertex(std::ifstream &file, MyVertex &vertex) {
    for (int property_idx = 0; property_idx < 5; ++property_idx) {
        std::string property_type;
        file >> property_type;
        property_type.pop_back();  // Remove the last colon character
        if (property_type == "pos") {
            double x, y, z;
            file >> x >> y >> z;
            vertex.set_position(x, y, z);
        }
        else if (property_type == "nor") {
            double x, y, z;
            file >> x >> y >> z;
            vertex.set_normal(x, y, z);
        }
        else if (property_type == "dif") {
            double x, y, z;
            file >> x >> y >> z;
            vertex.set_diffuse(x, y, z);
        }
        else if (property_type == "spe") {
            double x, y, z;
            file >> x >> y >> z;
            vertex.set_specular(x, y, z);
        }
        else if (property_type == "shi") {
            double shi;
            file >> shi;
            vertex.set_shininess(shi);
        }
        else {
            throw std::invalid_argument("Unrecognize property: " + property_type);
        }
    }
}


void SceneReader::_load_triangle(std::ifstream &file, MyTriangle &tri) {
    for (int vertex_idx = 0; vertex_idx < 3; ++vertex_idx) {
        MyVertex v;
        _load_vertex(file, v);
        tri.add_vertex(v);
    }
}


void SceneReader::_load_sphere(std::ifstream &file, MySphere &sphere) {
    for (int property_idx = 0; property_idx < 5; ++property_idx) {
        std::string property_type;
        file >> property_type;
        property_type.pop_back();  // Remove the last colon character
        if (property_type == "pos") {
            double x, y, z;
            file >> x >> y >> z;
            sphere.set_position(x, y, z);
        }
        else if (property_type == "rad") {
            double rad;
            file >> rad;
            sphere.set_radius(rad);
        }
        else if (property_type == "dif") {
            double x, y, z;
            file >> x >> y >> z;
            sphere.set_diffuse(x, y, z);
        }
        else if (property_type == "spe") {
            double x, y, z;
            file >> x >> y >> z;
            sphere.set_specular(x, y, z);
        }
        else if (property_type == "shi") {
            double shi;
            file >> shi;
            sphere.set_shininess(shi);
        }
        else {
            throw std::invalid_argument("Unrecognize property: " + property_type);
        }
    }
}


void SceneReader::load_scene(const std::string &path, Scene &scene) {
    std::ifstream scene_file(path);

    if (!scene_file.is_open()) {
        throw std::invalid_argument("Error loading " + path);
    }

    size_t num_objects;
    scene_file >> num_objects;

    _load_ambient(scene_file, scene.ambient_light);

    std::string primitive_type;
    for (int object_idx = 0; object_idx < num_objects; ++object_idx) {
        scene_file >> primitive_type;
        if (primitive_type == "triangle") {
            MyTriangle tri;
            _load_triangle(scene_file, tri);
            scene.all_triangles.push_back(tri);
        }
        else if (primitive_type == "sphere") {
            MySphere sphere;
            _load_sphere(scene_file, sphere);
            scene.all_spheres.push_back(sphere);
        }
        else if (primitive_type == "light") {
            MyLight light;
            _load_light(scene_file, light);
            scene.all_lights.push_back(light);

            if (scene.all_lights.size() > 8) {
                throw std::invalid_argument("Number of lights exceeded maximum number of lights in OpenGL");
            }
        }
    }
}
