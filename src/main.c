#include <stdio.h>
#include "Board.h"

#ifdef BUILD_MAIN
int main(void)
{
    Board *board = Board_new(7, 6);

    int result = board->input(board, 3, 3);

    return 0;
}
#endif
