#include "../inc/pathfinder.h"

t_list_node *mx_create_node(int idx, const char* name, int weight) {

    t_list_node *node = malloc(sizeof(t_list_node));
    node->name = !name ? NULL : mx_strdup(name);
    node->index = idx;
    node->weight = weight;
    node->next = NULL;
    return node;

}

void mx_push_front(t_list_node **list, int idx, const char* name, int weight) {

    t_list_node* new_node = mx_create_node(idx, name, weight);

    if (list != NULL && *list == NULL) {
        *list = new_node;
        return;
    }

    new_node->next = *list;
    *list = new_node;

}

void mx_push_back(t_list_node **list, int idx, const char* name, int weight) {

    t_list_node* new_node = mx_create_node(idx, name, weight);
    if (list != NULL && *list == NULL) {
        *list = new_node;
        return;
    }

    t_list_node* last = *list;
    while (last->next != NULL) {
        last = last->next;
    } 

    new_node->next = last->next;
    last->next = new_node;

}

void mx_pop_front(t_list_node **head) {

    if (head == NULL || *head == NULL) return; 

    if ((*head)->next == NULL) {
        mx_clear_node(head);
        *head = NULL;
        return;
    }

    t_list_node* temp = *head;
    *head = (*head)->next;
    mx_clear_node(&temp);

}

void mx_clear_list(t_list_node *list) {

    t_list_node* current = list;
    t_list_node* next = NULL;
    while (current != NULL) {

        next = current->next;
        mx_clear_node(&current);
        current = next;

    }
    list = NULL;

}

void mx_clear_node(t_list_node** node) {

    mx_strdel(&(*node)->name);
    free(*node);

}

void mx_copy_list(t_list_node** dest, t_list_node* src) {

    if (dest != NULL && *dest != NULL) {
        mx_clear_list(*dest);
        *dest = NULL;
    }

    while (src) {

        mx_push_back(dest, src->index, src->name, src->weight);
        src = src->next;

    }

}

t_list_node* mx_copy_node(t_list_node** dest, t_list_node* src) {

    if (dest != NULL && *dest != NULL) {
        mx_clear_node(dest);
    }

    *dest = mx_create_node(src->index, src->name, src->weight);
    return *dest;

}

t_list_node** mx_get_node_by_name(t_list_node** nodes, const char* name, int size) {

    for (int i = 0; i < size; ++i) {

        if (mx_strcmp(nodes[i]->name, name) == 0)
            return &nodes[i];

    }
    return NULL;

}

int mx_list_size(t_list_node* list) {

    if (list == NULL) return 0;

    t_list_node* head = list;
    int size = 0;
    while (head != NULL) {

        head = head->next;
        ++size;

    }
    return size;

}
