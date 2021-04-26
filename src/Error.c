#include <stdio.h>
#include <Error.h>

void print_error(const enum Error error) {
    switch(error) {
        case NULL_LIST: printf("ERROR > NULL_LIST\n");
        break;

        case NULL_NODE: printf("ERROR > NULL_NODE\n");
        break;

        case NULL_DATA: printf("ERROR > NULL_DATA\n");
        break;

        case NULL_MALLOC: printf("ERROR > NULL_MALLOC\n");
        break;

        case INDEX_RANGE: printf("ERROR > INDEX_RANGE\n");
        break;

        case EMPTY_LIST: printf("ERROR > EMPTY_LIST\n");
        break;

        default: break;
    }
}
