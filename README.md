# Welcome to SO_LONG project 🦖 (School 21)

### Project finished (125%)

This project is a small 2D game with minilibx (graphic library made by school21), 
where the player has to pick all collectibles and go the exit making as few as possible moves. 
This game is about a dino in the desert who collects water drops to drink from a puddle. 
The project only works on MacOS, so make sure you have installed the required 
elements to run the minilibx: dynamic lmx library is located in the mlx folder.

---
<img src="https://github.com/Vlad173/so_long/blob/master/images/dino.gif" width="800" />


# Installation

1. Clone the repository:
```sh
git clone git@github.com:Vlad173/so_long.git
```
2. Make to create the **mandatory** so_long program:
```sh
make
```
Make bonus to create the so_long program **with bonuses** (animation, score on screen, enemies):
```sh
make fclean
make bonus
```
3. And launch the game
```sh
./so_long [map]
```

## How to play

Use ``WASD`` or arrows to move. 

The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
| H | Horizontal enemy. It moves to left and right, changing direction when its path is blocked. |
| V | Vertical enemy. Moving up and down. |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

See some examples in the ``maps`` folder of this project.

## Subject

* You can view the task [*here*](https://cdn.intra.42.fr/pdf/pdf/37735/en.subject.pdf)
