#include "../inc/libmx.h"

char *mx_strtrim(const char* str) {

    if (str == NULL) return NULL;

    int begin = 0;
    int end = mx_strlen(str) - 1;

    for (; mx_isspace(str[begin]); ++begin);
    for (; mx_isspace(str[end]); --end);

    if ((begin > mx_strlen(str)) || (end < 0)) 
        return mx_strdup("");

    char* result = mx_strnew(end - begin + 1);
    mx_strncpy(result, &str[begin], end - begin + 1);

    return result;

}
