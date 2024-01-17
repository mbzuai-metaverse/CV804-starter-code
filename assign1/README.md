# Assignment #1
## Introduction
This assignment is intended as a hands-on introduction to OpenGL and programming in three dimensions. The starter code we provide is minimal, giving only the functionality to read and write a JPEG image and handle mouse and keyboard input. You must write the code to create a window, handle camera transformations, perform rendering, and handle any other functionality you may desire. We highly recommend the use of GLUT--please see the OpenGL Programming Guide for information, or [OpenGL.org](http://www.opengl.org/) and [a page of OpenGL tutors](http://users.polytech.unice.fr/~buffa/cours/synthese_image/DOCS/www.xmission.com/Nate/tutors.html) or the [online red book](http://www.glprogramming.com/red/).

A height field is a visual representation of a function which takes as input a two-dimensional point and returns a scalar value ("height") as output. In other words, a function f takes x and y coordinates and returns a z coordinate.

Rendering a height field over arbitrary coordinates is somewhat tricky--we will simplify the problem by making our function piece-wise. Visually, the domain of our function is a two-dimensional grid of points, and a height value is defined at each point. We can render this data using only a point at each defined value, or use it to approximate a surface by connecting the points with triangles in 3D.

## Installing Dependencies
This assignment requires OpenGL and OpenCV libraries for C++.
### MacOS
```
brew install opencv
brew link --overwrite opencv
```
### Linux
Follow [this link](https://phoenixnap.com/kb/installing-opencv-on-ubuntu) to install on Ubuntu. For other linux distributions, you can install opencv from source following the steps in the provided link.

## Compile Your Code
Use the following code to build your project
```
mkdir build
cd build
cmake ..
make
```
Then you can run the compiled code by the following command:
```
./assign1 ../images/spiral.jpg
```

## Tasks
Your final goal is to build a height field rendering application. The input of the program is a height field map which is represented as a gray image. Your program needs to have the following features:
- Be able to handle at least a 256x256 image for your height field at interactive frame rates (window size of 640x480). Height field manipulations should run smoothly.
- Be able to render the height field as points, lines("wireframe"), or solid triangles (with keys for the user to switch between the three).
- Render as a perspective view, utilizing GL's depth buffer for hidden surface removal.
- Use input from the mouse to spin the heightfield around using glRotate.
- Use input from the mouse to move the heightfield around using glTranslate.
- Use input from the mouse to change the dimensions of the heightfield using glScale.
- Color the vertices using some smooth gradient.
- Be reasonably commented and written in an understandable manner--we will read your code.

You may choose to implement any combination of the following for extra credit:
- Experiment with material and lighting properties.
- Render wireframe on top of solid triangles (use glPolygonOffset to avoid z-buffer fighting).
- Color the vertices based on color values taken from another image of equal size. However, your code should still support also smooth color gradients as per the core requirements.
- Texturemap the surface with an arbitrary image.
- Allow the user to interactively deform the landscape.

***Please note that the amount of extra credit awarded will not exceed 10% of the assignment's total value.***


## Starter Code Instructions
Here we provide you a starter code to make your life easier. All you need to do is filling the missing functions. We highly recommend checking all the code before starting your implementation:
- Take an image path as input and then create a height field such that the two dimensions of the grid correspond to the two dimensions of the image and the height value is a function of the image grayscale level. You also have to color the vertices using some smooth gradient. This is done by `load_height_map` function.
- Setup a window to display results using GLUT. Check `initialize_display` function.
- Initialize one-time commands, such as setting up initial projection/view matrices, or glClearColor. Check `init` function.
- Define display callback function that handle the rendering (drawing) process in `display` function.
- Transforming the height map using the input from user. In the starter code, we have already implemented the input logic: Rotation / translation / scaling is performed by dragging the mouse while holding nothing / Ctrl / Shift, respectively. You need to use `g_vLandRotate, g_vLandTranslate, g_vLandScale` to update the view matrix.
- Clicking 'm' or 'M' will switch between different rendering modes, including point, wireframe, and triangle modes. Check `keyboard` function and modify your `display` callback to achieve this feature.

After finish your implementation, your program should look like [this](https://youtu.be/tym9seaygYQ).


## Free Tips
- Make sure the starter code works on your machine.
- Familiarize yourself with GL's viewing transformations before attempting to render the height field itself. Try rendering a simple object first.
- Do not mix up `GL_MODELVIEW` and `GL_PROJECTION`.
- For glFustrum and gluPerspective, the near and far values for clipping plane have to be positive. You will see weird problems if they are zero or negative.
- Finish your program completely before worrying about the animation.
- One way to optimize your program is to minimize the number of calls to `glBegin(GL_TRIANGLES`) and glVertex3f. For example, you should only call `glBegin(GL_TRIANGLES`) once at the beginning of your triangles and glEnd() at the end instead of calling `glBegin(GL_TRIANGLES`) for every single triangle. To further optimize your program, you can use `GL_TRIANGLE_STRIP` or `GL_TRIANGLE_FAN`.
- Don't try to do this at the last minute. This assignment is supposed to be fun and relatively easy, but time pressure has a way of ruining that notion.
- Don't over-stretch the z-buffer. It has only finite precision. A good call to setup perspective is:
```
gluPerspective(fovy, aspect, 0.01, 1000.0);
```
A bad call would be:
```
gluPerspective(fovy, aspect, 0.0001, 100000.0);
```
or even worse:
```
gluPerspective(fovy, aspect, 0.0, 100000.0);
```
- In the last two examples, the problem is that the ratio between the distance of the far clipping plane (=last parameter to gluPerspective), and the distance of the near clipping plane (=third parameter to gluPerspective) is way too large. Since the z-buffer has only finite precision (only a finite number of bits to store the z-value), it cannot represent such a large range. OpenGL will not warn you of this. Instead, you will get all sorts of strange artifacts on the screen and your scene will look nothing like what you intended it to be.
- ***If you stuck somewhere, contact the TAs for necessary assistance.***


## Show People What You Got!!!
There is a large amount of room for creatitiy in terms of how you choose to show your results in the animation. You can use our provided input images, or modify them with any software you wish, or use your own input images. You may also use your animation to show off any extra features you choose to implement. Your animation will receive credit based on its artistic content, whether pretty, funny, or just interesting in some manner.

We recommend to use builtin record application of your OS (e.g. [MacOS](https://support.apple.com/en-ae/102618), [Ubuntu](https://help.ubuntu.com/stable/ubuntu-help/screen-shot-record.html)) to record your animation. We will compile a video of all student submissions and show it in class.
