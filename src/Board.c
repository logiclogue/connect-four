#include <stdlib.h>
#include "Board.h"

static int input(Board *self, int column, char colour);
static void allocate_state(Board *self);
static int is_column_valid(Board *self, int column);

Board *Board_new(void)
{
    Board *self = malloc(sizeof(Board));

    allocate_state(self);

    self->input = input;
    self->is_column_valid = is_column_valid;

    return self;
}

static int input(Board *self, int column, char colour)
{
    int is_column_valid = self->is_column_valid(self, column);
    char *current_column = self->state[column];

    if (is_column_valid) {
        return 0;
    }

    int y;
    char current_square;

    for (y = 0; y < BOARD_ROWS; y++) {
        current_square = current_column[y];

        if (current_square != BOARD_EMPTY_TOKEN)
        {
            continue;
        }

        current_column[y] = colour;

        break;
    }

    return 1;
}

static int is_column_valid(Board *self, int column)
{
    int current_square = self->state[column][BOARD_ROWS];
    int is_column_not_full = current_square == BOARD_EMPTY_TOKEN;
    int is_column_in_range = column >= 0 && column < BOARD_COLUMNS;

    return is_column_not_full && is_column_in_range;
}

static void allocate_state(Board *self)
{
    self->state = malloc(BOARD_COLUMNS * sizeof(char *));

    int x, y;

    for (x = 0; x < BOARD_COLUMNS; x++) {
        self->state[x] = malloc(BOARD_ROWS * sizeof(char));

        for (y = 0; y < BOARD_ROWS; y++) {
            self->state[x][y] = BOARD_EMPTY_TOKEN;
        }
    }
}
