#include "../inc/pathfinder.h"

static void paths_cleanup(t_path* path_list) {

    for (int j = 0; j < path_list->count; ++j) {

        mx_clear_node(&path_list->parents[j]);

    }
    free(path_list->parents);
    path_list->parents = NULL;

}

static void path_realloc(t_path** path, int count, int idx, const char* name, int weight) {
    
    (*path)->parents = mx_realloc((*path)->parents, sizeof(t_list_node) * count);
    (*path)->count = count;
    (*path)->parents[ count - 1 ] = mx_create_node(idx, name, weight);

}

// Free memory, allocated during `mx_dijkstra`'s execution
static void dijkstra_cleanup(t_path** paths, t_list* pq, int size) {

    for (int i = 0; i < size; ++i) {

        paths_cleanup(paths[i]);
        free(paths[i]);

    }
    free(paths);
    mx_clear_list(pq->head);
    free(pq);

}

// Dijkstra's algorithm implementation
void mx_dijkstra(t_graph* graph, t_list_node** nodes, t_list_node* src) {

    int size = graph->size;
    int src_idx = src->index;

    long weights[size];
    t_path** paths = malloc(sizeof(*paths) * size);
    t_list* min_pq = malloc(sizeof(*min_pq));

    for (int i = 0; i < size; ++i) {

        weights[i] = INT_MAX + 1L;
        paths[i] = malloc(sizeof(*(paths[i])));
        paths[i]->parents = NULL;
        path_realloc(&paths[i], 1, -1, NULL, 0);

    }

    min_pq->head = NULL;
    mx_push_back(&min_pq->head, src_idx, src->name, 0);
    weights[src_idx] = 0;
    
    while (min_pq->head != NULL) {

        t_list_node* u_node = NULL;
        mx_copy_node(&u_node, min_pq->head);
        int u_idx = u_node->index;
        mx_pop_front(&min_pq->head);

        t_list_node* adj_vertex = graph->adj_lists[u_idx].head;

        while (adj_vertex != NULL) {

            t_list_node* v_node = mx_create_node(adj_vertex->index, adj_vertex->name, adj_vertex->weight);
            int v_idx = v_node->index;
            long curr_weight = v_node->weight + weights[u_idx];

            if (curr_weight == weights[v_idx]) {

                mx_push_back(&min_pq->head, v_idx, v_node->name, weights[v_idx]);
                path_realloc(&paths[v_idx], paths[v_idx]->count + 1, u_idx, u_node->name, v_node->weight);
                
            } else if (curr_weight < weights[v_idx]) {

                weights[v_idx] = curr_weight;
                mx_push_back(&min_pq->head, v_idx, v_node->name, weights[v_idx]);

                paths_cleanup(paths[v_idx]);
                path_realloc(&paths[v_idx], 1, u_idx, u_node->name, v_node->weight);

            }
            adj_vertex = adj_vertex->next;
            mx_clear_node(&v_node);

        }
        mx_clear_node(&u_node);
        
    }

    for (int i = 0; i < size; ++i) {

        if (i <= src_idx) continue;
        
        t_list_node* u_node = mx_create_node(i, nodes[i]->name, weights[i]);
        mx_handle_paths_for(u_node, paths);
        mx_clear_node(&u_node);

    }

    dijkstra_cleanup(paths, min_pq, size);

}
