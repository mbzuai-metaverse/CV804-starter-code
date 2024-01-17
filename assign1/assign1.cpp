#include "assign1.h"
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
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


Assign1 *Assign1::instance;


void Assign1::load_height_map(std::string image_path) {
    cv::Mat image = imread(image_path, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cout << "Could not read the image: " << image_path << std::endl;
        exit(1);
    }

    /*
     * Your code start here
     */
    throw std::runtime_error("You havent' implemented load_height_map function yet");
    /*
     * End of your code
     */
}


void Assign1::do_idle() {
    // glutPostRedisplay();
}


void Assign1::do_idle_wrapper() {
    instance->do_idle();
}


void Assign1::mouse_drag(int x, int y) {
    int vMouseDelta[2] = {x-g_vMousePos[0], y-g_vMousePos[1]};
  
    switch (g_ControlState) {
        case TRANSLATE:  
            if (g_iLeftMouseButton) {
                g_vLandTranslate[0] += vMouseDelta[0]*0.01;
                g_vLandTranslate[1] -= vMouseDelta[1]*0.01;
            }
            if (g_iMiddleMouseButton) {
                g_vLandTranslate[2] += vMouseDelta[1]*0.01;
            }
            break;
        case ROTATE:
            if (g_iLeftMouseButton) {
                g_vLandRotate[0] += vMouseDelta[1];
                g_vLandRotate[1] += vMouseDelta[0];
            }
            if (g_iMiddleMouseButton) {
                g_vLandRotate[2] += vMouseDelta[1];
            }
            break;
        case SCALE:
            if (g_iLeftMouseButton) {
                g_vLandScale[0] *= 1.0+vMouseDelta[0]*0.01;
                g_vLandScale[1] *= 1.0-vMouseDelta[1]*0.01;
            }
            if (g_iMiddleMouseButton) {
                g_vLandScale[2] *= 1.0-vMouseDelta[1]*0.01;
            }
            break;
    }
    /*
     * Your code start here
     */
    throw std::runtime_error("You havent' implemented mouse dragging callback yet");
    /*
     * End of your code
     */

    g_vMousePos[0] = x;
    g_vMousePos[1] = y;
}


void Assign1::mouse_drag_wrapper(int x, int y) {
    instance->mouse_drag(x, y);
}


void Assign1::mouse_idle(int x, int y) {
    g_vMousePos[0] = x;
    g_vMousePos[1] = y;
}


void Assign1::mouse_idle_wrapper(int x, int y) {
    instance->mouse_idle(x, y);
}


void Assign1::mouse_button(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            g_iLeftMouseButton = (state==GLUT_DOWN);
            break;
        case GLUT_MIDDLE_BUTTON:
            g_iMiddleMouseButton = (state==GLUT_DOWN);
            break;
        case GLUT_RIGHT_BUTTON:
            g_iRightMouseButton = (state==GLUT_DOWN);
            break;
    }
 
    switch(glutGetModifiers()) {
        case GLUT_ACTIVE_CTRL:
            g_ControlState = TRANSLATE;
            break;
        case GLUT_ACTIVE_SHIFT:
            g_ControlState = SCALE;
            break;
        default:
            g_ControlState = ROTATE;
            break;
    }

    g_vMousePos[0] = x;
    g_vMousePos[1] = y;
}


void Assign1::mouse_button_wrapper(int button, int state, int x, int y) {
    instance->mouse_button(button, state, x, y);
}


void Assign1::keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'm': case 'M':
            /*
             * Your code start here
             */
            throw std::runtime_error("You havent' implemented keyboard callback yet");
            /*
             * End of your code
             */
        case 'q': case 'Q':
            exit(0);
            break;
    }
}


void Assign1::keyboard_wrapper(unsigned char key, int x, int y) {
    instance->keyboard(key, x, y);
}


void Assign1::initialize_window() {
    /*
     * Your code start here
     */
    throw std::runtime_error("You havent' implemented initialize_window function yet");
    /*
     * End of your code
     */
}


void Assign1::display() {
    /*
     * Your code start here
     */
    throw std::runtime_error("You havent' implemented display callback yet");
    /*
     * End of your code
     */
}


void Assign1::display_wrapper() {
    instance->display();
}


void Assign1::init() {
    /*
     * Your code start here
     */
    throw std::runtime_error("You havent' implemented init function yet");
    /*
     * End of your code
     */
}


void Assign1::main(int argc, char* argv[]) {
    if (argc == 2) {
        load_height_map(argv[1]);
    }
    else {
        throw std::invalid_argument("Expected an image path");
    }

    // Initializing GLUT
    glutInit(&argc, argv);
    
    // Create a window to draw stuff
    initialize_window();

    // Register the display callback
    glutDisplayFunc(display_wrapper);

    // Register callback for idling
    glutIdleFunc(do_idle_wrapper);

    // Register callback for mouse dragging
    glutMotionFunc(mouse_drag_wrapper);

    // Register callback for mouse idle
    glutPassiveMotionFunc(mouse_idle_wrapper);

    // Register callback for mouse button
    glutMouseFunc(mouse_button_wrapper);

    // Register callback for keyboard
    glutKeyboardFunc(keyboard_wrapper);

    // Here we go
    init();
    glutMainLoop();
}


void Assign1::set_instance(Assign1* framework) {
    instance = framework;
}
