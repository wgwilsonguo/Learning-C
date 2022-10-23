#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	int *array;
	int length;
	int total_size;
}int_set;


void initialize_int_set(int_set *set, int initial_size){
	printf("We are now initializing the int_set\n");
	set->array = malloc(sizeof(int) * initial_size);
	set->length = 0;
	set->total_size = initial_size;
}

void double_total_size(int_set *set){
	printf("Our set's size is being doubled\n");
	set->array = realloc(set->array, 2 * set->total_size * sizeof(int));
	set->total_size = 2 * set->total_size;
}

int is_in_set(int_set *set, int element){
	int total = set->length;
	for(int index = 0; index < total; index++){
		if (set->array[index] == element){
			printf("We already have the element in the int_set\n");
			return 1; // element is already in the set
		}
	
	}
	printf("We do not already have the element\n");
	return 0; // element is not already in the set
}

int add_to_set(int_set *set, int element){
	if(is_in_set(set, element)){
		// printf("First if-statment for the element %i\n", element);
		return 0; // returns 0 when element is already in the set
	}
	if( set->length == set->total_size){
		double_total_size(set);
	}
	// printf("We are adding %d to the array\n", element);
	set->array[set->length] = element;
	set->length++;
	return 1;
}

void int_set_intersect(int_set *out, int_set *set1, int_set *set2){ //[Potentially DONE]
/* Parameters: 	int_set *out : Declared but uninitialized int_set
				int_set *set1, int_set *set2: Two initialized sets

*/
	// int len = set1->length < set2->length ? set1->length : set2->length;
	int_set *smaller_set = set1->length < set2->length ? set1 : set2;
	int_set *larger_set = set1->length >= set2->length ? set1 : set2;

	initialize_int_set(out, smaller_set->length);
	for (int index = 0; index < smaller_set->length; index++){
		if(is_in_set(larger_set, smaller_set->array[index])){
			add_to_set(out, smaller_set->array[index]);
		}
	}
}


void int_set_union(int_set *out, int_set *set1, int_set *set2){
	/* Parameters: 	int_set *out : Declared but uninitialized int_set
				int_set *set1, int_set *set2: Two initialized sets */
	int_set *smaller_set = set1->length < set2->length ? set1 : set2;
	int_set *larger_set = set1->length >= set2->length ? set1 : set2;

	initialize_int_set(out, larger_set->length);
	// [POTENTIALLY DONE]
	for (int index = 0; index < larger_set->length; index++){
		add_to_set(out, larger_set->array[index]);
		if(index < smaller_set->length){
			add_to_set(out, smaller_set->array[index]);
		}
	}
}


void print_int_set(int_set *set){
	for(int index = 0; index < set->length; index++){
		printf("%d\n", set->array[index]);


	}
}

int main(int argc, char *argv[]){
	printf("This is an exercise in creating an integer (python) set in C.\n");

	int_set my_set1;
	int_set my_set2;
	initialize_int_set(&my_set1, 4);
	add_to_set(&my_set1, 0);
	// printf("This is the %ith element %i\n", 0, my_set1.array[0]);
	add_to_set(&my_set1, 1);
	add_to_set(&my_set1, 2);
	add_to_set(&my_set1, 3);	

	add_to_set(&my_set1, 4);
	add_to_set(&my_set1, 5); 
	add_to_set(&my_set1, 0); 
	printf("Printing the first set\n");
	print_int_set(&my_set1);		

	initialize_int_set(&my_set2, 4);
	// add_to_set(&my_set2, 3);
	// add_to_set(&my_set2, 4);
	add_to_set(&my_set2, -2); 
	add_to_set(&my_set2, -1); 
	printf("Printing the second set\n");
	print_int_set(&my_set2);		

	int_set intersect_set;
	int_set union_set;

	int_set_intersect(&intersect_set, &my_set1, &my_set2);
	printf("This is the intersect set\n");
	print_int_set(&intersect_set);		

	int_set_union(&union_set, &my_set1, &my_set2);
	printf("This is the union set");
	print_int_set(&union_set);



	return 0;
}




