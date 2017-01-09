#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_PROPS(self_t) \
    \\

typedef struct _Player Player;

struct _Player {
    PLAYER_PROPS(Player)
}

Player *Player_new(void);

#endif
