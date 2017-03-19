#ifndef CLI_GAME_H
#define CLI_GAME_H

#include "Class.h"
#include "GameManagerInterface.h"
#include "GridToString.h"

#define CLI_GAME_PROPS(self_t) \
    CLASS_PROPS(self_t) \
    GAME_MANAGER_INTERFACE_PROPS(self_t) \
    GridToString *converter; \
    char *column_string;

typedef struct _CliGame CliGame;

struct _CliGame {
    CLI_GAME_PROPS(CliGame)
};

CliGame *CliGame_new(
    Game *game,
    Grid *grid,
    LineChecker *line_checker);
CliGame *CliGame_new_default(void);
void CliGame_apply(CliGame *self);
void CliGame_destroy(CliGame *self);
void CliGame_start(CliGame *self);

#endif
