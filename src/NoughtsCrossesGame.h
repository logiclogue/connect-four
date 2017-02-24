#ifndef NOUGHTS_CROSSES_GAME
#define NOUGHTS_CROSSES_GAME

#include "Class.h"
#include "Game.h"

typedef struct _NoughtsCrossesGame NoughtsCrossesGame;

struct _NoughtsCrossesGame {
    CLASS_PROPS(NoughtsCrossesGame)
    GAME_PROPS(NoughtsCrossesGame)
};

NoughtsCrossesGame *NoughtsCrossesGame_new(
    Player *player_1,
    Player *player_2,
    Grid *grid,
    LineChecker *line_checker);
NoughtsCrossesGame *NoughtsCrossesGame_new_default(void);
void NoughtsCrossesGame_apply();
int NoughtsCrossesGame_input_move(
    NoughtsCrossesGame *self, Player *player,
    int column, int row);
int NoughtsCrossesGame_move_valid(
    NoughtsCrossesGame *self, Player *player,
    int column, int row);

#endif
