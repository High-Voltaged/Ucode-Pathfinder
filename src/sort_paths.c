#include "../inc/pathfinder.h"

// Compare two paths based on their nodes' indices
static bool pathcmp(t_list_node* path1, t_list_node* path2) {

    bool is_greater = false;
    while (path1 && path2) {

        if (path2->index > path1->index) {
            is_greater = true;
        }

        if (path1->index > path2->index && !is_greater)    
            return true;

        path1 = path1->next;
        path2 = path2->next;

    }
    return false;

}

// Swap two paths by copying originals
static void path_swap(t_list_node*** paths, int first_idx, int second_idx) {

    t_list_node* f_list = NULL;
    mx_copy_list(&f_list, (*paths)[first_idx]);
    mx_copy_list(&(*paths)[first_idx], (*paths)[second_idx]);
    mx_copy_list(&(*paths)[second_idx], f_list);
    mx_clear_list(f_list);

}

// Sort paths based on their nodes' indices
void mx_sort_paths(t_list_node*** paths, int count) {

    bool was_swapped = false;
    for (int i = 0; i < count - 1; ++i) {

        was_swapped = false;
        for (int j = 0; j < count - i - 1; ++j) {

            if (pathcmp((*paths)[j], (*paths)[j + 1])) {
                path_swap(paths, j, j + 1);
                was_swapped = true;
            }

        }
        if (!was_swapped) break;

    }

}
