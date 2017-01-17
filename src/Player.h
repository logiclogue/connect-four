#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_PROPS(self_t) \
    int (*input_move)(self_t *self, int column); \
    int (*move_valid)(self_t *self, int column);

typedef struct _Player Player;

struct _Player {
    PLAYER_PROPS(Player)
};

Player *Player_new(void);

#endif
