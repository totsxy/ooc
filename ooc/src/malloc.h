//
// Created by sxy on 2020/5/27.
// The allocation and recycling of memory used by objects.
//

#ifndef OOC_MALLOC_H
#define OOC_MALLOC_H

#include "object.h"

void *_new(void *clazz, ...);

#define new(classT, ...) ((classT *)_new(classOf(classT), ##__VA_ARGS__))

void _free(void *this);

#define del(this) _free(this)

#endif //OOC_MALLOC_H
