#ifndef PATH_FINDER
#define PATH_FINDER

#include "../libmx/inc/libmx.h"
#include "graph.h"
#include "const.h"

// PARSING

void mx_get_file_util(const char* file_name, char*** file_lines, int* node_count);
char** mx_get_node_names(char** file_lines, int node_count);
t_list_node** mx_parse_file_lines(t_graph* graph, char** file_lines);
char* mx_find_str(char** line, char symbol);

// LISTS

t_list_node *mx_create_node(int idx, const char* name, int weight);
void mx_clear_list(t_list_node *list);
void mx_clear_node(t_list_node** node);
void mx_push_front(t_list_node **list, int idx, const char* name, int weight);
void mx_push_back(t_list_node **list, int idx, const char* name, int weight);
void mx_pop_front(t_list_node **head);\
void mx_copy_list(t_list_node** dest, t_list_node* src);
t_list_node* mx_copy_node(t_list_node** dest, t_list_node* src);
int mx_list_size(t_list_node* list);
t_list_node** mx_get_node_by_name(t_list_node** nodes, const char* name, int size);

// GRAPH

t_graph* mx_create_graph(int size);
void mx_add_graph_edge(t_graph* graph, t_graph_edge* edge);
void mx_clear_graph(t_graph** graph);
void mx_dijkstra(t_graph* graph, t_list_node** nodes, t_list_node* src);

// PATHS' HANDLING

void mx_sort_paths(t_list_node*** paths, int count);
void mx_handle_paths_for(t_list_node* u_node, t_path** paths);

// OUTPUT

void mx_print_paths(t_list_node** paths, int size);

// ERROR_HANDLING

void mx_print_line_err(int index);
void mx_handle_errors(char** args, int arg_count);
void mx_check_line(const char* file_line, int line_idx, unsigned long* bridges_sum);
void mx_check_first_line(const char* line);

#endif
