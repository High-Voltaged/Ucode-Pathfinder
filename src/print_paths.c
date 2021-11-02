#include "../inc/pathfinder.h"

static void print_separator() {

    for (int i = 0; i < 40; ++i) {

        mx_printchar(SEPARATOR_CH);

    }
    mx_printstr("\n");

}

static void print_path_node(const char* name, bool is_last) {

    mx_printstr(name);
    if (!is_last)
        mx_printstr(ARROW_STR);

}

static void print_route_line(t_list_node* path) {

    mx_printstr(ROUTE_STR);
    while (path) {

        print_path_node(path->name, path->next ? false : true);
        path = path->next;

    }
    mx_printstr("\n");

}

static void print_dist_line(t_list_node* path) {

    int path_node_count = mx_list_size(path);
    mx_printstr(DIST_STR);
    while (path->next) {

        mx_printint(path->weight);
        if (path_node_count > 2 && path->next->next) {
            mx_printstr(PLUS_STR);
        }
        path = path->next;

    }
    if (path_node_count > 2) {
        mx_printstr(EQUALS_STR);
        mx_printint(path->weight);
    }
    mx_printstr("\n");

}

static void print_path_list(t_list_node* path_node) {

    t_list_node* last = path_node;
    while (last->next != NULL) {
        last = last->next;
    }
    
    print_separator();

    mx_printstr(PATH_STR);
    print_path_node(path_node->name, false);
    print_path_node(last->name, true);
    mx_printstr("\n");

    print_route_line(path_node);
    print_dist_line(path_node);

    print_separator();

    path_node = path_node->next;

}

void mx_print_paths(t_list_node** paths, int size) {

    for (int i = 0; i < size; ++i) {
        print_path_list(paths[i]);
    }

}
