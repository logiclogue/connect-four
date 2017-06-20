#include "../deps/minunit/minunit.h"
#include "MoveInputter_tests.h"
#include "../src/MoveInputter.h"
#include "../src/Game.h"

MoveInputter *inputter;
Game *game;
int called_input_move_counter;

static int input_move_counter_mock(Game *self, Player *player, int column)
{
    called_input_move_counter += 1;

    return 1;
}

MU_TEST(input_from_notation_called_with_empty_string_doesnt_call_input_move)
{
    // arrange
    int return_value;

    called_input_move_counter = 0;

    game->input_move = input_move_counter_mock;

    // act
    inputter->input_from_notation("");

    // assert
    mu_check(called_input_move_counter == 0);
}

void MoveInputter_tests()
{
    printf("MoveInputter_tests");

    game = Game_new_default();
    inputter = MoveInputter_new(game);
    called_input_move_counter = 0;

    MU_RUN_TEST(input_from_notation_called_with_empty_string_doesnt_call_input_move);

    MU_REPORT();
}
