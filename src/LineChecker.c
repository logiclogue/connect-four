#include <stdlib.h>
#include "LineChecker.h"
#include "Class.h"

LineChecker *LineChecker_new(Board *board)
{
    LineChecker *self = CLASS_MALLOC(LineChecker);

    self->board = board;

    Class_apply((Class *)self);
    LineChecker_apply(self);

    return self;
}

LineChecker *LineChecker_new_default(void)
{
    return LineChecker_new(NULL);
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
