#include "vec3f.h"
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "assign3.h"


Assign3 *Assign3::instance;


void Assign3::do_idle() {
    glutPostRedisplay();
}


void Assign3::do_idle_wrapper() {
    instance->do_idle();
}


void Assign3::keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        running = running ^ 1;
    }

    if (key == 'r') {
        current_position = 0.0f;
    }
}


void Assign3::keyboard_wrapper(unsigned char key, int x, int y) {
    instance->keyboard(key, x, y);
}


void Assign3::initialize_window() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_H, WINDOW_W);
    glutInitWindowPosition(WINDOW_X, WINDOW_Y);
    glutCreateWindow(WINDOW_NAME);
}


void Assign3::set_camera(const Vec3f &P, const Vec3f &T, const Vec3f &N, const Vec3f &B) {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Change the camera based on NBT.
     *
     * Hint: How to calculate lookat point, eye position, and up vector from the input?
     */
}


void Assign3::display() {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * Display callback function. 
     *
     * Hint: Use your brain.
     */
    glutSwapBuffers();
}


void Assign3::display_wrapper() {
    instance->display();
}


void Assign3::init() {
    /*
     * ----------------------------Insert your code here----------------------------------
     *
     * One-time initialization
     *
     */
}


void Assign3::main(int argc, char* argv[]) {
    // Load texture
    if (GROUND_TEXTURE_PATH == "") {
        throw std::invalid_argument("You haven't specify the ground texture path!");
    }
    if (SKY_TEXTURE_PATH == "") {
        throw std::invalid_argument("You haven't specify the sky texture path!");
    }

    if (TIES_TEXTURE_PATH == "") {
        throw std::invalid_argument("You haven't specify the ties texture path!");
    }

    // Initializing GLUT
    glutInit(&argc, argv);

    // Create a window to draw stuff
    initialize_window();

    // Register the display callback
    glutDisplayFunc(display_wrapper);

    // Register callback for idling
    glutIdleFunc(do_idle_wrapper);

    // Register callback for keyboard
    glutKeyboardFunc(keyboard_wrapper);

    // Here we go
    init();
    glutMainLoop();
}


void Assign3::set_instance(Assign3* framework) {
    instance = framework;
}
