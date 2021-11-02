#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {

    size_t s1_len = mx_strlen(s1);
    size_t res_len = (n > s1_len) ? s1_len : n;
    char* result = mx_strnew(res_len);
    
    if (result == NULL) return NULL;

    return mx_strncpy(result, s1, res_len);

}
