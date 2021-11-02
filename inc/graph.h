#ifndef GRAPH_H
#define GRAPH_H

typedef struct s_lnode {
    int index;
    int weight;
    char* name;
    struct s_lnode* next;
}              t_list_node;

typedef struct s_list {
    t_list_node* head;
}              t_list;

typedef struct s_graph_edge {
    t_list_node* src;
    t_list_node* dest;
}              t_graph_edge;

typedef struct s_graph {
    int size;
    t_list* adj_lists;
}              t_graph;

typedef struct s_path {
    int count;
    t_list_node** parents;
}              t_path;

#endif
