#ifndef CLASS_H
#define CLASS_H
#define CLASS_PROPS(self_t) \
    void (*destroy)(self_t *self);

typedef struct _Class Class;

struct _Class {
    CLASS_PROPS(Class)
};

#endif
