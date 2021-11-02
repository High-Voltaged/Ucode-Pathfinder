#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {

    if (!str || !sub || !replace)
        return NULL;

    int pos_idx = 0;
    int sub_len = mx_strlen(sub);
    int rep_len = mx_strlen(replace);
    int rep_count = mx_count_substr(str, sub);

    char* result = mx_strnew(mx_strlen(str) + (rep_len - sub_len) * rep_count);
    if (result == NULL) return NULL;
    char* temp = result;

    while (rep_count--) {
        pos_idx = mx_get_substr_index(str, sub);
        temp = mx_strncpy(temp, str, pos_idx) + pos_idx;
        temp = mx_strcpy(temp, replace) + rep_len;
        str += pos_idx + sub_len;
    }
    mx_strcpy(temp, str);
    return result;

}
