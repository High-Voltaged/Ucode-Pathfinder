#include "../inc/pathfinder.h"

// Check the node's name's format
static void check_node(const char* edge_line, int* curr_idx) {

    while (mx_isalpha(edge_line[*curr_idx])) {
        ++(*curr_idx);
    }

}

// Check edge's weight's format
static int check_edge_weight(const char** line, int ch_idx, int line_idx, int size) {

    char* weight_num = mx_strndup(&(*line)[ch_idx], size);
    int weight_num_i = mx_atoi(weight_num);
    
    if (weight_num_i == 0) {
        mx_print_line_err(line_idx);
        exit(0);
    }
    
    mx_strdel(&weight_num);

    return weight_num_i;

}

// Check if two nodes of the edge are identical
static void check_if_identical(const char* line, int first_len, int second_len, int line_idx) {

    char* first = mx_strndup(line, first_len);
    line += first_len + 1;
    char* second = mx_strndup(line, second_len);
    if (mx_strcmp(first, second) == 0) {
        mx_print_line_err(line_idx);
        exit(0);
    }
    mx_strdel(&first);
    mx_strdel(&second);

}

// Check full line's format
void mx_check_line(const char* file_line, int line_idx, unsigned long* bridges_sum) {

    int i = 0;
    check_node(file_line, &i);

    if (i == 0 || file_line[i] != '-') {
        mx_print_line_err(line_idx);
        exit(0);
    }

    int first_len = ++i;
    check_node(file_line, &i);

    if (i == first_len || file_line[i] != ',') {
        mx_print_line_err(line_idx);
        exit(0);
    }

    int second_len = ++i;
    while (mx_isdigit(file_line[i])) {
        ++i;
    }

    if (i == second_len || file_line[i] != '\0') {
        mx_print_line_err(line_idx);
        exit(0);
    }

    int weight_num_i = check_edge_weight(&file_line, second_len, line_idx, i - second_len + 1);
    *bridges_sum += weight_num_i;
    
    check_if_identical(file_line, first_len - 1, second_len - first_len - 1, line_idx);

}

// Check the first line's format
void mx_check_first_line(const char* line) {
    
    int i = 0;
    while (mx_isdigit(line[i])) {
        ++i;
    }
    if (i == 0 || line[i] != '\0') {

        mx_printerr(FIRST_LINE_ERR);
        exit(0);

    } 

}
