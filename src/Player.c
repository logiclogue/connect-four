#include <stdlib.h>
#include "Class.h"
#include "Player.h"

Player *Player_new(Game *game)
{
    Player *self = CLASS_MALLOC(Player);

    Class_apply((Class *)self);
    Player_apply(self);

    self->game = game;

    return self;
}

Player *Player_new_default(void)
{
    return Player_new(NULL);
}

void Player_destroy(Player *self)
{
    self->game->destroy(self->game);

    free(self);
}

void Player_apply(Player *self)
{
    self->new = Player_new_default;
    self->apply = Player_apply;
    self->input_move = Player_input_move;
    self->move_valid = Player_move_valid;
}

int Player_input_move(Player *self, int column)
{
    Game *game = self->game;

    return game->move_valid(game, self, column);
}

int Player_move_valid(Player *self, int column)
{
    Game *game = self->game;

    return game->move_valid(game, self, column);
}
