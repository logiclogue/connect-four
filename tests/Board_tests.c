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

int is_column_valid_returns_true(Board *self, int column)
{
    return 1;
}

int is_column_valid_returns_false(Board *self, int column)
{
    return 0;
}

MU_TEST(calls_input_when_is_column_valid_returns_false_returns_false)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    int return_value;

    board->is_column_valid = is_column_valid_returns_false;

    // act
    return_value = board->input(board, column, piece);

    // assert
    mu_check(!return_value);
}

MU_TEST(calls_input_when_is_column_valid_returns_true_returns_true)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    int return_value;

    board->is_column_valid = is_column_valid_returns_true;

    // act
    return_value = board->input(board, column, piece);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_input_puts_into_grid)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;

    // act
    board->input(board, column, piece);
    board->input(board, column, piece);

    // assert
    mu_check(board->get(board, 1, 2) == board->empty_square);
    mu_check(board->get(board, 1, 1) == piece);
    mu_check(board->get(board, 1, 0) == piece);
}

MU_TEST(calls_remove_returns_character_of_piece)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    char return_value;
    
    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);

    // act
    return_value = board->remove(board, column);

    // assert
    mu_check(return_value == piece);
}

MU_TEST(calls_remove_removes_from_full_grid)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    
    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);

    // act
    board->remove(board, column);

    // assert
    mu_check(board->get(board, column, 3) == board->empty_square);
    mu_check(board->get(board, column, 2) == piece);
}

MU_TEST(calls_remove_when_full_grid_returns_true)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    char return_value;
    
    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);
    board->input(board, column, piece);

    // act
    return_value = board->remove(board, column);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_remove_when_one_piece_removes_only_piece)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    
    board->input(board, column, piece);

    // act
    board->remove(board, column);

    // assert
    mu_check(board->get(board, column, 0) == board->empty_square);
}

MU_TEST(calls_remove_when_one_piece_returns_false)
{
    // arrange
    Board *board = Board_new(4, 4);
    char piece = 'T';
    int column = 1;
    char return_value;
    
    board->input(board, column, piece);

    // act
    return_value = board->remove(board, column);

    // assert
    mu_check(return_value);
}

MU_TEST(calls_remove_when_empty_column_returns_false)
{
    // arrange
    Board *board = Board_new(4, 4);
    int column = 1;
    char return_value;

    // act
    return_value = board->remove(board, column);

    // assert
    mu_check(!return_value);
}

char get_returning_empty_square(Board *self, int column, int row)
{
    return self->empty_square;
}

MU_TEST(calls_remove_when_get_on_first_row_returns_false_returns_false)
{
    // arrange
    Board *board = Board_new(4, 4);
    int column = 1;
    char return_value;

    board->get = get_returning_empty_square;
    
    // act
    return_value = board->remove(board, column);

    // assert
    mu_check(!return_value);
}

void Board_tests()
{
    printf("Board_tests");

    MU_RUN_TEST(calls_is_column_valid_when_empty_returns_true);
    MU_RUN_TEST(calls_is_column_valid_when_out_of_range_returns_false);
    MU_RUN_TEST(calls_is_column_valid_when_column_is_full_returns_false);
    MU_RUN_TEST(calls_is_column_valid_when_column_is_not_full_returns_true);
    MU_RUN_TEST(calls_input_when_is_column_valid_returns_false_returns_false);
    MU_RUN_TEST(calls_input_when_is_column_valid_returns_true_returns_true);
    MU_RUN_TEST(calls_input_puts_into_grid);
    MU_RUN_TEST(calls_remove_removes_from_full_grid);
    MU_RUN_TEST(calls_remove_when_full_grid_returns_true);
    MU_RUN_TEST(calls_remove_when_one_piece_removes_only_piece);
    MU_RUN_TEST(calls_remove_when_one_piece_returns_false);
    MU_RUN_TEST(calls_remove_when_get_on_first_row_returns_false_returns_false);
    MU_RUN_TEST(calls_remove_when_empty_column_returns_false);
    MU_RUN_TEST(calls_remove_returns_character_of_piece);

    MU_REPORT();
}