#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"
#include "GridToString.h"
#include "Grid.h"
#include "Board.h"
#include "LineChecker.h"
#include "CliGame.h"
#include "HelpText.h"
#include "GameManagerInterface.h"
#include "MoveInputter.h"

#ifdef BUILD_MAIN
int main(int argc, char *argv[])
{
    Game *game;
    Board *board;
    LineChecker *line_checker;
    GameManagerInterface *game_manager;
    MoveInputter *move_inputter;
    int columns = 7;
    int rows = 6;
    int line_length = 4;
    int i;
    char *flag, *argument;
    char null_string[] = "";
    char *moves = "";
    enum game_types { NORMAL, HELP, IS_VICTORY, WHO_WON, IS_DRAW, NONE };
    enum game_types game_type = NORMAL;

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
        } else if (!strcmp(flag, "--moves")) {
            moves = argument;
        } else if (!strcmp(flag, "--help")) {
            game_type = HELP;
        }
    }

    if (game_type == NORMAL) {
        board = Board_new(columns, rows);
        line_checker = LineChecker_new((Grid *)board, line_length);
        game = Game_new(NULL, NULL, board, line_checker);
        game_manager = (GameManagerInterface *)CliGame_new(
            game, (Grid *)board, line_checker);
        move_inputter = MoveInputter_new(game);

        move_inputter->input_from_notation(move_inputter, moves);
    } else if (game_type == HELP) {
        game_manager = (GameManagerInterface *)HelpText_new(argv[0]);
    }

    game_manager->start(game_manager);

    return 0;
}
#endif
