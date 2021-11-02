#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {

    if (s1 == s2 || n == 0) 
        return 0;

    const unsigned char* c_s1 = (const unsigned char*) s1;
    const unsigned char* c_s2 = (const unsigned char*) s2;
    while (n && *c_s1 && (*c_s1 == *c_s2)) {

        ++c_s1;
        ++c_s2;
        --n;
    
    }

    if (n == 0) return 0;

    return *c_s1 - *c_s2;

}
