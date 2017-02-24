#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"
#include "Class.h"
#include "LineChecker.h"

#define GAME_PROPS(self_t) \
    int *record; \
    int move; \
    Player *player_1; \
    Player *player_2; \
    Player *player_to_move; \
    Board *board; \
    LineChecker *line_checker; \
    int (*input_move)(); \
    int (*move_valid)(); \
    int (*is_game_over)(); \
    Player *(*get_winner)(); \
    int (*is_win)(); \
    int (*is_draw)();

typedef struct _Game Game;
typedef struct _Player Player;

struct _Game {
    CLASS_PROPS(Game)
    GAME_PROPS(Game)
};

Game *Game_new(
    Player *player_1,
    Player *player_2,
    Board *board,
    LineChecker *line_checker);
Game *Game_new_default(void);
void Game_apply(Game *self);
void Game_destroy(Game *self);
int Game_input_move(Game *self, Player *player, int column);
int Game_move_valid(Game *self, Player *player, int column);
int Game_is_game_over(Game *self);
Player *Game_get_winner(Game *self);
int Game_is_win(Game *self);
int Game_is_draw(Game *self);

#endif
