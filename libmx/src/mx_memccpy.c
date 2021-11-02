#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {

    unsigned char* c_dst = (unsigned char *)dst;
    const unsigned char* c_src = (const unsigned char *)src;
    unsigned char* ptr = NULL;
    for (size_t i = 0; (i < n) && !ptr; ++i) {
        
        c_dst[i] = c_src[i];
        if (c_src[i] == c) {
            ptr = c_dst + i + 1;
        }
    
    }
    return ptr;

}
