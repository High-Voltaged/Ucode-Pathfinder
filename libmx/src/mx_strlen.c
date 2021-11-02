#include "../inc/libmx.h"

int mx_strlen(const char* s) {
    if (s == NULL) return 0;
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}
