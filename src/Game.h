#ifndef GAME_H
#define GAME_H
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
    GAME_PROPS(Game)
};

Game *Game_new(Player *player_1, Player *player_2);

#endif