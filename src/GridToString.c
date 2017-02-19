#include "GridToString.h"

GridToString *GridToString_new(
    Grid *grid,
    Player *player_1_ptr,
    Player *player_2_ptr);
{
    GridToString *self = CLASS_MALLOC(GridToString);

    self->grid = grid;
    self->player_1_ptr = player_1_ptr;
    self->player_2_ptr = player_2_ptr;

    return self;
}

GridToString *GridToString_new_default(void)
{
    return GridToString_new(NULL, NULL, NULL);
}
