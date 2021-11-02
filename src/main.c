#include "../inc/pathfinder.h"

// Free memory, allocated during `pathfinder_init`'s execution
static void pathfinder_cleanup(t_graph** graph, t_list_node** nodes) {

    for (int i = 0; i < (*graph)->size; ++i) {

        mx_clear_node(&nodes[i]);

    }
    free(nodes);
    mx_clear_graph(graph);

}

// Save all needed file info and initiate the Dijkstra's algorithm
static void pathfinder_init(const char* file_name, t_graph** graph) {

    int size = 0;
    char** file_lines = NULL;

    mx_get_file_util(file_name, &file_lines, &size);
    *graph = mx_create_graph(size);
    
    t_list_node** nodes = mx_parse_file_lines(*graph, file_lines);
    for (int i = 0; i < size; ++i) {

        mx_dijkstra(*graph, nodes, nodes[i]);

    }
    pathfinder_cleanup(graph, nodes);

}

int main(int argc, char* argv[]) {

    mx_handle_errors(argv, argc);

    t_graph* graph = NULL;
    pathfinder_init(argv[1], &graph);
    
    return 0;

}
