#include "../inc/pathfinder.h"

// Create a graph, containing its size and adjacency lists
t_graph* mx_create_graph(int size) {

    t_graph* graph = malloc(sizeof(t_graph));
    graph->size = size;
    graph->adj_lists = malloc(size * sizeof(t_list));

    for (int i = 0; i < size; ++i) {

        graph->adj_lists[i].head = NULL;

    }
    return graph;

}

// Add an edge to a graph's adjacency lists
void mx_add_graph_edge(t_graph* graph, t_graph_edge* edge) {

    int src_idx = edge->src->index;
    int dest_idx = edge->dest->index;

    mx_push_back(&(graph->adj_lists[src_idx].head), dest_idx, edge->dest->name, edge->dest->weight);
    mx_push_back(&(graph->adj_lists[dest_idx].head), src_idx, edge->src->name, edge->src->weight);

}

// Free memory, allocated for the graph and its members
void mx_clear_graph(t_graph** graph) {

    for (int i = 0; i < (*graph)->size; ++i) {

        mx_clear_list((*graph)->adj_lists[i].head);

    }
    free((*graph)->adj_lists);
    free(*graph);
    
}
