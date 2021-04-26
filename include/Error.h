#ifndef ERROR_H
#define ERROR_H

enum Error { NULL_LIST, EMPTY_LIST, NULL_NODE, NULL_DATA, NULL_MALLOC, INDEX_RANGE };

void print_error(enum Error);

#endif // ERROR_H
