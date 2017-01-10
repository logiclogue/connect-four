#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Game.h"

Game *Game_new(Player *player_1, Player *player_2)
{
    Game *self = malloc(sizeof(Game));

    self->player_1 = player_1;
    self->player_2 = player_2;
    self->board = Board_new();

    return self;
}
