#include "../inc/pathfinder.h"

// Get a string from a line, cut until 'symbol'
char* mx_find_str(char** line, char symbol) {

    int symb_count = mx_get_char_index(*line, symbol);
    char* result = mx_strndup(*line, symb_count);
    *line += (symb_count + 1);
    return result;

}

// Save a new vertex's name if it wasn't saved before
void mx_add_node_name(char*** lines, char** line, char symbol, int* index, int node_count) {

    char* new_node_name = mx_find_str(line, symbol);
    if (!mx_is_str_found(*lines, new_node_name)) {
        (*lines)[(*index)++] = new_node_name;
    } else {
        mx_strdel(&new_node_name);
    }
    if (*index > node_count) {
        mx_printerr(ISLAND_NUM_ERR);
        exit(0);
    }

}

// Get vertices' names as strings
char** mx_get_node_names(char** file_lines, int node_count) {

    char** node_names = malloc(sizeof(*node_names) * (node_count + 1));
    for (int i = 0; i < node_count + 1; ++i) {
        node_names[i] = NULL;
    }
    int name_idx = 0;
    for (int i = 1; file_lines[i] != NULL; ++i) {

        char* line = file_lines[i];
        mx_add_node_name(&node_names, &line, '-', &name_idx, node_count);
        mx_add_node_name(&node_names, &line, ',', &name_idx, node_count);
        
    }
    if (name_idx < node_count) {
        mx_printerr(ISLAND_NUM_ERR);
        exit(0);
    }
    return node_names;

}
