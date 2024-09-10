//
// Created by sxy on 2020/6/1.
//

#include <stdio.h>
#include "Cat.h"

method(Cat, void, ctor, va_list *val) {
    superOf(Cat)->ctor((Animal *) self, val);
}

method(Cat, void *, dtor) {
    return superOf(Cat)->dtor((Animal *) self);
}

method(Cat, void, talk) {
    printf("I'm cat, My age is %d .\n", ((Animal *) self)->age);
}

CatClass *GetCatClass() {
    static CatClass clazz = {
            sizeof(CatClass), sizeof(Cat), NULL,
            method_bind_to_func(ctor),
            method_bind_to_func(dtor),
            method_bind_to_null(hash),
            method_bind_to_null(copy),
            method_bind_to_func(talk),
            method_bind_to_null(type),
    };

    static int i = 1;
    if (i) {
        clazz.super = classOf(Animal);
        extend_unbind_methods(&clazz), i = 0;
    }

    return &clazz;
}
