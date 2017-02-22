#include <stdlib.h>
#include <string.h>
#include "GridToString.h"

GridToString *GridToString_new(
    Grid *grid,
    Player *player_1_ptr,
    Player *player_2_ptr)
{
    GridToString *self = CLASS_MALLOC(GridToString);

    self->grid = grid;
    self->player_1_ptr = player_1_ptr;
    self->player_2_ptr = player_2_ptr;
    self->player_1_char = 'X';
    self->player_2_char = 'O';
    self->empty_char = ' ';

    GridToString_apply(self);

    return self;
}

GridToString *GridToString_new_default(void)
{
    return GridToString_new(NULL, NULL, NULL);
}

void GridToString_apply(GridToString *self)
{
    self->new = GridToString_new_default;
    self->apply = GridToString_apply;
    self->destroy = (void *)Class_destroy;
    self->get = GridToString_get;
    self->get_row = GridToString_get_row;
    self->get_char = GridToString_get_char;
}

char *GridToString_get(GridToString *self)
{
    int size = self->grid->rows * (self->grid->columns + 2);
    char *output = malloc(sizeof(char) * size);
    int y = self->grid->rows - 1;

    for (; y >= 0; y -= 1) {
        strcat(output, self->get_row(self, y));
        strcat(output, "\n");
    }

    return output;
}

char *GridToString_get_row(GridToString *self, int row)
{
    char *output = malloc(sizeof(char) * self->grid->columns);
    Grid *grid = self->grid;
    int columns = grid->columns;
    int x;
    void *current_ptr;

    for (x = 0; x < columns; x += 1) {
        current_ptr = grid->get(grid, x, row);
        output[x] = self->get_char(self, current_ptr);
    }

    return output;
}

char GridToString_get_char(GridToString *self, void *player_ptr)
{
    if (player_ptr == self->player_1_ptr) {
        return self->player_1_char;
    } else if (player_ptr == self->player_2_ptr) {
        return self->player_2_char;
    }

    return self->empty_char;
}
