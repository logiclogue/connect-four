#ifndef GAME_H
#define GAME_H
#define GET_PLAYER(PLAYER) player_PLAYER
#define GAME_PROPS(self_t) \
    char *record; \
    int move; \
    Player *player_1; \
    Player *player_2; \
    Board *board; \
    int (*input_move)(self_t *self, int column, int player);

typedef struct _Game Game;

struct _Game {
    GAME_PROPS(Game)
};

Game *Game_new(Player *player_1, Player *player_2);

#endif
