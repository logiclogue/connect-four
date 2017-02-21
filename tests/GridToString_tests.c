#include "../deps/minunit/minunit.h"
#include "GridToString_tests.h"
#include "../src/GridToString.h"
#include "../src/Player.h"

Player *player_1;
Player *player_2;

MU_TEST(get_char_called_with_player_returns_player_char)
{
    // arrange
    GridToString *grid_converter_1 = GridToString_new(NULL, player_1, player_2);
    GridToString *grid_converter_2 = GridToString_new(NULL, player_1, player_2);

    // act
    char result_1 = grid_converter_1->get_char(grid_converter_1, player_1);
    char result_2 = grid_converter_2->get_char(grid_converter_2, player_2);

    // assert
    mu_check(result_1 == grid_converter_1->player_1_char);
    mu_check(result_2 == grid_converter_2->player_2_char);
}

void GridToString_tests()
{
    player_1 = Player_new_default();
    player_2 = Player_new_default();

    printf("GridToString_tests");

    MU_RUN_TEST(get_char_called_with_player_returns_player_char);

    MU_REPORT();
}
