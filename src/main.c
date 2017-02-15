#include <stdio.h>
#include "Game.h"

#ifdef BUILD_MAIN
int main(void)
{
    Board *board = Board_new(3, 3);
    LineChecker *line_checker = LineChecker_new((Grid *)board, 3);
    Game *game = Game_new(NULL, NULL, board, line_checker);
    int column;

    while (!game->is_game_over(game)) {
        scanf("%d", &column);

        game->input_move(game, game->player_to_move, column);

        int x, y;

        for (x = board->columns - 1; x >= 0; x -= 1) {
            for (y = 0; y < board->rows; y += 1) {
                printf("%p", board->get(board, y, x));
            }
            printf("\n");
        }
    }
}
#endif
