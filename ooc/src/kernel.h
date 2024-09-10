//
// Created by sxy on 2020/5/14.
// Kernel components of OOC framework.
//

#ifndef OOC_KERNEL_H
#define OOC_KERNEL_H

#define hash_t unsigned long

#define class(classT)                           \
    typedef struct _ooc_##classT classT;        \
    typedef struct _ooc_##classT##Class classT##Class;  \
    classT##Class *Get##classT##Class();        \
    struct _ooc_##classT##Class

#define value(classT) struct _ooc_##classT

#define define(classT, ret, func, ...)          \
    char *_ooc_func_##func##_name;              \
    ret (*func)(classT *self, ##__VA_ARGS__)

#define method(classT, ret, func, ...) static ret func(classT *self, ##__VA_ARGS__)

#define method_bind_to_func(func) #func, func

#define method_bind_to_null(func) #func, NULL

#endif //OOC_KERNEL_H
