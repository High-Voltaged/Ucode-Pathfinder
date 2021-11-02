#include "../inc/libmx.h"

void *mx_memchr(const void* s, int c, size_t n) {

    if (s == NULL) return NULL;

    const unsigned char* c_s = (const unsigned char*) s;
    for (int i = 0; n--; ++i) {

        if (c_s[i] == c) {
            return (unsigned char*)&c_s[i];
        }

    }
    return NULL;

}
