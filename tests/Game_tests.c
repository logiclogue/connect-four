#include "../deps/minunit/minunit.h"
#include "Game_tests.h"
#include "../src/Player.h"
#include "../src/Game.h"

Player *player_1;
Player *player_2;
Game *game;

static int board_is_column_valid_returning_false(Board *self, int column)
{
    return 0;
}

static int board_is_column_valid_returning_true(Board *self, int column)
{
    return 1;
}

static int game_is_game_over_returning_false(Game *self)
{
    return 0;
}

MU_TEST(created_with_new_sets_player_properties)
{
    // arrange
    Game *game;

    // act
    game = Game_new(player_1, player_2, NULL, NULL);

    // assert
    mu_check(game->player_1 == player_1);
    mu_check(game->player_2 == player_2);
}

MU_TEST(created_with_new_default_properties_arent_null)
{
    // arrange
    Game *game;

    // act
    game = Game_new_default();

    // assert
    mu_check(game->player_1 != NULL);
    mu_check(game->player_2 != NULL);
    mu_check(game->board != NULL);
    mu_check(game->line_checker != NULL);
}

MU_TEST(calls_input_move_with_player_not_to_move_returns_false)
{
    // arrange
    game->player_to_move = player_1;
    int column = 0;
    int return_value;

    game->board->is_column_valid = board_is_column_valid_returning_true;

    // act
    return_value = game->input_move(game, player_2, column);

    // assert
    mu_check(!return_value);
}

MU_TEST(input_move_when_is_column_valid_returns_false_returns_false)
{
    // arrange
    game->player_to_move = player_1;
    int column = 0;
    int return_value;

    game->board->is_column_valid = board_is_column_valid_returning_false;

    // act
    return_value = game->input_move(game, player_1, column);

    // assert
    mu_check(!return_value);
}

MU_TEST(input_move_valid_move_switches_player)
{
    // arrange
    game->player_to_move = player_1;
    int column = 0;

    game->is_game_over = game_is_game_over_returning_false;
    game->board->is_column_valid = board_is_column_valid_returning_true;

    // act
    game->input_move(game, player_1, column);

    // assert
    mu_check(game->player_to_move == game->player_2);
}

MU_TEST(input_move_when_is_game_over_returns_false_returns_false)
{
    // arrange
    game->player_to_move = player_1;
    int column = 0;
    int return_value;

    game->is_game_over = game_is_game_over_returning_false;
    game->board->is_column_valid = board_is_column_valid_returning_false;

    // act
    return_value = game->input_move(game, player_1, column);

    // assert
    mu_check(!return_value);
}

static int line_checker_is_line_returning_true(LineChecker *self)
{
    return 1;
}

static int line_checker_is_line_returning_false(LineChecker *self)
{
    return 0;
}

static int board_is_full_returning_true(Board *self)
{
    return 1;
}

static int board_is_full_returning_false(Board *self)
{
    return 0;
}

MU_TEST(is_game_over_when_is_line_returns_true_returns_true)
{
    // arrange
    int return_value;
    game->line_checker->is_line = line_checker_is_line_returning_true;
    game->board->is_full = board_is_full_returning_false;

    // act
    return_value = game->is_game_over(game);

    // assert
    mu_check(return_value);
}

MU_TEST(is_game_over_when_board_is_full_returns_true_returns_true)
{
    // arrange
    int return_value;
    game->line_checker->is_line = line_checker_is_line_returning_false;
    game->board->is_full = board_is_full_returning_true;

    // act
    return_value = game->is_game_over(game);

    // assert
    mu_check(return_value);
}

MU_TEST(is_game_over_when_both_are_false_returns_false)
{
    // arrange
    int return_value;
    game->line_checker->is_line = line_checker_is_line_returning_false;
    game->board->is_full = board_is_full_returning_false;

    // act
    return_value = game->is_game_over(game);

    // assert
    mu_check(return_value);
}

void Game_tests()
{
    printf("Game_tests");

    player_1 = Player_new();
    player_2 = Player_new();
    game = Game_new(player_1, player_2, NULL, NULL);

    MU_RUN_TEST(created_with_new_sets_player_properties);
    MU_RUN_TEST(created_with_new_default_properties_arent_null);
    MU_RUN_TEST(calls_input_move_with_player_not_to_move_returns_false);
    MU_RUN_TEST(input_move_when_is_column_valid_returns_false_returns_false);
    MU_RUN_TEST(input_move_valid_move_switches_player);
    MU_RUN_TEST(input_move_when_is_game_over_returns_false_returns_false);
    MU_RUN_TEST(is_game_over_when_is_line_returns_true_returns_true);
    MU_RUN_TEST(is_game_over_when_board_is_full_returns_true_returns_true);
    MU_RUN_TEST(is_game_over_when_both_are_false_returns_false);

    MU_REPORT();
}
