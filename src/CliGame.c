#include <stdlib.h>
#include <stdio.h>
#include "CliGame.h"
#include "Class.h"

static char *get_column_string(int columns);

CliGame *CliGame_new(
    Game *game,
    Grid *grid,
    LineChecker *line_checker)
{
    CliGame *self = CLASS_MALLOC(CliGame);

    self->game = game;
    self->grid = grid;
    self->line_checker = line_checker;
    self->converter = GridToString_new(grid, game->player_1, game->player_2);

    if (grid) {
        self->column_string = get_column_string(grid->columns);
    }

    CliGame_apply(self);

    return self;
}

CliGame *CliGame_new_default(void)
{
    return CliGame_new(NULL, NULL, NULL);
}

void CliGame_apply(CliGame *self)
{
    self->new = CliGame_new_default;
    self->apply = CliGame_apply;
    self->destroy = CliGame_destroy;
    self->start = CliGame_start;
}

void CliGame_destroy(CliGame *self)
{
    self->converter->destroy(self->converter);

    free(self->column_string);
    free(self);
}

void CliGame_start(CliGame *self)
{
    int move;

    printf("%d, %d\n", self->grid->columns, self->grid->rows);

    while (!self->game->is_game_over(self->game)) {
        printf("\n%s\n", self->column_string);
        printf(self->converter->get(self->converter));

        printf("\nColumn to move: ");
        scanf("%d", &move);

        self->game->input_move(self->game, self->game->player_to_move, move);
    }

    printf("%s\n", self->column_string);
    printf(self->converter->get(self->converter));

    printf("Game over\n");
}

static char *get_column_string(int columns)
{
    char *output = malloc(sizeof(char) * columns);

    int i;

    for (i = 0; i < columns; i += 1) {
        sprintf(&output[i], "%d", i % 10);
    }

    return output;
}
