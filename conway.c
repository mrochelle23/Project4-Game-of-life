#include <stdio.h>
#include <stdlib.h>
#include "board.h"

// Function to free the memory allocated for the board
void free_board(Board *board) {
    for (int i = 0; i < board->nrows; i++) {
        free(board->grid[i]);
    }
    free(board->grid);
    free(board);
}

int main() {
    int nrows, ncols, timesteps;
    scanf("%d %d", &nrows, &ncols);
    scanf("%d", &timesteps);

    // Allocate memory for the board
    Board *board = malloc(sizeof(Board));
    board->nrows = nrows;
    board->ncols = ncols;
    board->grid = malloc(sizeof(char*) * nrows);
    for (int i = 0; i < nrows; i++) {
        board->grid[i] = malloc(sizeof(char) * ncols);
        for (int j = 0; j < ncols; j++) {
            scanf(" %c", &board->grid[i][j]);
        }
    }

    // Evolve the board for the specified number of timesteps
    for (int t = 0; t < timesteps; t++) {
        Board *new_board = update_board(board);
        free_board(board);
        board = new_board;
    }

    // Count the number of green and red cells
    int green_count = 0, red_count = 0;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (board->grid[i][j] == 'g') {
                green_count++;
            } else if (board->grid[i][j] == 'r') {
                red_count++;
            }
        }
    }

    // Print the counts
    printf("green: %d, red: %d\n", green_count, red_count);

    // Free the memory allocated for the board
    free_board(board);
    return 0;
}
