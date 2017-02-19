#ifndef GRID_TO_STRING_H
#define GRID_TO_STRING_H

#include "Class.h"
#include "Grid.h"
#include "Player.h"
#include "Grid.h"

#define GRID_TO_STRING_PROPS(self_t) \
    Grid *grid; \
    void *player_1_ptr; \
    void *player_2_ptr; \
    char player_1_char; \
    char player_2_char; \
    char empty_char; \
    char *(*get)(self_t *self); \
    char *(*get_row)(self_t *self, int column); \
    char (*get_char)(self_t *self, void *player_ptr);

typedef struct _GridToString GridToString;

struct _GridToString {
    CLASS_PROPS(GridToString)
    GRID_TO_STRING_PROPS(GridToString)
};

GridToString *GridToString_new(
    Grid *grid,
    Player *player_1_ptr,
    Player *player_2_ptr);
GridToString *GridToString_new_default(void);
void GridToString_apply(GridToString *self);
char *GridToString_get(GridToString *self);
char *GridToString_get_row(GridToString *self, int row);
char GridToString_get_char(GridToString *self, void *player_ptr);

#endif
