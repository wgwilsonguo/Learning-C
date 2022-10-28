#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

int main(){
    Bst *bst1 = malloc(sizeof(Bst));
    bst1->element = (Node *) malloc(sizeof(Node *)); //address of a node
    bst1->element -> element_val = (uint8_t *) malloc(sizeof(uint8_t *));
    (*bst1->element -> element_val) = "string literal";
    return 0;
}