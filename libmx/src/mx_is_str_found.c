#include "../inc/libmx.h"

bool mx_is_str_found(char** strarr, const char* str) {

    for (int i = 0; strarr[i] != NULL; ++i) {

        if (mx_strcmp(strarr[i], str) == 0)
            return true;

    }
    // while (list) {

    //     if (mx_strcmp(list->name, str) == 0) {
    //         return true;
    //     }
    //     list = list->next;

    // }
    return false;

}
