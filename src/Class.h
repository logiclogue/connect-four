#ifndef CLASS_H
#define CLASS_H
#define CLASS_PROPS(self_t) \
    self_t *(*new)(void); \
    void (*apply)(self_t *self); \
    void (*destroy)(self_t *self);

typedef struct _Class Class;

struct _Class {
    CLASS_PROPS(Class)
};

Class *Class_new(void);
void Class_apply(Class *self);
void Class_destroy(Class *self);

#define CLASS_MALLOC(self_t) malloc(sizeof(self_t))

#endif
