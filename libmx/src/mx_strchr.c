#include <stddef.h>

char *mx_strchr(const char* s, int c) {

    int size = 0;
    for (; s[size] != '\0'; ++size);
    for (int i = 0; i < size + 1; ++i) {

        if (s[i] == c) {
            char* c = (char*)&s[i];
            return c;
        }

    }
    return NULL;

}
