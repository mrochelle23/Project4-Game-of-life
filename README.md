# Conway's Game of Life - Multi-Player Version

## Overview

This project implements a multi-player version of Conway's Game of Life. Conway's Game of Life is a cellular automaton where the state of the game evolves based on an initial configuration. In this version, live cells can be different colors, specifically green and red.

## Rules

The game is played on a two-dimensional grid filled with cells. Each cell can be in one of three states:
- `g`: Alive and green
- `r`: Alive and red
- `x`: Dead

The state of the grid evolves over time based on the following rules:
1. **Overpopulation**: A cell with more than 3 live neighbors dies.
2. **Underpopulation**: A cell with fewer than 2 live neighbors dies.
3. **Existing**: A cell with 2 or 3 live neighbors continues to exist.
4. **Birth**: A dead cell with 3 live neighbors becomes alive. It takes the color of the majority of its living neighbors.

The grid is periodic, meaning it wraps around at the edges.

## Project Structure

- `board.h`: Header file containing the definition of the `Board` struct and function prototypes.
- `board.c`: Implementation of the functions to update the board and calculate the new state of each cell.
- `conway.c`: Main program that reads the initial grid configuration, evolves the grid for a specified number of timesteps, and outputs the final counts of green and red cells.
- `Makefile`: Makefile to compile the program.

## Compilation and Execution

### Prerequisites

- GCC (GNU Compiler Collection)

### Compilation

To compile the program, run the following command:

```sh
make
```

This will compile the source files and create an executable named 
`conway.out`.

### Execution

To run the program, use the following command:
```bash
./conway.out
```

The program expects input in the following format:
```bash
<number_of_rows> <number_of_columns>
<number_of_timesteps>
<initial_grid>
```

Example input:
```bash
5 4
1
g x x r
r x g g
x x r x
r g x r
x r x x
```

### Output
After evolving the grid for the specified number of timesteps, the program outputs the counts of green and red cells in the following format:
```bash
green: <count_of_green_cell>, red: <count_of_red_cells>
```

Example output:
```bash
green: 2, red: 4
```

### Example
#### Input
```bash
5 4
1
g x x r
r x g g
x x r x
r g x r
x r x x
```

### Output
```bash
green: 2, red: 4
```

### Cleaning Up
To remove the compiled executable, run the following command:
```sh
make clean
```
