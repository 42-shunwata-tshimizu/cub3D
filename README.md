*This project has been created as part of the 42 curriculum by tshimizu, shunwata.*

# cub3D

## Description

cub3D is a simple 3D game engine inspired by the early raycasting technology used in games such as Wolfenstein 3D.

The objective of this project is to learn the fundamentals of computer graphics, mathematical vector operations, and real-time rendering by implementing a raycasting engine from scratch using MiniLibX.

The program reads a `.cub` configuration file containing:

* Map layout
* Player spawn position and orientation
* Wall textures
* Floor and ceiling colors

The engine then renders a pseudo-3D view of the world and allows the player to move and rotate inside the map.

### Main Features

* Raycasting-based 3D rendering
* Textured walls
* Player movement (W, A, S, D)
* Camera rotation
* Collision detection
* Configurable maps through `.cub` files
* Floor and ceiling coloring
* Minimap (if implemented)

---

## Project Structure

```text
.
├── .github/
│   └── workflows/
│       └── norminette.yml
├── includes/
│   ├── cub3d.h
│   ├── draw.h
│   ├── engine.h
│   ├── game.h
│   ├── input.h
│   ├── parse.h
│   ├── read.h
│   ├── utils.h
│   └── validation.h
├── libs/
│   ├── Libft/
│   └── minilibx-linux/
├── objs/
│   ├── draw/
│   ├── engine/
│   ├── input/
│   ├── parse/
│   ├── read/
│   ├── utils/
│   └── validation/
├── resource/
│   ├── settings/
│   │   └── test.cub
│   └── textures/
├── srcs/
│   ├── draw/
│   ├── engine/
│   ├── input/
│   ├── main.c
│   ├── parse/
│   ├── read/
│   ├── run_game.c
│   ├── setup_game.c
│   └── utils/
├── Makefile
└── README.md
```

---

## How Raycasting Works

The rendering engine uses the raycasting technique.

For each vertical column of pixels:

1. A ray is cast from the player's position.
2. DDA (Digital Differential Analysis) is used to find the first wall hit.
3. The distance to the wall is calculated.
4. The wall height is projected onto the screen.
5. The corresponding texture column is sampled.
6. Pixels are drawn to the frame buffer.

This creates the illusion of a 3D environment while operating on a 2D map.

---

## Instructions

### Requirements

* Linux
* GCC
* Make
* MiniLibX

### Compilation

```bash
make
```

### Clean Object Files

```bash
make clean
```

### Remove All Generated Files

```bash
make fclean
```

### Rebuild

```bash
make re
```

### Run

```bash
./cub3D maps/example.cub
```

---

## Controls

| Key | Action        |
| --- | ------------- |
| W   | Move Forward  |
| S   | Move Backward |
| A   | Strafe Left   |
| D   | Strafe Right  |
| ←   | Rotate Left   |
| →   | Rotate Right  |
| ESC | Exit          |

---

## Technical Choices

### Rendering

* Raycasting
* DDA algorithm
* Perspective projection

### Graphics

* MiniLibX
* Off-screen image buffer
* Texture sampling

### Architecture

The project is organized by responsibility:

* Parsing
* Validation
* Rendering
* Player movement
* Texture management
* Utilities

This separation helps maintain readability and makes debugging easier.

---

## Learning Objectives

Through this project, we learned:

* Computer graphics fundamentals
* Raycasting algorithms
* Vector mathematics
* Collision detection
* Texture mapping
* Event-driven programming
* Memory management in C
* Software architecture and modular design

---

## Resources

### Raycasting

- https://lodev.org/cgtutor/raycasting.html

- https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

- https://qiita.com/susasaki/items/c74a228d7ddd48b818bd

- https://www.youtube.com/watch?v=NbSee-XM7WA

### MiniLibX

- MiniLibX Documentation
  https://harm-smits.github.io/42docs/libs/minilibx

### 42 Resources

- 42 Subject PDF
- Peer evaluations

---

## AI Usage

Artificial Intelligence tools were used as learning assistants during the development of this project.

### Tasks Assisted

* Understanding raycasting concepts
* Learning DDA algorithm behavior
* Explaining vector mathematics and trigonometry
* Reviewing architecture and code organization ideas

### Tasks Implemented Independently

* Project architecture
* Parsing implementation
* Validation logic
* Rendering engine
* Player movement
* Texture mapping
* Memory management
* Debugging and testing

All code was reviewed, understood, and integrated by the authors.
