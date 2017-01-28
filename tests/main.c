#ifdef BUILD_TESTS
#include <stdio.h>
#include "Grid_tests.h"
#include "Board_tests.h"

int main(void)
{
    Grid_tests();
    Board_tests();

    return 0;
}
#endif
