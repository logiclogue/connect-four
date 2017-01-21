#include <stdlib.h>
#include "Grid.h"
#include "Class.h"

static void allocate_grid(Grid *self);
static void destroy_grid(Grid *self);

Grid *Grid_new(int columns, int rows)
{
    Grid *self = CLASS_MALLOC(Grid);

    allocate_grid(self);

    self->columns = columns;
    self->rows = rows;
    self->empty_square = ' ';

    Grid_apply(self);

    return self;
}

Grid *Grid_new_default(void)
{
    return Grid_new(7, 6);
}

void Grid_apply(Grid *self)
{
    self->new = Grid_new_default;
    self->apply = Grid_apply;
    self->destroy = Grid_destroy;
}

void Grid_destroy(Grid *self)
{
    destroy_grid(self);

    free(self);
}

static void allocate_grid(Grid *self)
{
    self->grid = malloc(self->columns * sizeof(char *));

    int x, y;

    for (x = 0; x < self->columns; x++) {
        self->grid[x] = malloc(self->rows * sizeof(char));

        for (y = 0; y < self->rows; y++) {
            self->grid[x][y] = self->empty_square;
        }
    }
}

static void destroy_grid(Grid *self)
{
    int x;

    for (x = 0; x < self->columns; x++) {
        free(self->grid[x]);
    }

    free(self->grid);
}
