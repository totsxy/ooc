//
// Created by sxy on 2020/5/14.
//

#include <string.h>
#include <malloc.h>

#include "object.h"

static size_t _size_o(void *object) {
    return *(*((size_t **) object) + 1);
}

method(Object, void, ctor, va_list *val) {
    // Constructor's empty implementation.
}

method(Object, void *, dtor) {
    size_t i = *(*((size_t **) self) + 1);
    return memset(self, 0, i);
}

method(Object, hash_t, hash) {
    size_t i = *(*((size_t **) self) + 1);
    hash_t ht = (unsigned long) self >> 3;
    return ht ^ (ht >> i % 3);
}

method(Object, void *, copy) {
    size_t i = *(*((size_t **) self) + 1);
    return memcpy(malloc(i), self, i);
}

ObjectClass *GetObjectClass() {
    static ObjectClass this = {
            sizeof(ObjectClass), sizeof(Object), NULL,
            method_bind_to_func(ctor),
            method_bind_to_func(dtor),
            method_bind_to_func(hash),
            method_bind_to_func(copy),
    };
    return &this;
}
