#ifndef PLAYER_H
#define PLAYER_H

#include "Class.h"
#include "Game.h"

#define PLAYER_PROPS(self_t) \
    Game *game; \
    int (*input_move)(self_t *self, int column); \
    int (*move_valid)(self_t *self, int column);

typedef struct _Player Player;
typedef struct _Game Game;

struct _Player {
    CLASS_PROPS(Player)
    PLAYER_PROPS(Player)
};

Player *Player_new(Game *self);
Player *Player_new_default(void);
void Player_destroy(Player *self);
void Player_apply(Player *self);
int Player_input_move(Player *self, int column);
int Player_move_valid(Player *self, int column);

#endif
