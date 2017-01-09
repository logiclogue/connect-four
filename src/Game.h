#ifndef GAME_H
#define GAME_H
#define GAME_PROPS(self_t) \
    char *record; \
    Player *player_1; \
    Player *player_2; \
    Board *board;

typedef struct _Game Game;

struct _Game {
    GAME_PROPS(Game)
};

Game *Game_new(Player *player_1, Player *player_2);

#endif
