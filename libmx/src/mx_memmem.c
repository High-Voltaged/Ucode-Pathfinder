#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {

    if (big == NULL || little == NULL) 
        return NULL; 
    
    if (big_len == 0 || little_len == 0 || little_len > big_len) 
        return NULL;

    for (const unsigned char *hayst = big; big_len >= little_len; ++hayst, --big_len) {
        if (!mx_memcmp(hayst, little, little_len)) {
            return (void*) hayst;
        }
    }
    return NULL;

}
