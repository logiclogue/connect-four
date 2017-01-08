#include <stdlib.h>
#include "Board.h"

static void allocate_state(Board *self);
static int input(Board *self, char column, char colour);

Board *Board_new(void)
{
    Board *self = malloc(sizeof(Board));

    allocate_state(self);

    self->input = input;

    return self;
}

static int input(Board *self, char column, char colour)
{
    int is_column_full = self->state[column][BOARD_ROWS] != " ";
    int is_valid_column = column >= 0 && column < BOARD_COLUMNS;

    if (is_column_full && is_valid_row) {
        return 0;
    }

    int x;
    char current_square;

    for(y = 0; y < BOARD_ROWS; y++) {
        current_square = self->state[column][y];

        if (current_square != " ")
        {
            continue;
        }

        self->state[column][y] = colour;

        break;
    }

    return 1;
}

static void allocate_state(Board *self)
{
    self->state = malloc(BOARD_COLUMNS * sizeof(char *));

    int x, y;

    for (x = 0; x < BOARD_COLUMNS; x++) {
        self->state[x] = malloc(BOARD_ROWS * sizeof(char));

        for (y = 0; y < BOARD_ROWS; y++) {
            self->state[x][y] = " ";
        }
    }
}
