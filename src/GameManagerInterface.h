#ifndef GAME_MANAGER_INTERFACE_H
#define GAME_MANAGER_INTERFACE_H

#include "Class.h"
#include "LineChecker.h"
#include "Board.h"
#include "Game.h"

#define GAME_MANAGER_INTERFACE_PROPS(self_t) \
    LineChecker *line_checker; \
    Board *board; \
    Game *game;

#endif
