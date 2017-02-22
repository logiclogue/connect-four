#include <stdio.h>
#include "Game.h"
#include "GridToString.h"
#include "Grid.h"

#ifdef BUILD_MAIN
int main(void)
{
    Game *game = Game_new_default();
    GridToString *converter = GridToString_new((Grid *)game->board, game->player_1, game->player_2);

    int move;

    while (!game->is_game_over(game)) {
        printf("\n0123456\n");
        printf(converter->get(converter));

        printf("\nColumn to move: ");
        scanf("%d", &move);

        game->input_move(game, game->player_to_move, move);
    }

    printf("0123456\n");
    printf(converter->get(converter));

    printf("Game over\n");
}
#endif
