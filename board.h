#ifndef BOARD_H
#define BOARD_H

typedef struct {
    char **grid;
    int nrows;
    int ncols;
} Board;

Board* update_board(Board *);
char cell_color(Board *board, int row, int col);

#endif // BOARD_H
