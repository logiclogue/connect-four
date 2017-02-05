#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Game.h"

Game *Game_new(Player *player_1, Player *player_2)
{
    Game *self = CLASS_MALLOC(Game);

    self->board = Board_new(7, 6);

    int board_squares = self->board->rows * self->board->columns;

    self->player_1 = player_1;
    self->player_2 = player_2;
    self->player_to_move = player_1;
    self->record = malloc(board_squares * sizeof(char));
    self->move = 0;

    Game_apply(self);

    return self;
}

Game *Game_new_default(void)
{
    Player *player_1 = Player_new();
    Player *player_2 = Player_new();

    return Game_new(player_1, player_2);
}

void Game_apply(Game *self)
{
    self->new = Game_new_default;
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
    int column_isnt_valid = !board->is_column_valid(board, column);
    int isnt_players_move = player != self->player_to_move;

    if (column_isnt_valid || isnt_players_move) {
        return 0;
    }

    return 1;
}
