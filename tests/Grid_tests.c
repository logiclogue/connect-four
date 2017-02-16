#include "../deps/minunit/minunit.h"
#include "Grid_tests.h"
#include "../src/Grid.h"
#include "../src/Player.h"

Player *player;

MU_TEST(calls_new_default_sets_correct_columns)
{
    // arrange
    Grid *grid;
    int columns = 7;

    // act
    grid = Grid_new_default();

    // assert
    mu_check(grid->columns == columns);
}

MU_TEST(calls_new_default_sets_correct_rows)
{
    // arrange
    Grid *grid;
    int rows = 6;

    // act
    grid = Grid_new_default();

    // assert
    mu_check(grid->rows == rows);
}

MU_TEST(calls_set_sets_grid_correctly)
{
    // arrange
    Grid *grid = Grid_new(4, 4);

    // act
    grid->set(grid, 0, 0, player);

    // assert
    mu_check(grid->grid[0][0] == player);
}

MU_TEST(calls_set_returns_true_when_in_range)
{
    // arrange
    Grid *grid = Grid_new(4, 4);
    int valid;

    // act
    valid = grid->set(grid, 0, 0, player);

    // assert
    mu_check(valid);
}

MU_TEST(calls_set_returns_false_when_out_of_range)
{
    // arrange
    Grid *grid = Grid_new(4, 4);
    int valid;

    // act
    valid = grid->set(grid, 4, 4, player);

    // assert
    mu_check(!valid);
}

MU_TEST(calls_is_in_range_returns_true_when_in_range)
{
    // arrange
    Grid *grid = Grid_new(4, 4);
    int valid;

    // act
    valid = grid->is_in_range(grid, 0, 0);

    // assert
    mu_check(valid);
}

MU_TEST(calls_is_in_range_returns_false_when_out_of_range)
{
    // arrange
    Grid *grid = Grid_new(4, 4);
    int valid;

    // act
    valid = grid->is_in_range(grid, 4, 4);

    // assert
    mu_check(!valid);
}

MU_TEST(calls_get_returns_set_null)
{
    // arrange
    Grid *grid = Grid_new(4, 4);
    void *return_value;
    void *set_value = (void *)player;

    grid->set(grid, 0, 0, set_value);

    // act
    return_value = grid->get(grid, 0, 0);

    // assert
    mu_check(return_value == set_value);
}

MU_TEST(calls_get_returns_empty_square_when_out_of_range)
{
    // arrange
    Grid *grid = Grid_new(4, 4);
    void *return_value;
    void *set_value = player;

    grid->set(grid, 4, 4, set_value);

    // act
    return_value = grid->get(grid, 4, 4);

    // assert
    mu_check(return_value == NULL);
}

void Grid_tests()
{
    printf("Grid_tests");

    player = Player_new_default();

    MU_RUN_TEST(calls_new_default_sets_correct_columns);
    MU_RUN_TEST(calls_new_default_sets_correct_rows);
    MU_RUN_TEST(calls_set_sets_grid_correctly);
    MU_RUN_TEST(calls_set_returns_true_when_in_range);
    MU_RUN_TEST(calls_set_returns_false_when_out_of_range);
    MU_RUN_TEST(calls_is_in_range_returns_true_when_in_range);
    MU_RUN_TEST(calls_is_in_range_returns_false_when_out_of_range);
    MU_RUN_TEST(calls_get_returns_set_null);
    MU_RUN_TEST(calls_get_returns_empty_square_when_out_of_range);

    MU_REPORT();
}
