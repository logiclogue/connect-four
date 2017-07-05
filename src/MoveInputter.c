#include <stdlib.h>
#include <string.h>
#include "MoveInputter.h"
#include "Game.h"
#include "Class.h"

static int convert_char_to_int(char number);

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
    int length = strlen(notation);
    int i;
    int column;

    for (i = 0; i < length; i += 1) {
        column = convert_char_to_int(notation[i]);

        self->game->input_move(self->game, self->game->player_1, column);
    }

    return 1;
}

int static convert_char_to_int(char number)
{
    return (char)number - 48;
}
