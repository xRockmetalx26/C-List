#include <stdio.h>
#include <stdlib.h>
#include <List.h>
#include <Error.h>

Node* new_node(void *data) {
    Node *node = (Node*) malloc(sizeof(Node));

    if(!node) {
        print_error(NULL_MALLOC);
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

List* new_list() {
    List *list = (List*) calloc(1, sizeof(List));

    if(!list) {
        print_error(NULL_MALLOC);
        return NULL;
    }

    return list;
}

boolean delete_list(List *list) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    free(list);

    return true;
}

boolean add_first_list(List *list, void *data) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    Node *node_new = new_node(data);

    if(!node_new) {
        print_error(NULL_NODE);
        return false;
    }

    if(!list->first) list->first = list->last = node_new;
    else {
        node_new->next = list->first;
        list->first = node_new;
    }

    list->size++;

    return true;
}

boolean add_last_list(List *list, void *data) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    Node *node_new = new_node(data);

    if(!node_new) {
        print_error(NULL_NODE);
        return false;
    }

    if(!list->first) list->first = list->last = node_new;

    else list->last = list->last->next = node_new;

    list->size++;

    return true;
}

Node* get_node(List *list, const size_t index) {
    if(!list) {
        print_error(NULL_LIST);
        return NULL;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return NULL;
    }

    if(index >= list->size) {
        print_error(INDEX_RANGE);
        return NULL;
    }

    Node *begin = list->first;

    for(size_t i = 0; i < index; i++) begin = begin->next;

    return begin;
}

boolean insert_list(List *list, void *data, const size_t index) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(index >= list->size || index == ULONG_LONG_MAX) {
        print_error(INDEX_RANGE);
        return false;
    }

    if(!index) return add_first_list(list, data);

    Node *node_new = new_node(data);
    Node *previous = get_node(list, index - 1);
    node_new->next = previous->next;
    previous->next = node_new;
    list->size++;

    return true;
}

boolean delete_node_list(List *list, const size_t index, const boolean with_data) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return false;
    }

    if(index >= list->size)  {
        print_error(INDEX_RANGE);
        return false;
    }

    Node *previous = get_node(list, index - 1);
    Node *to_delete = previous->next;
    previous->next = previous->next->next;

    if(with_data)
        if(!to_delete->data) print_error(NULL_DATA);

        else free(to_delete->data);

    free(to_delete);

    list->size--;

    return true;
}

boolean delete_all_nodes_list(List *list, const boolean with_data) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return false;
    }

    Node *begin = list->first;

    if(with_data)
        while(begin) {
            Node *to_delete = begin;
            begin = begin->next;

            if(!to_delete->data) print_error(NULL_DATA);

            else free(to_delete->data);

            free(to_delete);
        }
    else
        while(begin) {
            Node *to_delete = begin;
            begin = begin->next;

            free(to_delete);
        }

    list->last = list->first = NULL;
    list->size = 0;

    return true;
}


boolean delete_first_node_list(List *list, const boolean with_data) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return false;
    }

    Node *to_delete = list->first;
    list->first = list->first->next;

    if(with_data)
        if(!to_delete->data) print_error(NULL_DATA);

        else free(to_delete->data);

    free(to_delete);

    list->size--;

    return true;
}

boolean delete_last_node_list(List *list, const boolean with_data) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return false;
    }

    if(list->first == list->last) return delete_first_node_list(list, with_data);

    Node *previous = get_node_list(list, list->size - 2);
    Node *to_delete = previous->next;

    if(with_data)
        if(!to_delete->data) print_error(NULL_DATA);

        else free(to_delete->data);

    free(to_delete);

    previous->next = NULL;
    list->last = previous;
    list->size--;

    return true;
}



const Node* get_node_list(List *list, const size_t index) {
    if(!list) {
        print_error(NULL_LIST);
        return NULL;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return NULL;
    }

    if(index >= list->size) {
        print_error(INDEX_RANGE);
        return NULL;
    }

    Node *begin = list->first;

    for(size_t i = 0; i < index; i++) begin = begin->next;

    return begin;
}

void* get_data_list(List *list, size_t index) { return get_node_list(list, index)->data; }


// UTILS
boolean is_empty_list(List *list) { return !list->size; }

void reverse_iterator_list(Node *begin, Node *previous) {
    if(!begin) return;

    Node *node = begin;
    begin = begin->next;

    if(begin) reverse_iterator_list(begin, node);

    begin = node;
    begin->next = previous;
}

boolean reverse_list(List *list) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(is_empty_list(list)) {
        print_error(EMPTY_LIST);
        return false;
    }

    Node *first = list->first;

    reverse_iterator_list(list->first, NULL);

    list->first = list->last;
    list->last = first;

    return true;
}


// ABSTRACT FUNCTIONS
/*boolean List_sort(List *list) {
    if(!list) {
        print_error(NULL_LIST);
        return false;
    }

    if(List_is_empty(list)) {
        print_error(EMPTY_LIST);
        return false;
    }

    Node *it_previous = NULL;

    for(Node *it = list->first; it; it = it->next) {
        Node *it_2_previous = NULL;

        for(Node *it_2 = it->next; it_2; it_2 = it_2->next) {
            if(((TYPE*)it->data)->FIELD > ((TYPE*)it_2->data)->FIELD) {
                if(it_2 == list->last) list->last = it;

                Node *right_node = it_2->next;

                if(it_previous) {
                    it_previous->next = it_2;

                    if(it_2_previous) {
                        it_2_previous->next = it;
                        it_2->next = it->next;
                        it->next = right_node;
                        it = it_2;
                        it_2 = it_2_previous->next;
                    }
                    else {
                        it->next = it_2->next;
                        it_2->next = it;
                        it = it_2;
                        it_2 = it_2->next;
                    }
                }
                else {
                    list->first = it_2;

                    if(it_2_previous) {
                        it_2->next = it->next;
                        it_2_previous->next = it;
                        it->next = right_node;
                        it = it_2;
                        it_2 = it_2_previous->next;
                    }
                    else {
                        it_2->next = it;
                        it->next = right_node;
                        it = it_2;
                        it_2 = it->next;
                    }
                }
            }

            it_2_previous = it_2;
        }

        it_previous = it;
    }

    return true;
}*/
