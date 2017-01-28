#include <stdlib.h>
#include "Class.h"
#include "Grid.h"
#include "Board.h"

Board *Board_new(int columns, int rows)
{
    Board *self = CLASS_MALLOC(Board);

    Grid_apply((Grid *)self, columns, rows);
    Board_apply(self);

    return self;
}

Board *Board_new_default(void)
{
    return Board_new(7, 6);
}

void Board_apply(Board *self)
{
    self->new = Board_new_default;
    self->apply = Board_apply;
    self->destroy = Board_destroy;
    self->input = Board_input;
    self->is_column_valid = Board_is_column_valid;
}

void Board_destroy(Board *self)
{
    Grid_destroy((Grid *)self);
}

int Board_input(Board *self, int column, char piece)
{
    int is_not_column_valid = !self->is_column_valid(self, column);
    char *current_column = self->grid[column];

    if (is_not_column_valid) {
        return 0;
    }

    int row;
    char current_square;

    for (row = 0; row < self->rows; row += 1) {
        current_square = current_column[row];

        if (current_square == self->empty_square) {
            current_column[row] = piece;
        }
    }

    return 1;
}

int Board_is_column_valid(Board *self, int column)
{
    int last_row = self->rows - 1;
    int current_square = self->get(self, column, last_row);
    int is_column_not_full = current_square == self->empty_square;
    int is_column_in_range = self->is_in_range(self, column, last_row);

    return is_column_not_full && is_column_in_range;
}
