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
    return column * colour;
}

static void allocate_state(Board *self)
{
    self->state = malloc(BOARD_COLUMNS * sizeof(char *));

    int x, y;

    for (x = 0; x < BOARD_COLUMNS; x++)
    {
        self->state[x] = malloc(BOARD_ROWS * sizeof(char));
    }
}
