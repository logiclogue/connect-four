#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Game.h"

Game *Game_new(void)
{
    Game *self = malloc(sizeof(Game));

    self->board = Board_new(7, 6);

    int board_squares = self->board->rows * self->board->columns;

    self->player_1 = Player_new();
    self->player_2 = Player_new();
    self->player_to_move = self->player_1;
    self->record = malloc(board_squares * sizeof(char));
    self->move = 0;

    Game_apply(self);

    return self;
}

void Game_apply(Game *self)
{
    self->new = Game_new;
    self->apply = Game_apply;
    self->destroy = Game_destroy;
    self->input_move = Game_input_move;
}

void Game_destroy(Game *self)
{
    self->player_1->destroy(self->player_1);
    self->player_2->destroy(self->player_2);

    free(self->record);
    free(self);
}

int Game_input_move(Game *self, Player *player, int column)
{
    Board *board = self->board;
    int is_column_valid = board->is_column_valid(board, column);

    if (is_column_valid) {
        return 0;
    }

    return 1;
}
