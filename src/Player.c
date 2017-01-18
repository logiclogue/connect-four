#include <stdlib.h>
#include "Class.h"
#include "Player.h"

Player *Player_new(void)
{
    Player *self = malloc(sizeof(Player));

    Class_apply((Class *)self);

    self->input_move = Player_input_move;
    self->move_valid = Player_move_valid;

    return self;
}

int Player_input_move(Player *self, int column)
{
    return 0;
}

int Player_move_valid(Player *self, int column)
{
    return 0;
}
