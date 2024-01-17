#ifndef ASSIGN1
#define ASSIGN1

#include <string>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Assign1 {
private:
    const int WINDOW_X = 100;
    const int WINDOW_Y = 100;
    const int WINDOW_H = 640;
    const int WINDOW_W = 480;
    const char* WINDOW_NAME = "Assign 1";

    enum ControlState {
        ROTATE,
        TRANSLATE,
        SCALE
    } g_ControlState;

    enum RenderMode {
        POINT,
        WIREFRAME,
        TRIANGLE,
    } g_renderMode;

    int g_vMousePos[2] = {0, 0};
    int g_iLeftMouseButton = 0;    // 1 if pressed, 0 if not
    int g_iMiddleMouseButton = 0;
    int g_iRightMouseButton = 0;

    // state of the world */
    GLfloat g_vLandRotate[3] = {0.0, 0.0, 0.0};
    GLfloat g_vLandTranslate[3] = {0.0, 0.0, 0.0};
    GLfloat g_vLandScale[3] = {1.0, 1.0, 1.0};

    // Height map data
    // You can add your data here

protected:
    static Assign1 *instance;

public:
    void load_height_map(std::string);

    void main(int, char**);

    void initialize_window();

    void init();

    void display();
    static void display_wrapper();

    void do_idle();

    static void do_idle_wrapper();

    void mouse_drag(int, int);
    static void mouse_drag_wrapper(int, int);

    void mouse_idle(int, int);
    static void mouse_idle_wrapper(int, int );

    void mouse_button(int, int, int, int);
    static void mouse_button_wrapper(int, int, int, int);

    void keyboard(unsigned char, int, int);
    static void keyboard_wrapper(unsigned char, int, int);

    static void set_instance(Assign1*);
};

#endif
