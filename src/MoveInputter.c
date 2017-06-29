#include <stdlib.h>
#include "MoveInputter.h"
#include "Game.h"
#include "Class.h"

MoveInputter *MoveInputter_new(Game *game)
{
    MoveInputter *self = CLASS_MALLOC(MoveInputter);

    if (game == NULL) {
        self->game = Game_new_default();
    } else {
        self->game = game;
    }

    MoveInputter_apply(self);

    return self;
}

MoveInputter *MoveInputter_new_default(void)
{
    return MoveInputter_new(NULL);
}

void MoveInputter_apply(MoveInputter *self)
{
    self->new = MoveInputter_new_default;
    self->apply = MoveInputter_apply;
    self->destroy = MoveInputter_destroy;
    self->input_from_notation = MoveInputter_input_from_notation;
}

void MoveInputter_destroy(MoveInputter *self)
{
    free(self);
}

int MoveInputter_input_from_notation(MoveInputter *self, char *notation)
{
    self->game->input_move(self->game, self->game->player_1, 0);

    return 1;
}
