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
        self->player_1 = Player_new(self);
    } else {
        self->player_1 = player_1;
    }

    if (player_2 == NULL) {
        self->player_2 = Player_new(self);
    } else {
        self->player_2 = player_2;
    }

    if (board == NULL) {
        self->board = Board_new_default();
    } else {
        self->board = board;
    }

    if (line_checker == NULL) {
        self->line_checker = LineChecker_new((Grid *)self->board, 4);
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
    self->is_game_over = Game_is_game_over;
    self->is_win = Game_is_win;
    self->is_draw = Game_is_draw;
    self->get_winner = Game_get_winner;
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
    int is_game_over = self->is_game_over(self);

    if (column_isnt_valid || isnt_players_move || is_game_over) {
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

int Game_is_game_over(Game *self)
{
    int is_win = self->line_checker->is_line(self->line_checker);
    int is_full = self->board->is_full(self->board);

    return is_win || is_full;
}

int Game_is_win(Game *self)
{
    return self->line_checker->is_line(self->line_checker);
}

int Game_is_draw(Game *self)
{
    int isnt_line = !self->line_checker->is_line(self->line_checker);
    int is_full = self->board->is_full(self->board);

    return isnt_line && is_full;
}

Player *Game_get_winner(Game *self)
{
    int is_win = self->is_win(self);
    int is_player_1_winner = self->player_to_move == self->player_2;

    if (is_win && is_player_1_winner) {
        return self->player_1;
    } else if (is_win) {
        return self->player_2;
    }

    return NULL;
}
