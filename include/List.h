#ifndef LIST_H
#define LIST_H

#include <Constants.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    size_t size;
} List;

//INSTANCE MANAGER
List* new_list(); // create a new list
boolean delete_list(List *list); // delete a list

//ADD NODE MANAGER
boolean add_first_list(List *list, void *data);             // add a data to the beginning of the list
boolean add_last_list(List *list, void *data);              // add a data to the last of the list
boolean insert_list(List *list, void *data, size_t index);   // insert a data in the index of the list

// DELETE NODE MANAGER
boolean delete_node_list(List *list, size_t index, boolean with_data);              // REMOVE A NODE IN THE INDEX
boolean delete_all_nodes_list(List *list, boolean with_data);
boolean delete_first_node_list(List *list, boolean with_data);                      // REMOVE FIRST NODE
boolean delete_last_node_list(List *list, boolean with_data);                       // REMOVE LAST NODE

// GET MANAGER
const Node* get_node_list(List *list, size_t index);              // GET THE NODE IN THE INDEX
void* get_data_list(List *list, size_t index);              // GET THE NODE IN THE INDEX

// UTILS
boolean is_empty_list(List *list);                          // LIST IS EMPTY?
boolean reverse_list(List *list);                           // REVERSE THE LIST

#endif // LIST_H
