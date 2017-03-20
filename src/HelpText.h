#ifndef HELP_TEXT_H
#define HELP_TEXT_H

#include "Class.h"
#include "GameManagerInterface.h"

#define HELP_TEXT_PROPS(self_t) \
    CLASS_PROPS(self_t) \
    GAME_MANAGER_INTERFACE_PROPS(self_t) \
    char *program_name; \
    char *help_text;

typedef struct _HelpText HelpText;

struct _HelpText {
    HELP_TEXT_PROPS(HelpText)
}

CliGame *CliGame_new(char *help_text);
CliGame *CliGame_new_default(void);
void CliGame_apply(CliGame *self);
void CliGame_destroy(CliGame *self);
void CliGame_start(CliGame *self);

#endif
