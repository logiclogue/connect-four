#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "HelpText.h"

static const char *help_text[] = {
    (char *)"Connect Four Engine by Jordan Lord written in C",
    (char *)"",
    (char *)"Usage:",
    (char *)" %s [arguments]",
    (char *)"",
    (char *)"Arguments:",
    (char *)" --columns  <number>  Columns on the board (default 7)",
    (char *)" --rows     <number>  Rows on the board (default 6)",
    (char *)" --length   <number>  Length of line required to win (default 4)",
};

HelpText *HelpText_new(char *program_name)
{
    HelpText *self = CLASS_MALLOC(HelpText);


    self->program_name = program_name;
    self->length = sizeof(help_text) / sizeof(*help_text);

    HelpText_apply(self);

    return self;
}

HelpText *HelpText_new_default(void)
{
    return HelpText_new(NULL);
}

void HelpText_apply(HelpText *self)
{
    self->new = HelpText_new_default;
    self->apply = HelpText_apply;
    self->destroy = HelpText_destroy;
    self->start = HelpText_start;
}

void HelpText_destroy(HelpText *self)
{
    free(self->program_name);
    free(self);
}

void HelpText_start(HelpText *self)
{
    int i;

    for (i = 0; i < self->length; i += 1) {
        printf(help_text[i], self->program_name);
        printf("\n");
    }
}
