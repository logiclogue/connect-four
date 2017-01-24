#include <stdlib.h>
#include "LineChecker.h"
#include "Class.h"

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
}

void LineChecker_destroy(LineChecker *self)
{
    free(self);
}

int LineChecker_is_line(LineChecker *self)
{
    return 0;
}

static int is_horizontal_line(LineChecker *self)
{
    int column, row, i;
    int max_column = self->columns - self->length;
    int max_row = self->rows;
    char piece;
    char current_piece;

    for (column = 0; column < max_column; column++) {
        for (row = 0; row < max_row; row++) {
            piece = self->grid->get(column, row);

            for (i = 0; i < self->length; i++) {
                current_piece = self->grid->get(column + i, row);

                if (current_piece != piece) {
                    break;
                }
            }
        }
    }

    return 0;
}
