// enum node_types = {INT, STRING, FLOAT, DOUBLE};

struct Node;

typedef struct{
    void *element_val;
    struct Node *left_node;
    struct Node *right_node;
}Node;

