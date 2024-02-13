import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import seaborn as sns
import numpy as np


ORI_VIS_LEN = 3


class Spline:
    def __init__(self, points):
        assert len(points) >= 4
        '''
            Insert your code here
        '''

    @staticmethod
    def _catmull_rom(points, t):
        '''
            Insert your code here
        '''

        return None

    def __call__(self, t):
        '''
            Insert your code here
        '''
        return None


def sloan_method(points):
    '''
        Insert your code here
    '''
    Ts, Ns, Bs = [], [], []

    return Ts, Ns, Bs


def animate(frame_idx, particle, orientation_lines, x_railroad, y_railroad, z_railroad, Ts, Ns, Bs):
    p = [x_railroad[frame_idx], y_railroad[frame_idx], z_railroad[frame_idx]]
    T = Ts[frame_idx]
    N = Ns[frame_idx]
    B = Bs[frame_idx]

    print(np.dot(T, B), np.dot(T, N), np.dot(N, B))
    assert np.isclose(np.linalg.norm(T), 1 + 1e-6)
    assert np.isclose(np.linalg.norm(B), 1 + 1e-6)
    assert np.isclose(np.linalg.norm(N), 1 + 1e-6)

    # Update particle's position
    particle.set_data(p[0], p[1])
    particle.set_3d_properties([p[2],])

    # Update particle's orientations
    for i, vec in enumerate([T, N, B]):
        orientation_lines[i].set_data(
            [p[0], p[0] + ORI_VIS_LEN * vec[0]],
            [p[1], p[1] + ORI_VIS_LEN * vec[1]]
        )
        orientation_lines[i].set_3d_properties([p[2], p[2] + ORI_VIS_LEN * vec[2]])

    return [particle,] + orientation_lines


if __name__ == '__main__':
    with open('spline_data/goodRide.sp', 'r') as f:
        f.readline()
        points = [list(map(float, line.split(' '))) for line in f]

    spline = Spline(points)

    # Set Seaborn style
    sns.set_theme(style="whitegrid")

    # Create figure and axis
    fig = plt.figure()
    ax = plt.subplot(111, projection='3d')

    # Plot the railroad
    x_railroad, y_railroad, z_railroad = [], [], []
    for t in np.linspace(0, 0.99, 500):  # Only go to 0.99 to avoid numerical issue
        p = spline(t)
        x_railroad.append(p[0])
        y_railroad.append(p[1])
        z_railroad.append(p[2])
    ax.plot(x_railroad, y_railroad, z_railroad)

    # Prepare the particle and the orientations
    particle, = ax.plot([x_railroad[0]], [y_railroad[0]], [z_railroad[0]], 'ro') # 'ro' creates a red circle marker

    # Generate the orientations
    [Ts, Ns, Bs] = sloan_method(np.stack((x_railroad, y_railroad, z_railroad), axis=1))
    orientation_colors = ['r', 'g', 'b']
    orientation_lines = []
    for i, ori in enumerate([Ts[0], Ns[0], Bs[0]]):
        line, = ax.plot(
            [x_railroad[0], x_railroad[0] + ORI_VIS_LEN * ori[0]],
            [y_railroad[0], y_railroad[0] + ORI_VIS_LEN * ori[1]],
            [z_railroad[0], z_railroad[0] + ORI_VIS_LEN * ori[2]],
            color=orientation_colors[i]
        )
        orientation_lines.append(line)

    # Animate the car
    num_frames = 1000
    ani = FuncAnimation(
        fig,
        lambda frame: animate(
            frame, particle, orientation_lines, x_railroad, y_railroad, z_railroad, Ts, Ns, Bs
        ),
        frames=np.arange(0, num_frames - 1, 2),
        blit=False
    )

    # Show plot
    plt.show()
