#ifndef CLI_GAME_H
#define CLI_GAME_H

#include "Class.h"
#include "GameManagerInterface.h"

typedef struct _CliGame CliGame;

struct _CliGame {
    CLASS_PROPS(CliGame)
    GAME_MANAGER_INTERFACE_PROPS(CliGame)
};

#endif
