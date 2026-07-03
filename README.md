# cub3d

## Project Overview

**cub3d** is a 42 curriculum project designed to develop a simple 3D game engine inspired by early raycasting games like *Wolfenstein 3D*. The project challenges you to implement a real-time first-person renderer of a maze-like environment using raycasting techniques, texture mapping, and event-driven programming—all using C and the MiniLibX graphical library.

Your program reads a 2D map describing walls and open spaces and allows the player to move and rotate in a 3D projection of that map, rendered efficiently by casting rays to detect walls and drawing textured vertical stripes for these walls.

## Features

- **Raycasting Engine:** Efficiently casts rays for each vertical screen stripe, determining wall distance and displaying textures accordingly.
- **Texture Mapping:** Supports loading and rendering of wall textures in **PPM** format (note: your implementation uses `.ppm` files).
- **Player Movement and Rotation:**
    - Move forward/backward (W/S keys).
    - Strafe left/right (A/D keys).
    - Rotate view left/right (Left/Right arrow keys).
    - Smooth collision detection prevents walking through walls.
- **Robust Map Parsing:** Reads `.cub` files for textures, floor and ceiling colors, and map layout validation.
- **Error Handling:**
    - Detects invalid `.cub` files, missing texture files, malformed maps, invalid colors, multiple or missing player start positions, etc.
    - Prints descriptive error messages and exits cleanly.
- **Resource Management:** Proper allocation and freeing of memory and graphical assets.
- **Bonus Implementations (if any):** May include minimap rendering, sprite handling, or other enhancements.


## Project Structure and Files

Your project is structured cleanly with clear separation of concerns:

- **Parsing:** Reads the `.cub` configuration file and validates all elements (textures, map layout, RGB colors).
- **Game Logic:** Handles player state, input, and collision detection.
- **Rendering:** Uses the raycasting algorithm to render the 3D scene with textures and color fills.
- **Utils/Helpers:** Functions for vector math, file I/O, error reporting, and other utilities.
- **Main:** Sets up the window via MiniLibX, initializes state and enters the main game loop.


## Map File Format (`.cub`)

Your map files have the `.cub` extension and include the following elements:

- Texture file paths for each cardinal wall side (`NO`, `SO`, `WE`, `EA`).
- Floor (`F`) and ceiling (`C`) colors specified as RGB values separated by commas.
- The map itself: a grid made of the following valid characters:
    - `1` — Wall.
    - `0` — Empty space.
    - `N`, `S`, `E`, `W` — Player's start position and orientation.

**Example:**

```
NO ./textures/north.ppm
SO ./textures/south.ppm
WE ./textures/west.ppm
EA ./textures/east.ppm
F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

**Map Constraints:**

- The map must be rectangular.
- Completely enclosed by walls.
- Exactly one player position.
- No invalid characters allowed.
- Floor and ceiling colors must be valid RGB values [0-255].


## Usage

### Compilation

Use the provided `Makefile`:

```bash
make        # Compiles the project and produces executable `cub3D`
make clean  # Removes object files
make fclean # Removes objects and executable
make re     # Rebuilds the project entirely
```


### Running the Program

```bash
./cub3D <path_to_map.cub>
```

**Example:**

```bash
./cub3D maps/level1.cub
```

- The program will open a graphical window displaying the 3D-rendered maze.
- The player can move around the environment respecting walls and collisions.


## Controls

| Key | Action |
| :-- | :-- |
| **W** or **Up Arrow** | Move forward |
| **S** or **Down Arrow** | Move backward |
| **A** | Strafe left |
| **D** | Strafe right |
| **Left Arrow** | Rotate view left |
| **Right Arrow** | Rotate view right |
| **ESC** | Exit the program |

## Architecture \& Program Flow

### Core Components

1. **Parsing and Validation**
    - Reads the `.cub` configuration file line by line.
    - Extracts texture paths for `NO`, `SO`, `WE`, `EA`.
    - Parses floor and ceiling colors, ensuring RGB ranges.
    - Reads the map grid, validates enclosure by walls, rectangular shape, only allowed characters.
    - Confirms exactly one player start position and its orientation.
2. **Initialization**
    - Initializes MiniLibX window and image buffers.
    - Loads `.ppm` texture files for each wall side into memory.
    - Sets up player position, directional vectors, and camera plane based on starting orientation.
    - Initializes internal game state, including map data structures.
3. **Main Game Loop**
    - Listens for keyboard events and updates player position and rotation accordingly.
    - Performs collision checks before allowing movement.
    - For each screen column:
        - Casts a ray from the player’s viewpoint into the map using Digital Differential Analysis (DDA).
        - Finds distance to the wall.
        - Determines the texture coordinate based on ray hit.
        - Calculates perpendicular wall distance for proper perspective (avoiding fish-eye effect).
        - Renders the vertical slice with the appropriate texture strip.
    - Draws floor and ceiling using the specified RGB colors.
    - Updates the window display.
    - Loops until the user exits (ESC key or window close).
4. **Cleanup**
    - Frees textures and map data.
    - Closes window and exits cleanly.

### Raycasting Details

- **Ray Direction** is computed per screen column using the player direction and camera plane.
- **DDA Algorithm** traces the ray cell-by-cell through the 2D map grid until hitting a wall (`'1'`).
- **Distance Calculation** adjusts for viewing angle to avoid distortion.
- **Texture Coordinate** on the wall is computed based on the precise hit location.
- **Vertical Slice Height** is proportional to the inverse of the perpendicular distance.
- **Pixel Drawing** uses the loaded `.ppm` textures, accessed pixel-by-pixel for correct projection.


## Error Handling

- Errors in parsing (missing or invalid files, color values, or map syntax) print clear messages and stop execution.
- Invalid textures or unreadable `.ppm` files produce informative errors.
- Exiting the program at any point ensures resources are properly freed.


## Bonus Features (if implemented)

- Minimap displaying the player's position and map layout.
- Sprite rendering for movable objects or enemies.
- Smooth animations for player or environment.
- Additional keyboard controls or mouse input handling.


## Credits

- Author: [Nicolas Fromont, alias nifromon] and [Yanis seguin, alias yseguin].
- Inspired by Wolfenstein 3D and the 42 School curriculum.

