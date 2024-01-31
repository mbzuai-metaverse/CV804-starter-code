# Assignment #2 
## Introduction
The aim of the first exercise sheet is to make yourself familiar with the provided mesh processing framework and to implement a simple vertex valence visualization of a mesh using OpenMesh.

The valence v(x<sub>i</sub>) of a vertex x<sub>i</sub> in a triangle mesh is the number of vertices in the 1-ring neighborhood N(x<sub>i</sub>) of x<sub>i</sub>. In particular, the vertices of N(x<sub>i</sub>) are connected with an edge to x<sub>i</sub>. In this assignment, you will color each vertex using its valence.

To make your life easier, we provide a minimal codebase which already implemented a few basic functionality of a mesh viewer:
- **Zoom in/out**: The user can scale the mesh by scrolling the middle mouse button.
- **Rotation**: User can rotate the mesh by dragging the mouse while holding the left button.
- **Rendering mode (Wireframe/Hidden Line/Solid Flat/Solid Smooth/Vertex Valences)**: The application can render the mesh with different modes. The "vertex valences" mode will be implemented by you.
- **Performance testing**: When pressing `f`, the application will run a performance test.

If run successfully, the application will look like in the below video.

![](images/demo.gif)


## Installing Dependencies
### Install FreeGLUT
```
git clone https://github.com/freeglut/freeglut
cd freeglut
mkdir build && cd build
cmake -DFREEGLUT_BUILD_DEMOS=OFF -DOPENGL_gl_LIBRARY=/usr/local/lib/libGL.dylib ..
make
sudo make install
cd ../..
```
### Install OpenMesh
First, download and extract OpenMesh v8.1:
```
wget www.graphics.rwth-aachen.de/media/openmesh_static/Releases/8.1/OpenMesh-8.1.zip
unzip OpenMesh-8.1.zip
cd OpenMesh-8.1
```
Then change c++ version to 17 in `CMakefile.txt`:
```
...
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 17)
...
```

Then:
```
mkdir build && cd build
cmake .. -DBUILD_APPS=OFF
make
sudo make install
```

### Compiling Your Code 
```
mkdir build && cd build
cmake ..
make
./assign2 ../data/bunny.off
```

## Tasks
Your task is to build the "Vertex Valences" rendering mode. To do so, you have to fill the two missing functions:
- `calc_valences` in `src/ValenceViewer.cpp`: This function calculates all the valence of each vertex and save it in a customized vertex property called valence_.
- `color_coding` in `ValenceViewer.cpp`: Having the valences of all the vertices, now you have to map them to a color map, e.g. Jet Color, or the one we provided in `data/colors.png`.
- Please do not change any other part of the code. You just need to modify the above two functions.

A working application should look as follow:

![](images/valence_mode.gif)

## Free Tips
- You may need to calculate the maximum and minimum valences. Use the variables `min_valence_` and `max_valence_` that are already defined.
- You can use any color map that you want, or just use the color map we provided in `data/colors.png`. If you use a customized color map, describe it in the readme file.
- Feel free to modify any part of the code, but remember to describe your changes in the readme file.
- You can use the already defined property handler `valence_` in `include/ValenceViewer.h` to store the valence of each vertex.


## We Value Creativity!
Well, the assignment is pretty simple. Try to find a way to make your homework distinguish. For example, you can add more features to the program, or use another meshes, etc. We will give you some credit scores (up to 10%) if we think your program is intesting.

