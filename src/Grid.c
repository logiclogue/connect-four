#include <stdlib.h>
#include "Grid.h"
#include "Class.h"

static void allocate_grid(Grid *self);
static void destroy_grid(Grid *self);

Grid *Grid_new(int columns, int rows)
{
    Grid *self = CLASS_MALLOC(Grid);

    Grid_apply(self, columns, rows);

    return self;
}

Grid *Grid_new_default(void)
{
    return Grid_new(7, 6);
}

void Grid_apply(Grid *self, int columns, int rows)
{
    allocate_grid(self);

    self->columns = columns;
    self->rows = rows;
    self->empty_square = ' ';

    Grid_apply_default(self);
}

void Grid_apply_default(Grid *self)
{
    self->new = Grid_new_default;
    self->apply = Grid_apply_default;
    self->destroy = Grid_destroy;
    self->get = Grid_get;
    self->set = Grid_set;
    self->is_in_range = Grid_is_in_range;
}

void Grid_destroy(Grid *self)
{
    destroy_grid(self);

    free(self);
}

char Grid_get(Grid *self, int column, int row)
{
    if (self->is_in_range(self, column, row))
    {
        return self->grid[column][row];
    }

    return self->empty_square;
}

int Grid_set(Grid *self, int column, int row, char piece)
{
    if (!self->is_in_range(self, column, row))
    {
        return 0;
    }

    self->grid[column][row] = piece;

    return 1;
}

int Grid_is_in_range(Grid *self, int column, int row)
{
    int is_column_in_range = column >= 0 && column < self->columns;
    int is_row_in_range = row >= 0 && row < self->rows;

    return is_column_in_range && is_row_in_range;
}

static void allocate_grid(Grid *self)
{
    self->grid = malloc(self->columns * sizeof(char *));

    int column, row;

    for (column = 0; column < self->columns; column++) {
        self->grid[column] = malloc(self->rows * sizeof(char));

        for (row = 0; row < self->rows; row++) {
            self->grid[column][row] = self->empty_square;
        }
    }
}

static void destroy_grid(Grid *self)
{
    int column;

    for (column = 0; column < self->columns; column++) {
        free(self->grid[column]);
    }

    free(self->grid);
}
