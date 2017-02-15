#include "../deps/minunit/minunit.h"
#include "Player_tests.h"
#include "../src/Player.h"
#include "../src/Game.h"

MU_TEST(move_valid_game_move_valid_returns_false_returns_false)
{
    // arrange
    Game *game = Game_new_default();
    Player *player = game->player_1;

    // act
    // assert
}

void Player_tests()
{
    printf("Player_tests");

    MU_RUN_TEST(move_valid_game_move_valid_returns_false_returns_false);

    MU_REPORT();
}
