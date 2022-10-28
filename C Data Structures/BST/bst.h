#include "../Node/node.h"

typedef struct{
    Node *element;
    int (*comparefunction)(void *element_address1, void *element_address2);
    Node left_child;
    Node right_child;
}Bst;

