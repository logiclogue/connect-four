#include <stdlib.h>
#include "Class.h"
#include "Player.h"

static int input_move(Player *self, int column);
static int move_valid(Player *self, int column);

Player *Player_new(void)
{
    Player *self = malloc(sizeof(Player));

    Class_apply((Class *)self);

    self->input_move = input_move;
    self->move_valid = move_valid;

    return self;
}

static int input_move(Player *self, int column)
{
    return 0;
}

static int move_valid(Player *self, int column)
{
    return 0;
}
