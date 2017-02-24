#include <stdlib.h>
#include "Player.h"
#include "Game.h"
#include "NoughtsCrossesGame.h"
#include "LineChecker.h"

NoughtsCrossesGame *NoughtsCrossesGame_new(
    Player *player_1,
    Player *player_2,
    Grid *grid,
    LineChecker *line_checker)
{
    if (grid == NULL) {
        grid = Grid_new(3, 3);
    }

    if (line_checker == NULL) {
        line_checker = LineChecker_new(grid, 3);
    }

    NoughtsCrossesGame *self = (NoughtsCrossesGame *)Game_new(
        player_1,
        player_2,
        (Board *)grid,
        line_checker);

    NoughtsCrossesGame_apply(self);

    return self;
}

NoughtsCrossesGame *NoughtsCrossesGame_new_default(void)
{
    return NoughtsCrossesGame_new(NULL, NULL, NULL, NULL);
}

void NoughtsCrossesGame_apply(NoughtsCrossesGame *self)
{
    self->new = NoughtsCrossesGame_new_default;
    self->apply = NoughtsCrossesGame_apply;
    //self->input_move = NoughtsCrossesGame_input_move;
    //self->move_valid = NoughtsCrossesGame_move_valid;
}
