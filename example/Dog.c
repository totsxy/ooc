//
// Created by sxy on 2020/6/1.
//

#include <stdio.h>
#include "Dog.h"

method(Dog, void, ctor, va_list *val) {
    superOf(Dog)->ctor((Animal *) self, val);
}

method(Dog, void *, dtor) {
    return superOf(Dog)->dtor((Animal *) self);
}

method(Dog, void, talk) {
    printf("I'm dog, My age is %d .\n", ((Animal *) self)->age);
}

DogClass *GetDogClass() {
    static DogClass clazz = {
            sizeof(DogClass), sizeof(Dog), NULL,
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
