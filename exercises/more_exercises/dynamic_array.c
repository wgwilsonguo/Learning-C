#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int *array;
    int number_of_items;
    int current_total_size;
}int_dynamic_array;


void init_int_dynamic_array(int_dynamic_array *my_dynamic_int_array, int init_size){
    my_dynamic_int_array->array = malloc(init_size * sizeof(int));
    my_dynamic_int_array->number_of_items = 0;
    my_dynamic_int_array->current_total_size = init_size;
}

void insert_into_int_dynamic_array(int_dynamic_array *my_dynamic_int_array, int insert_value){
    if(my_dynamic_int_array->current_total_size == 0){
        // If the current total size is zero, then doubling zero would not help us;
        // We first must initialize the dynamic integer array
       init_int_dynamic_array(my_dynamic_int_array, 1);
    }
    else if(my_dynamic_int_array->number_of_items == my_dynamic_int_array->current_total_size){

        my_dynamic_int_array->current_total_size = 2 * my_dynamic_int_array->current_total_size;
        my_dynamic_int_array->array = realloc(my_dynamic_int_array->array, my_dynamic_int_array->current_total_size * sizeof(int));

    }
    my_dynamic_int_array->array[my_dynamic_int_array->number_of_items] = insert_value;
    my_dynamic_int_array->number_of_items++;
}

void free_int_dyn_array(int_dynamic_array *my_dynamic_int_array){
    free(my_dynamic_int_array->array);
    my_dynamic_int_array->array = NULL;
    my_dynamic_int_array->number_of_items = 0;
    my_dynamic_int_array->current_total_size = 0;
}


int main(){
    int_dynamic_array a;
    int i;
    // int a_succeeded = 0;

    init_int_dynamic_array(&a, 5);  // initially 5 elements
    // a.array[0] = 1234567890;
    printf("%i, %i, %i, %i, %i, ", a.array[0], a.array[1], a.array[2], a.array[3], a.array[4]);
    // for (i = 0; i < 100; i++)
    //     insert_into_int_dynamic_array(&a, i);  // automatically resizes as necessary
    // printf("%d\n", a.array[9]);  // print 10th element
    // printf("%d\n", a.number_of_items);  // print number of elements
    // free_int_dyn_array(&a);
}

