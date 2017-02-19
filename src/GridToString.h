#ifndef GRID_TO_STRING_H
#define GRID_TO_STRING_H

#include "Class.h"
#include "Grid.h"
#include "Player.h"
#include "Grid.h"

#define GRID_TO_STRING_PROPS(self_t) \
    void *player_1_ptr; \
    void *player_2_ptr; \
    char player_1_char; \
    char player_2_char; \
    char empty_char; \
    char *(*get_string)(self_t *self);

typedef struct _GridToString GridToString;

struct _GridToString {
    CLASS_PROPS(GridToString)
    GRID_TO_STRING_PROPS(GridToString)
}

GridToString *GridToString_new(
    Grid *grid,
    Player *player_1_ptr,
    Player *player_2_ptr);
GridToString *GridToString_new_default(void);
void GridToString_apply(GridToString *self);
char *GridToString_get_string(GridToString *self);

#endif
