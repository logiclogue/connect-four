#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Class.h"
#include "LineChecker.h"
#include "Board.h"
#include "Game.h"

#define GAME_MANAGER_PROPS(self_t) \
    LineChecker *line_checker; \
    Board *board; \
    Game *game;

typedef struct _GameManager GameManager;

struct _GameManager {
    CLASS_PROPS(GameManager)
    GAME_MANAGER_PROPS(GameManager)
};

GameManager *GameManager_new(int columns, int rows, int length);
GameManager *GameManager_new_default();

#endif
