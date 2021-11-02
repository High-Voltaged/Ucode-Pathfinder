#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {

    if (str == NULL) return NULL;

    char* result = mx_strtrim(str);

    int x = 0;
    for (int i = 0; result[i] != '\0'; ++i) {

        if (!mx_isspace(result[i])) {
            result[x++] = result[i];
        }

        if (!mx_isspace(result[i]) && mx_isspace(result[i + 1])) {
            result[x++] = ' ';
        }

    }
    result[x] = '\0';
    return result;

}
