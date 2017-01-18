#ifndef PLAYER_H
#define PLAYER_H

#include "Class.h"

#define PLAYER_PROPS(self_t) \
    int (*input_move)(self_t *self, int column); \
    int (*move_valid)(self_t *self, int column);

typedef struct _Player Player;

struct _Player {
    CLASS_PROPS(Player)
    PLAYER_PROPS(Player)
};

Player *Player_new(void);
void Player_apply(Player *self);
int Player_input_move(Player *self, int column);
int Player_move_valid(Player *self, int column);

#endif
