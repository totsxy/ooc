//
// Created by sxy on 2020/6/1.
//

#ifndef OOC_CAT_H
#define OOC_CAT_H

#include "Animal.h"

class(Cat) {
    init_class(Animal, Cat);

    define(Cat, void, talk);

    define(Cat, void, type);
};

value(Cat) {
    init_value(Animal, Cat);
};

#endif //OOC_CAT_H
