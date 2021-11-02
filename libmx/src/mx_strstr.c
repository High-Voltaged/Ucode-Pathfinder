#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {

    if (mx_strlen(needle) == 0) return (char*)haystack;

    while (*haystack) {
        
        char *temp = mx_strchr(haystack, needle[0]);

        if ((*haystack == *needle) && mx_strncmp(temp, needle, mx_strlen(needle)) == 0) {
            return temp;
        }
        haystack++;
    }
    return NULL;
}
