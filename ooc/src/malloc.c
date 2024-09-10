//
// Created by sxy on 2020/5/27.
//

#include <malloc.h>
#include <assert.h>
#include <stdarg.h>

#include "malloc.h"

void *_new(void *clazz, ...) {
    size_t sizo = *((size_t *) clazz + 1);
    assert(sizo);

    void *this = malloc(sizo);
    assert(this);
    *((void **) this) = clazz;

    va_list args;
    va_start(args, clazz);
    ((ObjectClass *) clazz)->ctor(this, &args);
    va_end(args);

    return this ? this : NULL;
}

void _free(void *this) {
    free((*(ObjectClass **) this)->dtor(this));
}
