#include <stdlib.h>
#include "Class.h"

Class *Class_new(void)
{
    Class *self = malloc(sizeof(Class));

    Class_apply(self);

    return self;
}

void Class_apply(Class *self)
{
    self->new = Class_new;
    self->apply = Class_apply;
    self->destroy = Class_destroy;
}

void Class_destroy(Class *self)
{
    free(self);
}
