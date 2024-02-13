#ifndef ASSIGN1_H
#define ASSIGN1_H

#include "spline.h"
#include "vec3f.h"
#include <ctime>
#include <string>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "texture.h"


class Assign3 {
private:
    const size_t WINDOW_X = 100;
    const size_t WINDOW_Y = 100;
    const size_t WINDOW_H = 720;
    const size_t WINDOW_W = 720;
    const char* WINDOW_NAME = "Assign 3";

    const std::string GROUND_TEXTURE_PATH = "../texture_images/ground.jpg";
    const std::string SKY_TEXTURE_PATH = "../texture_images/sky.png";
    const std::string TIES_TEXTURE_PATH = "../texture_images/ties.png";
    const std::string SPLINE_PATH = "../spline_data/goodRide.sp";

    // Textures
    MyTexture ground_texture, sky_texture, ties_texture;

    // Railway
    Spline railway;
    GLboolean running = false;
    GLfloat current_position = 0;

protected:
    static Assign3 *instance;

public:

    void main(int, char**);

    void initialize_window();

    void init();

    static void set_camera(const Vec3f&, const Vec3f&, const Vec3f&, const Vec3f&);

    void display();
    static void display_wrapper();

    void do_idle();
    static void do_idle_wrapper();

    void keyboard(unsigned char, int, int);
    static void keyboard_wrapper(unsigned char, int, int);

    static void set_instance(Assign3*);
};

#endif
