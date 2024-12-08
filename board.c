#include <stdlib.h>
#include "board.h"

// Function to calculate the new color of a cell based on its neighbors
char cell_color(Board *board, int row, int col) {
    int green_count = 0, red_count = 0, live_neighbors = 0;
    int nrows = board->nrows, ncols = board->ncols;
    char **grid = board->grid;

    // Directions for the 8 neighbors
    int directions[8][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };

    // Count the live neighbors and their colors
    for (int i = 0; i < 8; i++) {
        int new_row = (row + directions[i][0] + nrows) % nrows;
        int new_col = (col + directions[i][1] + ncols) % ncols;
        if (grid[new_row][new_col] == 'g') {
            green_count++;
            live_neighbors++;
        } else if (grid[new_row][new_col] == 'r') {
            red_count++;
            live_neighbors++;
        }
    }

    // Apply the rules of the game
    if (grid[row][col] == 'x') {
        if (live_neighbors == 3) {
            return green_count > red_count ? 'g' : 'r';
        } else {
            return 'x';
        }
    } else {
        if (live_neighbors < 2 || live_neighbors > 3) {
            return 'x';
        } else {
            return grid[row][col];
        }
    }
}

// Function to update the board to the next state
Board* update_board(Board *board) {
    Board *new_board = malloc(sizeof(Board));
    new_board->nrows = board->nrows;
    new_board->ncols = board->ncols;
    new_board->grid = malloc(sizeof(char*) * new_board->nrows);
    for (int i = 0; i < new_board->nrows; i++) {
        new_board->grid[i] = malloc(sizeof(char) * new_board->ncols);
    }

    for (int i = 0; i < new_board->nrows; i++) {
        for (int j = 0; j < new_board->ncols; j++) {
            new_board->grid[i][j] = cell_color(board, i, j);
        }
    }

    return new_board;
}
