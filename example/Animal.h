//
// Created by sxy on 2020/5/27.
//

#include "../ooc/src/define.h"

#ifndef OOC_ANIMAL_H
#define OOC_ANIMAL_H

class(Animal) {
    init_class(Object, Animal);

    define(Animal, void, talk);

    define(Animal, void, type);
};

value(Animal) {
    init_value(Object, Animal);
    int age;
};

#endif //OOC_ANIMAL_H
