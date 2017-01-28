#include "../deps/minunit/minunit.h"
#include "Board_tests.h"
#include "../src/Board.h"

MU_TEST(calls_is_column_valid_when_empty_returns_true)
{
    // arrange
    Board *board = Board_new(4, 4);
    int is_valid;

    // act
    is_valid = board->is_column_valid(board, 0);

    // assert
    mu_check(is_valid);
}

MU_TEST(calls_is_column_valid_when_out_of_range_returns_false)
{
    // arrange
    Board *board = Board_new(4, 4);
    int is_valid;

    // act
    is_valid = board->is_column_valid(board, 4);

    // assert
    mu_check(!is_valid);
}

MU_TEST(calls_is_column_valid_when_column_is_full_returns_false)
{
    // arrange
    Board *board = Board_new(4, 2);
    char piece = 'T';
    int column = 1;
    int is_valid;

    board->input(board, column, piece);
    board->input(board, column, piece);

    // act
    is_valid = board->is_column_valid(board, column);

    // assert
    mu_check(!is_valid);
}

MU_TEST(calls_is_column_valid_when_column_is_not_full_returns_true)
{
    // arrange
    Board *board = Board_new(4, 3);
    char piece = 'T';
    int column = 1;
    int is_valid;

    board->input(board, column, piece);
    board->input(board, column, piece);

    // act
    is_valid = board->is_column_valid(board, column);

    // assert
    mu_check(is_valid);
}

void Board_tests()
{
    printf("Board_tests");

    MU_RUN_TEST(calls_is_column_valid_when_empty_returns_true);
    MU_RUN_TEST(calls_is_column_valid_when_out_of_range_returns_false);
    MU_RUN_TEST(calls_is_column_valid_when_column_is_full_returns_false);
    MU_RUN_TEST(calls_is_column_valid_when_column_is_not_full_returns_true);

    MU_REPORT();
}
