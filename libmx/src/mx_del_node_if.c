#include "../inc/libmx.h"

void mx_del_node_if(t_list_t **list, void *del_data, bool (*cmp)(void *a, void* b)) {

    t_list_t* previous = *list;
    t_list_t* current = (*list)->next;

    if (current != NULL) {

        while (current->next) {
        
            if (cmp(&current->data, del_data)) {
                previous->next = current->next;
                free(current);
                current = previous->next;
            } else {
                previous = previous->next;
                current = current->next;
            }
        }
        if (cmp(&current->data, del_data)) {
            previous->next = NULL;
            free(current);
        }

        current = *list;
        if (cmp(&current->data, del_data)) {
            (*list) = (*list)->next;
            free(current);
        }

    } else {

        if (cmp(&previous->data, del_data)) free(*list);
    
    }

}
