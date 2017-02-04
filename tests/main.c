#ifdef BUILD_TESTS
#include <stdio.h>
#include "Grid_tests.h"
#include "Board_tests.h"
#include "LineChecker_tests.h"
#include "Game_tests.h"

int main(void)
{
    Grid_tests();
    Board_tests();
    LineChecker_tests();
    Game_tests();

    return 0;
}
#endif
