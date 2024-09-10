//
// Created by sxy on 2020/5/14.
// The root class of the class hierarchy.
//

#ifndef OOC_OBJECT_H
#define OOC_OBJECT_H

#include <stdarg.h>
#include <stddef.h>

#include "kernel.h"

class(Object) {
    size_t _ooc_sizc, _ooc_sizo;
    void *super;

    define(Object, void, ctor, va_list *val);

    define(Object, void *, dtor);

    define(Object, hash_t, hash);

    define(Object, void *, copy);
};

value(Object) {
    union {
        ObjectClass *_ooc_clazz;
    } _ooc_heads;
};

#endif //OOC_OBJECT_H
