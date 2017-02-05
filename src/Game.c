#include <stdlib.h>
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include "LineChecker.h"

static void switch_player_to_move(Game *self);

Game *Game_new(
    Player *player_1,
    Player *player_2,
    Board *board,
    LineChecker *line_checker)
{
    Game *self = CLASS_MALLOC(Game);
    int board_squares;

    if (player_1 == NULL) {
        self->player_1 = Player_new();
    } else {
        self->player_1 = player_1;
    }

    if (player_2 == NULL) {
        self->player_2 = Player_new();
    } else {
        self->player_2 = player_2;
    }

    if (board == NULL) {
        self->board = Board_new_default();
    } else {
        self->board = board;
    }

    if (line_checker == NULL) {
        self->line_checker = LineChecker_new_default();
    } else {
        self->line_checker = line_checker;
    }

    board_squares = self->board->rows * self->board->columns;

    self->player_to_move = player_1;
    self->record = malloc(board_squares * sizeof(char));
    self->move = 0;

    Game_apply(self);

    return self;
}

Game *Game_new_default(void)
{
    return Game_new(NULL, NULL, NULL, NULL);
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

    switch_player_to_move(self);

    return 1;
}

static void switch_player_to_move(Game *self)
{
    if (self->player_to_move == self->player_1) {
        self->player_to_move = self->player_2;
    } else {
        self->player_to_move = self->player_1;
    }
}
