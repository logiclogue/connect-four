#ifndef LINE_CHECKER_H
#define LINE_CHECKER_H

#include "Grid.h"

#define LINE_CHECKER_PROPS(self_t) \
    Grid *grid; \
    int length; \
    int (*is_line)(self_t *self);

typedef struct _LineChecker LineChecker;

struct _LineChecker {
    CLASS_PROPS(LineChecker)
    LINE_CHECKER_PROPS(LineChecker)
};

LineChecker *LineChecker_new(Grid *grid, int length);
LineChecker *LineChecker_new_default(void);
void LineChecker_apply(LineChecker *self);
void LineChecker_destroy(LineChecker *self);
int LineChecker_is_line(LineChecker *self);

#endif
