#ifndef MOVE_INPUTTER_H
#define MOVE_INPUTTER_H

#include "Game.h"
#include "Class.h"

#define MOVE_INPUTTER_PROPS(self_t) \
    Game *game; \
    int (*input_from_notation)();

typedef struct _MoveInputter MoveInputter;

struct _MoveInputter {
    CLASS_PROPS(MoveInputter)
    MOVE_INPUTTER_PROPS(MoveInputter)
};

MoveInputter *MoveInputter_new(Game *game);
MoveInputter *MoveInputter_new_default(void);
void MoveInputter_apply(MoveInputter *self);
void MoveInputter_destroy(MoveInputter *self);
int MoveInputter_input_from_notation(MoveInputter *self, char *notation);

#endif
