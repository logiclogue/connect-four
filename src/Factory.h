#ifndef FACTORY_H
#define FACTORY_H

#include "Board.h"
#include "LineChecker.h"
#include "Game.h"
#include "GameManagerInterface.h"

#define FACTORY_PROPS(self_t) \

typedef struct _Factory Factory;

struct _Factory {
    FACTORY_PROPS(Factory)
}

Factory Factory_new();
Board *Factory_create_board(Factory self, int columns, int rows);
LineChecker *Factory_create_line_checker(Factory self, Grid grid, int length);

#endif
