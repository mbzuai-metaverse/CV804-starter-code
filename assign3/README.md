# Assignment #3
## Introduction
In this assignment, you will use Catmull-Rom splines along with OpenGL lighting and texture mapping to create a roller coaster simulation. The simulation will run in a first-person view, allowing the user to "ride" the coaster in an immersive environment. As with the first assignment, you will create an interesting animation after finishing the program itself. This time, the objective of your animation is to show off both your coaster and the features of your program.

Now that the first programming assignment has familiarized you with working in OpenGL, this assignment asks you to utilize some more interesting features of the library in the design of a more significant and more entertaining application. In addition, this project gives you a great deal more freedom to be creative in the actual design of your program and the features that go into it; you are asked to create your own solutions to issues involved in the making of your simulation, and to render your coaster as you wish in a world of your design.

After completing this assignment, you should have a solid understanding of:
- **Splines**
- **Texture maps** and their use in OpenGL
- **Camera manipulations** --the use of transformations to create realistic first-person movement

This assignment should be challenging, at least as much as the first assignment and likely more. However, it should also be a lot of fun! Please start early.

## Installing Dependencies
This assignment requires OpenGL and OpenCV libraries for C++. All the dependencies were installed in the first assignment. If you have not installed them, please refer to the README file of the first assignment.

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
./assign3
```

Since there are a lot of input paths, we define them as constant strings in `include/assign3.h` instead of passing them as arguments like previous assignments. Please modify them to match the file paths on your machine.

## Tasks
Your task is to create a roller coaster simulation using OpenGL. You'll need to render a spline sequence which represents the entire length of your track. In order to do so, you will need to implement a function that takes four control points (p0 through p3) and a floating point value (u) from 0 to 1, and computes the corresponding position on the spline segment defined by these four control points. Drawing a single spline from four control points isn't that exciting--you'll need to use several control points in sequence and draw spline segments along them, starting from the first four points and proceeding until you draw the final spline for the last four points. This will allow you to represent a long, elaborate curve for your coaster. In this exercise, we will use Catmull-Rom splines for the representation of your coaster. More details can be found in latter sections.

The assignment can be divided into 5 main subtasks:
- **Level 1 (spline)**: First, please implement your spline function and draw some splines to the screen. A point on a single Catmull-Rom spline segment is given by:

    $p(u) = [u^3 \quad u^2 \quad u \quad 1] \times M \times C \qquad (1)$

    where M is the Catmull-Rom spline basis matrix, C is the control matrix, and parameter u varies on the interval [0,1]. The exact form of the formula can be found [here](http://www.mvps.org/directx/articles/catmull/).

    To render the spline, you may use the simplest "brute-force" method where you vary the parameter u by some fixed value, for example 0.001. Insert each value of u into equation (1) (above), to obtain the point location $p(u)$. For example: $u = 0.0, 0.001, 0.002, ..., 0.999, 1.0$. Then, connect consecutive points with lines, for example, by using `GL_LINES`. You may need to set a proper line width, by using the OpenGL `glLineWidth` function. Note that in order to see the spline, you must setup your OpenGL camera. For a start, you can just use a stationary camera, similar to the first assignment (we recommend using gluPerspective for this assignment). You may use the keyboard/mouse to view the scene from different angles, or zoom in and out, just like in the first assignment. We provide a set of "track" files containing control points to define some simple splines, and starter code to read in a sequence of these files and convert them to sequences of control points that you can use. You can safely assume that each spline file (i.e. `spline_data/*.sp`) has at least 4 control points. You are encouraged to experiment with .sp files, creating your own spline files as needed for your personalized solution (well-documented creativity will be awarded).

- **Level 2 (ground)**: Next, add the ground. You can use a plane for the ground. It should be texture-mapped for realism with an image of your choice. There are plenty of free texture online, for example, [Unity assess store](https://assetstore.unity.com/popular-assets--skyboxes#free-skyboxes-Ts73), so find one that appeals to you. Note that you may need to rescale your texture image to be of dimension that is a power of 2. For example, good choices are 256x256 or 512x512. You can use any software you wish to scale and/or edit your texture image. For Linux user, we recommend GThumb.

- **Level 3 (sky)**: After this, create your sky--this should also be texture-mapped, and the method of modeling it is up to you. For example, one way to create the sky is to enclose the entire scene into a cube, and then texture-map the faces of this cube with some sky-like texture. Note, however, that there are issues (e.g., visible seams) with many obvious representations, so you can improve this for extra credit (but don't do it until you are done with all the levels). Make sure that you can still draw the splines as before once you have done levels 2 and 3!

- **Level 4 (the ride)**: Now, implement the ability to ride the coaster. You can do so by moving your camera at a constant speed (in u) along the spline (creating physically realistic motion is extra credit). Properly orienting your camera is a challenging problem! You'll want to have your camera facing "forward" (along the tangent to your spline) as it moves. The tangent vector can be computed by differentiating equation (1) with respect to u, that is: $t(u) = p'(u) = [3u^2 \quad 2u \quad 1 \quad 0] \times M \times C$. Note that you need to normalize this vector to obtain a unit length tangent. Also, you need to make the "up" vector of your camera follow some continuous path of normals to the spline. A cheap method to decide your up vector is to always set it equal to the normal of your ground plane--however, this is very unrealistic for many splines.

- **Level 5 (rail cross-section)**: Modify the appearance of the coaster itself: instead of just a line, make your track look like a track, by rendering a cross-section of the rail. In order to render the cross-section, you can use the tangent, normal and binormal described in Level 4. Suppose p0 and p1 are two consecutive points along the spline. You can then compute vertices $v_0, v_1, ..., v_7$, and render a tube as described in the **Free Tips** section.

After this is all done, add some fun extras! Do not attempt extra credit until you have successfully finished everything else, or else you run the risk of running out of time. Your final implementation must satisfy the followings:
- Complete all levels.
- Properly render Catmull-Rom splines to represent your track.
- Render a texture-mapped ground and sky.
- Render a rail cross-section.
- Move the camera at a reasonable speed in a continuous path and orientation along the coaster.
- Render the coaster in an interesting manner (good visibility, realism).
- Run at interactive frame rates (>15fps at 640x480).
- Be reasonably commented and written in an understandable manner--we will read your code.
- Be submitted along with the illustration video for the required animation (see below).
- Be submitted along with a readme file documenting your program's features and describing the approaches you took to each of the open-ended problems we posed here (rendering the sky and determining coaster normals in particular). This is especially crucial if you have done something spectacular for which you wish to receive extra credit!

Below is an example of a solution, with several extra credit elements. Of course, this is just an example; your solution will likely differ. This image is not a standard for grading or meant to show what you need to do. The text in this README gives the official (and only) rules for the assignment requirements.

![final](resources/final.gif)

This assignment is much more open-ended as to what you may choose to implement for extra credit. You may be awarded credit for any creative or interesting solution to an issue in your implementation, as long as it is well-documented in your readme file. Below are some ideas you might want to think about if you have the time:
- Render a T-shaped rail cross-section.
- Render double rail (like in real railroad tracks).
- Make your track circular and close it with C1 continuity (small credit, i.e., 1 point).
- Add OpenGL lighting to make your coaster look more realistic.
- Draw additional scene elements: texture-mapped wooden crossbars, a support structure that looks realistic, decorations on your track, something interesting in the world nearby, etc.
- Create tracks that mimic real world roller coasters.
- Generate your track from several different sequences of splines (multiple track files), so you can shuffle these around and create a random track.
- Draw splines using recursive subdivision (vary step size to draw short lines) instead of using brute force (vary u with fixed step size).
- Render the environment in a better (prettier, more efficient, more interesting, etc?) manner than described here.
- Decide coaster normals in a better manner than described here.
- Modify the velocity with which your camera moves to make it physically realistic in terms of gravity.- Derive the steps that lead to the above physically realistic equation.

***Please note that the amount of extra credit awarded will not exceed 20% of the assignment's total value.***


## Starter Code Instructions

Similar to previous assignments, we also provide a starter code which already implemented a few basic elements:
- `include/texture.h` and `src/texture.cpp`: `MyTexture` class represents texture. It has a function to load the texture data from a texture image path. The texture data will be saved in `data[512][512][3]`. It also has an `id` member which can be used for OpenGL texture binding. You don't have to implement anything in these files.
- `include/vec3f.h` and `src/vec3f.cpp`: `Vec3f` class represents 3D float vector. It already has most of basic vector operators (e.g. dot product, cross product, normalization, etc). Can be useful to work with splines and vertex coordinates. You don't have to implement anything in these files.
- `include/spline.h` and `src/spline.cpp`:

    * `from_path` function:  Load the control points from a given spline data path. This function is already implemented but you may want to add some additional code to preprocess the control points (for example, rescale it to match your coordinate system).
    * `_catmull_rom` function: Calculate the value of the Catmul-Rom spline constructed by four control points starting from `start_idx` at $0 \le t \le 1$. You need to implement this.
    * `get` function: Calculate the value of the spline at $0 \le t \le 1$. You need to implement this.

- `include/assign3.h` and `src/assign3.cpp`: You have to implement:
    * `set_camera` function: Change the camera when moving a long the track.
    * `display` function: Display callback function.
    * `init` function: One-time initialization commands.

    Please check predefined variables so that you don't have to redefine them again.


## Free Tips (Will make your life much easier!!!)
### General tips
- Make sure the starter code works on your machine.
- Start this assignment as soon as you can. It is a significant endeavor, with many intermediate steps. If you wait until a few days before the assignment is due, you probably will not finish. This project is a lot of fun if you're not rushed, and if enough time is put in the end product is something fun that you can show off to your friends.
- Reuse any code from the previous assignment that might save you some time. OpenGL programs tend to have a fair deal of overlap. Particularly, you might want to borrow some user control functionality, functions to read/write images, and any functions you might have made to automatically write out the frames for your animation. Don't overdo this to the degree that you have an awkward time changing things for this project--the general structure of your transformations and the state of your simulation will be significantly different from the layout of the previous assignment.
- Do not load the texture before initializing OpenGL and GLUT (initialization happens when calling glutCreateWindow). Otherwise, there is no place to load the textures to, and textures won't work.
- Experiment with your own ideas, and have fun.
- ***If you stuck somewhere, contact the TAs for necessary assistance.***
### How to construct the railway
As we mentioned, the railway is represented by a Catmull-Rom spline. After constructing the spline, you also have to move a car along this spline. To do so, the camera must have orientation which can be formulated by three orthogonal vectors and this orientation must be changed in a realistic manner when moving on the spine. One way to achieve this is to use the NTB space.

'NTB' is an 'on curve' coordinate system, consisting of orthogonal vectors T (curve tangent), N (curve normal) and B (curve "binormal", obtained via TxN). Creating an NTB coordinate 'frame' at each timestep of your animation is the best way to orient your car along the coaster track (and have it tilt and turn correctly as the track winds and loops around). Such an NTB frame is called a 'Frenet frame’.

Here is a visualization (T - red; N - green; B - blue):

![NTB](resources/NTB.gif)

Calculating T is rather easy (via the curve's derivative). N is trickier - but we can start with an initial guess, and use it to get a good starting point. B is simply the cross product of T and N. Only for the very first point in the calculated chain of points, instead of starting with T and N to calculate B, it seems better to start with T and B, and derive N from those (again, via cross product). Once we have a starter set (ie. our first NTB triplet), we could calculate further NTB sets incrementally. Such incremental propagation guarantees that the NTB frame won't wildly 'flip' around at regions of severe normal change (not calculating NTB incrementally, eg. computing it explicitly for each point, could result in this hard-to-fix problem). The NTB flipping issue is described in details [here](https://dhal.com/downloads/resources/PathsForVolumeSlices.pdf). This method of calculating T, N, and B is called Sloan's method. Exact equations can be found [here](http://www.cs.cmu.edu/afs/andrew/scs/cs/15-462/web/old/asst2camera.html).

We provide `visualizattion_spline.py` written in Python for you to test and visualize the NTB implementation. You just need to fill the missing functions/methods and the code will visualize the Catmull-Rom spline and the orientation vectors (T, N, and B) of each point on the spline like the above image. Note that `visualizattion_spline.py` is just to help you test your NTB implementation before implement it in C++ and it is not required to implement this.

### Moving the camera
Like an FPS, the goal is to place the camera on the moving car to get a first-person rider POV. Use these two calls:
- gluLookAt - inputs change each frame, based on (animating) NTB 
- gluPerspective/glFrustum - one-time setup, to specify the lens FOV


### Drawing coaster tracks
You need eight vertices to draw a cuboid that spans the two end ("rail") CatmullRom curves - four verts (forming a SQUARE cross section) on the left (using the yellow-colored BTN (specifically, B,T) axes, centered at a curve point), and four corresponding verts on the right. Using the 8 verts you can draw 6 quads (2 end squares, 4 middle rectangles) to produce a single ‘slat'.

How would you form a square at a curve point on either track? Easy:
```
vert0 = curvePoint
vert1 = curvePoint+T
vert2 = curvePoint+T+B
vert3 = curvePoint+B
```
To get the other square, repeat the above on the other side, with the corresponding curvePoint that's across.

Given the close spacing of the curve points, it's likely that the slat cuboids would OVERLAP. To fix the problem (ie. to create thin slats that have gaps between them), just scale the squares down appropriately, by identically scaling the T and B vectors using a <1 scale factor (you'll need to find a good value by trial and error):
```
// might need to set 's' bigger/smaller than 0.01..
s = 0.01
vert0 = curvePoint
vert1 = curvePoint+(s*T)
vert2 = curvePoint+(s*T)+(s*B)
vert3 = curvePoint+(s*B)
```

Another problem that can occur (depending on track configuration) is this: in high curvature areas (eg. where drops are situated), your second (offset) track might loop back on itself, ie. create an unwanted pinch/bubble/loop. How would you fix it? Simple - instead of using the normalized N to locate the track (which creates an inter-track spacing of 1 by definition), use a scaled down value, eg. 0.5N.


## Show People What You Got!!!
We recommend to use builtin record application of your OS (e.g. [MacOS](https://support.apple.com/en-ae/102618), [Ubuntu](https://help.ubuntu.com/stable/ubuntu-help/screen-shot-record.html)) to record your animation. We will compile a video of all student submissions and show it in class.
