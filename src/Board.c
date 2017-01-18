#include <stdlib.h>
#include "Board.h"

static void allocate_state(Board *self);

Board *Board_new(int columns, int rows)
{
    Board *self = CLASS_MALLOC(Board);

    allocate_state(self);

    self->columns = columns;
    self->rows = rows;
    self->input = Board_input;
    self->is_column_valid = Board_is_column_valid;

    return self;
}

int Board_input(Board *self, int column, char colour)
{
    int is_column_valid = self->is_column_valid(self, column);
    char *current_column = self->state[column];

    if (is_column_valid) {
        return 0;
    }

    int y;
    char current_square;

    for (y = 0; y < self->rows; y++) {
        current_square = current_column[y];

        if (current_square != BOARD_EMPTY_TOKEN) {
            continue;
        }

        current_column[y] = colour;

        break;
    }

    return 1;
}

int Board_is_column_valid(Board *self, int column)
{
    int current_square = self->state[column][self->rows];
    int is_column_not_full = current_square == BOARD_EMPTY_TOKEN;
    int is_column_in_range = column >= 0 && column < self->columns;

    return is_column_not_full && is_column_in_range;
}

static void allocate_state(Board *self)
{
    self->state = malloc(self->columns * sizeof(char *));

    int x, y;

    for (x = 0; x < self->columns; x++) {
        self->state[x] = malloc(self->rows * sizeof(char));

        for (y = 0; y < self->rows; y++) {
            self->state[x][y] = BOARD_EMPTY_TOKEN;
        }
    }
}
