//
// Created by sxy on 2020/6/1.
//

#ifndef OOC_DOG_H
#define OOC_DOG_H

#include "Animal.h"

class(Dog) {
    init_class(Animal, Dog);

    define(Dog, void, talk);

    define(Dog, void, type);
};

value(Dog) {
    init_value(Animal, Dog);
};

#endif //OOC_DOG_H
