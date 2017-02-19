#include "../deps/minunit/minunit.h"
#include "GridToString_tests.h"
#include "../src/GridToString.h"
#include "../src/Player.h"

Player *player_1;
Player *player_2;

MU_TEST(get_char_called_with_player_1_returns_player_1_char)
{
    // arrange
    GridToString *grid_converter = GridToString_new(NULL, player_1, player_2);

    // act
    char result = grid_converter->get_char(grid_converter, player_1);

    // assert
    mu_check(result == grid_converter->player_1_char);
}

void GridToString_tests()
{
    player_1 = Player_new_default();
    player_2 = Player_new_default();

    printf("GridToString_tests");

    MU_RUN_TEST(get_char_called_with_player_1_returns_player_1_char);

    MU_REPORT();
}
