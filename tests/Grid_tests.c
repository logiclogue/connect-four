#include "../deps/minunit/minunit.h"
#include "Grid_tests.h"
#include "../src/Grid.h"

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

MU_TEST(calls_new_sets_correct_empty_square)
{
    // arrange
    Grid *grid;
    char empty_square = ' ';

    // act
    grid = Grid_new(4, 4);

    // assert
    mu_check(grid->empty_square == empty_square);
}

MU_TEST(calls_get_sets_grid_correctly)
{
    // arrange
    Grid *grid = Grid_new(4, 4);

    // act
    grid->set(grid, 0, 0, 'T');

    // assert
    mu_check(grid->grid[0][0] == 'T');
}

void Grid_tests()
{
    printf("Grid_tests");

    MU_RUN_TEST(calls_new_default_sets_correct_columns);
    MU_RUN_TEST(calls_new_default_sets_correct_rows);
    MU_RUN_TEST(calls_new_sets_correct_empty_square);
    MU_RUN_TEST(calls_get_sets_grid_correctly);

    MU_REPORT();
}
