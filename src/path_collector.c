#include "../inc/pathfinder.h"

// Check if the same path was already saved 
static bool is_path_saved(t_list_node** arr, t_list_node** list, int count) {

    t_list_node* list_init = *list;
    for (int i = 0; i < count; ++i) {

        t_list_node* arr_head = arr[i];
        t_list_node* list_head = list_init;
        bool is_present = true;
        while (arr_head && list_head) {

            if (arr_head->index != list_head->index) {
                is_present = false;
                break;
            }
            arr_head = arr_head->next;
            list_head = list_head->next;

        }
        if (is_present) return true;

    }
    return false;

}

// Build a path for a given node based on the given SPT (Shortest-Path Tree)
static void set_path(t_list_node* u_node, t_list_node** current_path, t_list_node*** all_paths, t_path** paths, int* count) {

    int u_idx = u_node->index;
    if (u_idx == -1) {
        t_list_node **arr = *all_paths;
        if (!is_path_saved(arr, current_path, *count)) {

            arr = mx_realloc(arr, sizeof(*arr) * (*count + 1));
            arr[*count] = NULL;
            mx_copy_list(&arr[(*count)++], *current_path);
            *all_paths = arr;

        }
        return;
    }
    mx_push_front(current_path, u_idx, u_node->name, u_node->weight);
    for (int i = 0; i < paths[u_idx]->count; i++) {

        set_path(paths[u_idx]->parents[i], current_path, all_paths, paths, count);
    
    }
    mx_pop_front(current_path);

}

// Get all paths for the given node
static t_list_node** collect_paths_for(t_list_node* u, t_path** paths, int* count) {
  
    t_list_node** all_paths = NULL;
    t_list_node* current_path = NULL;

    *count = 0;
    set_path(u, &current_path, &all_paths, paths, count);
    
    return all_paths;

}

// Get and print paths for a given node
void mx_handle_paths_for(t_list_node* u_node, t_path** paths) {

    int count = 0;
    t_list_node** paths_collected = collect_paths_for(u_node, paths, &count);
    
    mx_sort_paths(&paths_collected, count);
    mx_print_paths(paths_collected, count);
    
    for (int p = 0; p < count; ++p) {

        mx_clear_list(paths_collected[p]);

    }
    free(paths_collected);

}
