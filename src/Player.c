#include <stdlib.h>
#include "Player.h"

static int make_move(Player *self, int column);
static int move_valid(Player *self, int column);

Player *Player_new(void)
{
    Player *self = malloc(sizeof(Player));

    self->make_move = make_move;
    self->move_valid = move_valid;

    return self;
}

static int make_move(Player *self, int column)
{
    return 0;
}

static int move_valid(Player *self, int column)
{
    return 0;
}
