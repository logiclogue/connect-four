#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"
#include "GridToString.h"
#include "Grid.h"
#include "Board.h"
#include "LineChecker.h"

#ifdef BUILD_MAIN
static char *get_column_string(int columns)
{
    char *output = malloc(sizeof(char) * columns);
    char current_char;

    int i;

    for (i = 0; i < columns; i += 1) {
        sprintf(&current_char, "%d", i % 10);

        output[i] = current_char;
    }

    return output;
}

int main(int argc, char *argv[])
{
    Game *game;
    Board *board;
    Player *player_1, *player_2;
    GridToString *converter;
    LineChecker *line_checker;
    int columns = 7;
    int rows = 6;
    int line_length = 4;
    int move, i;
    char *flag, *argument, *column_string;
    char null_string[] = "";

    for (i = 0; i < argc; i += 1) {
        flag = argv[i];
        argument = null_string;
        
        if (i < argc - 1) {
            argument = argv[i + 1];
        }

        if (!strcmp(flag, "--columns")) {
            columns = atoi(argument);
        } else if (!strcmp(flag, "--rows")) {
            rows = atoi(argument);
        } else if (!strcmp(flag, "--length")) {
            line_length = atoi(argument);
        }
    }

    column_string = get_column_string(columns);
    board = Board_new(columns, rows);
    line_checker = LineChecker_new((Grid *)board, line_length);
    printf("%d, %d\n", columns, rows);
    game = Game_new(NULL, NULL, board, line_checker);
    player_1 = game->player_1;
    player_2 = game->player_2;
    converter = GridToString_new((Grid *)board, player_1, player_2);

    while (!game->is_game_over(game)) {
        printf("\n%s\n", column_string);
        printf(converter->get(converter));

        printf("\nColumn to move: ");
        scanf("%d", &move);

        game->input_move(game, game->player_to_move, move);
    }

    printf("%s\n", column_string);
    printf(converter->get(converter));

    printf("Game over\n");
}
#endif
