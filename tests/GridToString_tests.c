#include <string.h>
#include <stdlib.h>
#include "../deps/minunit/minunit.h"
#include "GridToString_tests.h"
#include "../src/GridToString.h"
#include "../src/Player.h"
#include "../src/Grid.h"

Player *player_1;
Player *player_2;
Grid *grid;

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

MU_TEST(get_row_called_returns_string_length_of_row)
{
    // arrange
    GridToString *converter = GridToString_new(grid, player_1, player_2);
    int row = 0;

    // act
    char *result = converter->get_row(converter, row);

    // assert
    mu_check(strlen(result) == grid->columns);

    free(result);
}

MU_TEST(get_row_called_when_player_1_made_move_player_1_char)
{
    // arrange
    GridToString *converter = GridToString_new(grid, player_1, player_2);
    int row = 0;

    // act
    grid->set(grid, 0, 0, player_1);

    char *result = converter->get_row(converter, row);

    // assert
    mu_check(result[0] == converter->player_1_char);

    free(result);
}

void GridToString_tests()
{
    player_1 = Player_new_default();
    player_2 = Player_new_default();
    grid = Grid_new_default();

    printf("GridToString_tests");

    MU_RUN_TEST(get_char_called_with_player_returns_player_char);
    MU_RUN_TEST(get_row_called_returns_string_length_of_row);
    MU_RUN_TEST(get_row_called_when_player_1_made_move_player_1_char);

    MU_REPORT();
}
