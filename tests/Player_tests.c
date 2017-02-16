#include "../deps/minunit/minunit.h"
#include "Player_tests.h"
#include "../src/Player.h"
#include "../src/Game.h"

static int returning_true()
{
    return 1;
}

MU_TEST(move_valid_game_move_valid_returns_true_returns_true)
{
    // arrange
    Game *game = Game_new_default();
    Player *player = game->player_to_move;
    int column = 2;

    game->move_valid = returning_true;

    // act
    int result = player->move_valid(player, column);

    // assert
    mu_check(result);
}

MU_TEST(input_move_returns_move_valid_return_value)
{
    // arrange
    Game *game = Game_new_default();
    Player *player = game->player_to_move;
    int column = 2;

    game->input_move = returning_true;

    // act
    int result = player->input_move(player, column);

    // assert
    mu_check(result);
}

void Player_tests()
{
    printf("Player_tests");

    MU_RUN_TEST(move_valid_game_move_valid_returns_true_returns_true);
    MU_RUN_TEST(input_move_returns_move_valid_return_value);

    MU_REPORT();
}
