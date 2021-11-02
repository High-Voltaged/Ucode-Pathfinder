#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {

    if ((unsigned char*) dst < (unsigned char*) src) {

        return mx_memcpy(dst, src, len);

    }
    unsigned char* tmp_dst = dst;
    const unsigned char* tmp_src = src;

    for (int i = len; i > 0; --i) {

        tmp_dst[i - 1] = tmp_src[i - 1];

    }
    return dst;

}
