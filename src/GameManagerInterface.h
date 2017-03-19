#ifndef GAME_MANAGER_INTERFACE_H
#define GAME_MANAGER_INTERFACE_H

#include "Class.h"
#include "LineChecker.h"
#include "Board.h"
#include "Game.h"

#define GAME_MANAGER_INTERFACE_PROPS(self_t) \
    Game *game; \
    Grid *grid; \
    LineChecker *line_checker; \
    void (*start)();

typedef struct _GameManagerInterface GameManagerInterface;

struct _GameManagerInterface {
    CLASS_PROPS(GameManagerInterface)
    GAME_MANAGER_INTERFACE_PROPS(GameManagerInterface)
};

#endif
