#include "../inc/pathfinder.h"

void mx_print_line_err(int index) {

    mx_printerr("error: line ");
    char* str_idx = mx_itoa(index);
    mx_printerr(str_idx);
    mx_printerr(" is not valid\n");
    mx_strdel(&str_idx);

}

// Check if there're duplicate bridges
static void check_for_dups(char** lines) {

    for (int i = 1; lines[i] != NULL; ++i) {

        for (int j = i + 1; lines[j] != NULL; ++j) {

            char* temp_line = mx_strndup(lines[i], mx_get_char_index(lines[i], ','));
            char* temp_prev = mx_strndup(lines[j], mx_get_char_index(lines[j], ','));
            
            if (mx_strcmp(temp_line, temp_prev) == 0) {
                mx_printerr(DUPLICATE_ERR);
                exit(0);
            }
            
            mx_strdel(&temp_line);
            mx_strdel(&temp_prev);

        }

    }

}

// Check if all bridges' sum exceeds INT_MAX
static void check_bridges(unsigned long bridges_sum) {

    if (bridges_sum > INT_MAX) {
        mx_printerr(BRIDGES_SUM_ERR);
        exit(0);
    }

}

// Check all file lines
static void check_lines(const char* file_str) {

    char** file_lines = mx_strsplit(file_str, '\n');

    mx_check_first_line(file_lines[0]);

    unsigned long bridges_sum = 0;
    for (int i = 1; file_lines[i] != NULL; ++i) {

        mx_check_line(file_lines[i], i + 1, &bridges_sum);

    }

    char** names = mx_get_node_names(file_lines, mx_atoi(file_lines[0]));

    check_for_dups(file_lines);
    check_bridges(bridges_sum);

    mx_del_strarr(&file_lines);
    mx_del_strarr(&names);

}

// Check the file for errors & initiate total error handling
void mx_handle_errors(char** args, int arg_count) {

    if (arg_count != 2) {
        mx_printerr(USAGE_ERR);
        exit(0);
    }

    int file_des;
    if ((file_des = open(args[1], O_RDONLY)) < 0) {
        mx_printerr(FILE_ERR);
        mx_printerr(args[1]);
        mx_printerr(NO_EXIST_ERR);
        exit(0);
    }
    close(file_des);

    char* file_str = mx_file_to_str(args[1]);
    if (mx_strlen(file_str) == 0) {
        mx_printerr(FILE_ERR);
        mx_printerr(args[1]);
        mx_printerr(FILE_EMTY_ERR);
        exit(0);
    }

    check_lines(file_str);

    mx_strdel(&file_str);

}
