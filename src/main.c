#include "Board.h"


int main(void)
{
    Board *board = Board_new();

    board->input(board, 3, 3);

    return 0;
}
