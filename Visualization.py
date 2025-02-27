import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import matplotlib.animation as animation


data = np.genfromtxt('data_zxy_012_pid_04_01.csv', delimiter=',', skip_header=0)
x_array = data[:, 0]
y_array = data[:, 1]
z_array = data[:, 2]

# Create a figure and a 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Set axis limits and labels
ax.set_xlim([-5, 5])
ax.set_ylim([-5, 5])
ax.set_zlim([-5, 5])
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Create a text annotation to display the timestep (position in axes fraction)
time_text = ax.text2D(0.05, 0.95, "", transform=ax.transAxes)

# --- Add a constant vector ---
# This arrow starts at the origin (0,0,0) and points to (0,0,4)
const_vector = ax.quiver(0, 0, 0, 0, 0, 4, color='r', arrow_length_ratio=0.2)

# --- Define functions to create and display the box ---
def rotation_matrix_from_vector(n):
    """
    Compute a rotation matrix that rotates the vector (0,0,1) to the vector n.
    
    Parameters:
        n (array-like): The desired normal vector for the top face.
        
    Returns:
        R (3x3 np.array): The rotation matrix.
    """
    n = np.array(n, dtype=np.float64)
    n = n / np.linalg.norm(n)  # Normalize the input normal
    
    a = np.array([0, 0, 1], dtype=np.float64)  # original "up" direction
    
    # If the normal is already (0,0,1) or nearly so, no rotation is needed.
    if np.allclose(n, a):
        return np.eye(3)
    # Handle the case when n is opposite to (0,0,1)
    if np.allclose(n, -a):
        # 180 degree rotation: here we choose to rotate about the x-axis
        return np.array([[1, 0, 0],
                         [0, -1, 0],
                         [0, 0, -1]])
    
    # Compute the rotation axis via cross product
    v = np.cross(a, n)
    s = np.linalg.norm(v)
    c = np.dot(a, n)
    
    # Skew-symmetric cross-product matrix of v
    vx = np.array([[0, -v[2], v[1]],
                   [v[2], 0, -v[0]],
                   [-v[1], v[0], 0]])
    
    # Rodrigues' rotation formula
    R = np.eye(3) + vx + np.dot(vx, vx) * ((1 - c) / (s**2))
    return R

def create_box(center, size, normal):
    """
    Create the 8 vertices of a box given its center, size, and the normal vector of the top face.
    
    Parameters:
        center (array-like): (3,) coordinates for the center of the box.
        size (tuple): (L, W, H) representing the dimensions of the box.
        normal (array-like): (3,) vector representing the desired normal of the top face.
    
    Returns:
        rotated_corners (np.array): (8,3) array of the box vertices after aligning the top face with the normal and translating.
    """
    # Compute the rotation matrix that aligns (0,0,1) with the given normal vector.
    R = rotation_matrix_from_vector(normal)
    
    L, W, H = size
    l, w, h = L / 2, W / 2, H / 2
    
    # Define the box corners in the local coordinate system (centered at the origin)
    corners = np.array([
        [-l, -w, -h],
        [ l, -w, -h],
        [ l,  w, -h],
        [-l,  w, -h],
        [-l, -w,  h],
        [ l, -w,  h],
        [ l,  w,  h],
        [-l,  w,  h]
    ])
    
    # Rotate and translate the corners
    rotated_corners = np.dot(corners, R.T) + center
    return rotated_corners


def get_box_faces(vertices):
    """
    Given 8 vertices of a box, return the 6 faces as lists of vertices.
    """
    faces = [
        [vertices[j] for j in [0, 1, 2, 3]],  # bottom face
        [vertices[j] for j in [4, 5, 6, 7]],  # top face
        [vertices[j] for j in [0, 1, 5, 4]],  # side face
        [vertices[j] for j in [1, 2, 6, 5]],  # side face
        [vertices[j] for j in [2, 3, 7, 6]],  # side face
        [vertices[j] for j in [3, 0, 4, 7]]   # side face
    ]
    return faces

# Global variable to store the box so we can remove it on update
box_collection = None

def update(frame):
    global box_collection
    # Remove the previous box if it exists
    if box_collection is not None:
        box_collection.remove()
    
    # Example: rotate the box about the z-axis over time
    x = x_array[frame]
    y = y_array[frame]
    z = z_array[frame]
    vec = np.array([x, y, z])
    # Define the box center and size
    center = np.array([0, 0, 0])
    size = (1, 1, 3)  # (length, width, height)
    
    # Compute the rotated vertices of the box
    vertices = create_box(center, size, vec)
    faces = get_box_faces(vertices)
    
    # Create a Poly3DCollection for the box and add it to the axes
    face_colors = ['blue', 'grey', 'grey', 'grey', 'grey', 'grey']
    box_collection = Poly3DCollection(faces, facecolors=face_colors, edgecolors='k', alpha=0.5)
    ax.add_collection3d(box_collection)
        # Update the text annotation to display the current timestep
    time_text.set_text(f"Time = {frame}")
    return box_collection,

# Create and start the animation
ani = animation.FuncAnimation(fig, update, frames=len(x_array), interval=400, blit=False)
plt.show()
