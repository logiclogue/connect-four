#include <stdlib.h>
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
    return "";
}

char *GridToString_get_row(GridToString *self, int column)
{
    return "";
}

char GridToString_get_char(GridToString *self, void *player_ptr)
{
    return self->empty_char;
}
