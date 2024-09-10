//
// Created by sxy on 2020/5/27.
//

#include <stdio.h>
#include "Animal.h"

method(Animal, void, ctor, va_list *val) {
    self->age = va_arg(*val, int);
}

method(Animal, void *, dtor) {
    return superOf(Animal)->dtor((Object *) self);
}


method(Animal, void, talk) {
    printf("My age is %d .\n", self->age);
}

method(Animal, void, type) {
    printf("I'm a cute little animal.\n");
}

AnimalClass *GetAnimalClass() {
    static AnimalClass clazz = {
            sizeof(AnimalClass), sizeof(Animal),
            NULL,
            method_bind_to_func(ctor),
            method_bind_to_func(dtor),
            method_bind_to_null(hash),
            method_bind_to_null(copy),
            method_bind_to_func(talk),
            method_bind_to_func(type),
    };

    static int i = 1;
    if (i) {
        clazz.super = classOf(Object);
        extend_unbind_methods(&clazz), i = 0;
    }

    return &clazz;
}
