#ifndef HELP_TEXT_H
#define HELP_TEXT_H

#include "Class.h"
#include "GameManagerInterface.h"

#define HELP_TEXT_PROPS(self_t) \
    CLASS_PROPS(self_t) \
    GAME_MANAGER_INTERFACE_PROPS(self_t) \
    char *program_name; \
    int length;

typedef struct _HelpText HelpText;

struct _HelpText {
    HELP_TEXT_PROPS(HelpText)
};

HelpText *HelpText_new(char *program_name);
HelpText *HelpText_new_default(void);
void HelpText_apply(HelpText *self);
void HelpText_destroy(HelpText *self);
void HelpText_start(HelpText *self);

#endif
