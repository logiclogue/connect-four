#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Game.h"

static int input_move(self_t *self, Player *player, int column);

Game *Game_new(Player *player_1, Player *player_2)
{
    Game *self = malloc(sizeof(Game));

    self->player_1 = player_1;
    self->player_2 = player_2;
    self->player_to_move = player_1;
    self->board = Board_new();
    self->record = malloc(BOARD_SQUARES * sizeof(char));
    self->move = 0;
    self->input_move = input_move;

    return self;
}

static int input_move(self_t *self, Player *player, int column)
{
    Board *board = self->board;
    int is_column_valid = board->is_column_valid(board, column);

    if (is_column_valid) {
        return 0;
    }

    return 1;
}
