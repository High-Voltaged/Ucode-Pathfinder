#include "../inc/libmx.h"

void mx_foreach_list(t_list_t *list, void (*f)(t_list_t* node)) {

    t_list_t* current = list;
    while (current != NULL) {

        f(current);
        current = current->next;

    }

}
