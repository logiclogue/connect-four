#include "../deps/minunit/minunit.h"
#include "MoveInputter_tests.h"
#include "../src/MoveInputter.h"
#include "../src/Game.h"
#include "../src/Player.h"

MoveInputter *inputter;
Game *game;
Player *called_input_move_with_player;
int called_input_move_counter;
int called_input_move_with_column;

static int input_move_counter_mock(Game *self, Player *player, int column)
{
    called_input_move_counter += 1;
    called_input_move_with_column = column;
    called_input_move_with_player = player;

    return 1;
}

MU_TEST(input_from_notation_called_with_empty_string_doesnt_call_input_move)
{
    // arrange
    char *notation = "";

    called_input_move_counter = 0;

    game->input_move = input_move_counter_mock;

    // act
    inputter->input_from_notation(inputter, notation);

    // assert
    mu_check(called_input_move_counter == 0);
}

MU_TEST(input_from_notation_called_with_string_of_len_5_calls_method_5_times) {
    // arrange
    char *notation = "01234";

    called_input_move_counter = 0;

    // act
    inputter->input_from_notation(inputter, notation);

    // assert
    mu_check(called_input_move_counter == 5);
}

MU_TEST(input_from_notation_called_calls_input_move_with_the_right_column) {
    // arrange
    char *notation = "01234";

    // act
    inputter->input_from_notation(inputter, notation);

    // assert
    mu_check(called_input_move_with_column == 4);
}

MU_TEST(input_from_notation_called_calls_input_move_with_player_to_move) {
    // arrange
    char *notation = "342";

    // act
    inputter->input_from_notation(inputter, notation);

    // assert
    mu_check(called_input_move_with_player == inputter->game->player_to_move);
}

void MoveInputter_tests()
{
    printf("MoveInputter_tests");

    game = Game_new_default();
    inputter = MoveInputter_new(game);
    called_input_move_counter = 0;

    MU_RUN_TEST(input_from_notation_called_with_empty_string_doesnt_call_input_move);
    MU_RUN_TEST(input_from_notation_called_with_string_of_len_5_calls_method_5_times);
    MU_RUN_TEST(input_from_notation_called_calls_input_move_with_the_right_column);
    MU_RUN_TEST(input_from_notation_called_calls_input_move_with_player_to_move);

    MU_REPORT();
}
