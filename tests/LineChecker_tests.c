#include "../deps/minunit/minunit.h"
#include "LineChecker_tests.h"
#include "../src/LineChecker.h"
#include "../src/Board.h"

static Grid *grid;

int returns_true(LineChecker *self)
{
    return 1;
}

int returns_false(LineChecker *self)
{
    return 0;
}

MU_TEST(calls_is_line_returns_true_when_all_return_true)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    line_checker->is_horizontal_line = returns_true;
    line_checker->is_vertical_line = returns_true;
    line_checker->is_positive_diagonal_line = returns_true;
    line_checker->is_negative_diagonal_line = returns_true;

    // act
    return_value = line_checker->is_line(line_checker);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_is_line_returns_true_when_one_return_true)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    line_checker->is_horizontal_line = returns_false;
    line_checker->is_vertical_line = returns_false;
    line_checker->is_positive_diagonal_line = returns_false;
    line_checker->is_negative_diagonal_line = returns_true;

    // act
    return_value = line_checker->is_line(line_checker);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_is_line_returns_false_when_none_return_true)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    line_checker->is_horizontal_line = returns_false;
    line_checker->is_vertical_line = returns_false;
    line_checker->is_positive_diagonal_line = returns_false;
    line_checker->is_negative_diagonal_line = returns_false;

    // act
    return_value = line_checker->is_line(line_checker);

    // assert
    mu_check(!return_value);
}

Grid *get_horizontal_line_grid(void)
{
    Board *board = Board_new(3, 3);
    char piece = 'T';

    board->input(board, 0, piece);
    board->input(board, 1, piece);
    board->input(board, 2, piece);

    return (Grid *)board;
}

Grid *get_vertical_line_grid(void)
{
    Board *board = Board_new(3, 3);
    char piece = 'T';
    int column = 1;

    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);

    return (Grid *)board;
}

Grid *get_positive_diagonal_line_grid(void)
{
    Board *board = Board_new(3, 3);
    char piece = 'T';
    char other_piece = 'L';

    board->input(board, 0, piece);
    board->input(board, 1, other_piece);
    board->input(board, 2, other_piece);
    board->input(board, 1, piece);
    board->input(board, 2, other_piece);
    board->input(board, 2, piece);

    return (Grid *)board;
}

Grid *get_negative_diagonal_line_grid(void)
{
    Board *board = Board_new(3, 3);
    char piece = 'T';
    char other_piece = 'L';

    board->input(board, 0, other_piece);
    board->input(board, 0, other_piece);
    board->input(board, 0, piece);
    board->input(board, 1, other_piece);
    board->input(board, 1, piece);
    board->input(board, 2, piece);

    return (Grid *)board;
}

MU_TEST(calls_is_horizontal_line_when_is_line_then_return_true)
{
    // arrange
    Grid *grid = get_horizontal_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_horizontal_line(line_checker);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_is_horizontal_line_when_vertical_then_return_false)
{
    // arrange
    Grid *grid = get_vertical_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_horizontal_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_horizontal_line_when_empty_grid_returns_false)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_horizontal_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_vertical_line_when_is_line_returns_true)
{
    // arrange
    Grid *grid = get_vertical_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_vertical_line(line_checker);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_is_vertical_line_when_horizontal_line_returns_false)
{
    // arrange
    Grid *grid = get_horizontal_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_vertical_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_vertical_line_when_empty_grid_returns_false)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_vertical_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_positive_diagonal_when_is_line_then_returns_true)
{
    // arrange
    Grid *grid = get_positive_diagonal_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_positive_diagonal_line(line_checker);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_is_positive_diagonal_when_neg_diagonal_returns_false)
{
    // arrange
    Grid *grid = get_negative_diagonal_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_positive_diagonal_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_positive_diagonal_when_empty_grid_returns_false)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_positive_diagonal_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_negative_line_when_is_line_then_returns_true)
{
    // arrange
    Grid *grid = get_negative_diagonal_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_negative_diagonal_line(line_checker);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_is_negative_line_when_is_positive_then_returns_false)
{
    // arrange
    Grid *grid = get_positive_diagonal_line_grid();
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_negative_diagonal_line(line_checker);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_is_negative_line_when_empty_grid_returns_false)
{
    // arrange
    LineChecker *line_checker = LineChecker_new(grid, 3);
    int return_value;

    // act
    return_value = line_checker->is_negative_diagonal_line(line_checker);

    // assert
    mu_check(!return_value);
}

void LineChecker_tests()
{
    printf("LineChecker_tests");

    grid = Grid_new(3, 3);

    MU_RUN_TEST(calls_is_line_returns_true_when_all_return_true);
    MU_RUN_TEST(calls_is_line_returns_true_when_one_return_true);
    MU_RUN_TEST(calls_is_line_returns_false_when_none_return_true);
    MU_RUN_TEST(calls_is_horizontal_line_when_is_line_then_return_true);
    MU_RUN_TEST(calls_is_horizontal_line_when_vertical_then_return_false);
    MU_RUN_TEST(calls_is_horizontal_line_when_empty_grid_returns_false);
    MU_RUN_TEST(calls_is_vertical_line_when_is_line_returns_true);
    MU_RUN_TEST(calls_is_vertical_line_when_horizontal_line_returns_false);
    MU_RUN_TEST(calls_is_vertical_line_when_empty_grid_returns_false);
    MU_RUN_TEST(calls_is_positive_diagonal_when_is_line_then_returns_true);
    MU_RUN_TEST(calls_is_positive_diagonal_when_neg_diagonal_returns_false);
    MU_RUN_TEST(calls_is_positive_diagonal_when_empty_grid_returns_false);
    MU_RUN_TEST(calls_is_negative_line_when_is_line_then_returns_true);
    MU_RUN_TEST(calls_is_negative_line_when_is_positive_then_returns_false);
    MU_RUN_TEST(calls_is_negative_line_when_empty_grid_returns_false);

    MU_REPORT();
}
