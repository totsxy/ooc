//
// Created by sxy on 2020/5/25.
//

#include <string.h>
#include "define.h"

static void *offset(void *this, int i) {
    return ((char *) this) + i;
}

void extend_unbind_methods(void *this) {
    void *base = *((size_t **) this + 2);
    if (!base) return;

    static int x = sizeof(void *);
    static int y = sizeof(size_t) * 2 + sizeof(void *);

    char **dst = offset(this, y);
    char **src = offset(base, y);

    int dc = (*((size_t *) this) - y) / x;
    int sc = (*((size_t *) base) - y) / x;

    for (int i = 0; i < dc; i += 2) {
        if (dst[i + 1]) continue;

        for (int j = 0; j < sc; j += 2) {
            if (strcmp(dst[i], src[j])) continue;
            dst[i + 1] = src[j + 1];
        }
    }
}
