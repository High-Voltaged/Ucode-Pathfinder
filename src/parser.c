#include "../inc/pathfinder.h"

// Save all the file lines and number of vertices
void mx_get_file_util(const char* file_name, char*** file_lines, int* node_count) {

    char* file_str = mx_file_to_str(file_name);
    *file_lines = mx_strsplit(file_str, '\n');
    *node_count = mx_atoi((*file_lines)[0]);
    mx_strdel(&file_str);

}

// Parse a single file line to get a graph edge's info and save it into `graph`
void mx_parse_edge(char* line, t_graph** graph, t_list_node** nodes) {

    char** edge_line = mx_strsplit(line, ',');
    char** edge_pair = mx_strsplit(edge_line[0], '-');
    int edge_weight = mx_atoi(edge_line[1]);

    t_graph_edge* edge = malloc(sizeof(*edge));
    edge->src = *mx_get_node_by_name(nodes, edge_pair[0], (*graph)->size);
    edge->dest = *mx_get_node_by_name(nodes, edge_pair[1], (*graph)->size);
    edge->src->weight = edge->dest->weight = edge_weight;

    mx_add_graph_edge(*graph, edge);

    free(edge);
    mx_del_strarr(&edge_pair);
    mx_del_strarr(&edge_line);

}

// Parse all file lines, fill the `graph`'s edges and get an array of vertices
t_list_node** mx_parse_file_lines(t_graph* graph, char** file_lines) {

    int node_count = graph->size;
    t_list_node** nodes = malloc(sizeof(*nodes) * (node_count));
    
    char** node_names = mx_get_node_names(file_lines, node_count);

    for (int node_idx = 0; node_idx < node_count; ++node_idx) {

        nodes[node_idx] = mx_create_node(node_idx, node_names[node_idx], 0);

    }

    for (int i = 1; file_lines[i] != NULL; ++i) {

        mx_parse_edge(file_lines[i], &graph, nodes);

    }

    mx_del_strarr(&node_names);
    mx_del_strarr(&file_lines);

    return nodes;

}
