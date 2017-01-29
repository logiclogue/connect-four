#include <stdlib.h>
#include "LineChecker.h"
#include "Class.h"

static int check_line(LineChecker *self, int delta_column, int delta_row);
static int get_maximum(LineChecker *self, int count, int delta);
static int get_minimum(LineChecker *self, int delta);

LineChecker *LineChecker_new(Grid *grid, int length)
{
    LineChecker *self = CLASS_MALLOC(LineChecker);

    self->grid = grid;
    self->length = length;

    Class_apply((Class *)self);
    LineChecker_apply(self);

    return self;
}

LineChecker *LineChecker_new_default(void)
{
    return LineChecker_new(NULL, 4);
}

void LineChecker_apply(LineChecker *self)
{
    self->new = LineChecker_new_default;
    self->apply = LineChecker_apply;
    self->is_line = LineChecker_is_line;
    self->is_horizontal_line = LineChecker_is_horizontal_line;
    self->is_vertical_line = LineChecker_is_vertical_line;
    self->is_positive_diagonal_line = LineChecker_is_positive_diagonal_line;
    self->is_negative_diagonal_line = LineChecker_is_negative_diagonal_line;
}

void LineChecker_destroy(LineChecker *self)
{
    free(self);
}

int LineChecker_is_line(LineChecker *self)
{
    return
        self->is_horizontal_line(self) ||
        self->is_vertical_line(self) ||
        self->is_positive_diagonal_line(self) ||
        self->is_negative_diagonal_line(self);
}

int LineChecker_is_horizontal_line(LineChecker *self)
{
    return check_line(self, 1, 0);
}

int LineChecker_is_vertical_line(LineChecker *self)
{
    return check_line(self, 0, 1);
}

int LineChecker_is_positive_diagonal_line(LineChecker *self)
{
    return check_line(self, 1, 1);
}

int LineChecker_is_negative_diagonal_line(LineChecker *self)
{
    return check_line(self, 1, -1);
}

static int check_line(LineChecker *self, int delta_column, int delta_row)
{
    int column, row, i, is_same_piece, testing_column, testing_row;
    int max_column = get_maximum(self, self->grid->columns, delta_column);
    int max_row = get_maximum(self, self->grid->rows, delta_row);
    int min_column = get_minimum(self, delta_column);
    int min_row = get_minimum(self, delta_row);
    char piece, current_piece;

    for (column = min_column; column <= max_column; column += 1) {
        for (row = min_row; row <= max_row; row += 1) {
            piece = self->grid->get(self->grid, column, row);

            for (i = 0; i < self->length; i += 1) {
                testing_column = column + (delta_column * i);
                testing_row = column + (delta_row * i);
                current_piece = self->grid->get(
                    self->grid, testing_column, testing_row);
                is_same_piece = current_piece != piece;

                if (!is_same_piece) {
                    break;
                }
            }

            if (is_same_piece) {
                return 1;
            }
        }
    }

    return 0;
}

static int get_maximum(LineChecker *self, int count, int delta)
{
    if (delta <= 0) {
        return count;
    }

    return count - (delta * self->length);
}

static int get_minimum(LineChecker *self, int delta)
{
    if (delta >= 0) {
        return 0;
    }

    return (-delta * self->length);
}
