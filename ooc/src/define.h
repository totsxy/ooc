//
// Created by sxy on 2020/5/25.
// Common components of OOC framework.
//

#ifndef OOC_DEFINE_H
#define OOC_DEFINE_H

#include "object.h"

#define init_class(superT, classT)  \
    size_t _ooc_sizc, _ooc_sizo;    \
    superT##Class  *super;          \
                                    \
    define(classT, void, ctor, va_list * val);      \
                                    \
    define(classT, void *, dtor);   \
                                    \
    define(classT, hash_t, hash);   \
                                    \
    define(classT, void *, copy)

#define classOf(classT) (Get##classT##Class())

#define superOf(classT) classOf(classT)->super

#define init_value(superT, classT)  \
    union {                         \
        classT##Class *_ooc_clazz;  \
        superT _ooc_support_super;  \
    } _ooc_heads

#define $call ->_ooc_heads._ooc_clazz->

void extend_unbind_methods(void *this);

#endif //OOC_DEFINE_H
