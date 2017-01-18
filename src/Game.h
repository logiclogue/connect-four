#ifndef GAME_H
#define GAME_H

#include "Class.h"

#define GAME_PROPS(self_t) \
    char *record; \
    int move; \
    Player *player_1; \
    Player *player_2; \
    Player *player_to_move; \
    Board *board; \
    int (*input_move)(self_t *self, Player *player, int column);

typedef struct _Game Game;

struct _Game {
    CLASS_PROPS(Game)
    GAME_PROPS(Game)
};

Game *Game_new(void);
void Game_apply(Game *self);
void Game_destroy(Game *self);
int Game_input_move(Game *self, Player *player, int column);

#endif
