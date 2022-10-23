#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_occurrences(char **haystack, char *needle);

void printArray(char **strings_arary, int length){
    for (int index = 0; index < length; index++){
        printf("This is strings_arary[index]: %s\n", strings_arary[index]);

    }

}

int main(int argc, char *argv[]){

    char *haystack1[] = {"This", "should", "be", "illegal;", "you're", "going", "to", "jail", "bitch", "This", "should", "be", "illegal;", "you're", "going", "to", "jail", "bitch", "This", "should", "be", "illegal;", "you're", "going", "to", "jail", "bitch"};
    
    // int haystack_len = sizeof(haystack1);
    // printf("This is haystack1's length %i\n", haystack_len);

    printf("This is %i's length %d\n", 0, (int) sizeof(haystack1[0]));
    printf("This is %i's length %d\n", 1, (int) sizeof(haystack1[1]));
    printf("This is %i's length %d\n", 2, (int) sizeof(haystack1[2]));

    char *needle1 = "illegal";
    int needle_size = sizeof(needle1);
    // int char_size = sizeof(char);

    char new_str[] = "should";
    int s_size = sizeof(new_str);

    printf("This is the size of %s %i\n", new_str, s_size);
    printf("This is size of needle1 %i\n", needle_size);
    // printf("This is char_size %i\n", char_size);

    // int freqs = count_occurrences(haystack1, needle1);
    // printf("This is freqs %i\n", freqs);

    return 0;
}


int count_occurrences(char **haystack, char *needle){
    // int needle_len = strlen(needle);
    int search_space = sizeof(haystack) / sizeof(char);
    // int second_length = sizeof(haystack);

    // printf("This is second_length %d\n", second_length);

    printf("This is search space: %d\n", search_space);

    int out_count = 0;
    int size;
    int hay_size;
    int needle_size;
    int count = 0;

    for(int haystack_index = 0; haystack_index < search_space; haystack_index++){
        hay_size = sizeof(*haystack);
        needle_size = sizeof((*haystack)[haystack_index]);
        count++;

        printf("This is sizeof(*haystack) %d\n", hay_size);
        printf("This is sizeof(*haystack[haystack_index]) %d\n", needle_size);

        // size = sizeof(*haystack) / sizeof((*haystack)[haystack_index]);

        // printf("Value is \"%s\"\nLength at index %i, \tsize: %i\n", haystack[haystack_index], haystack_index, size );
        if (strcmp(needle, (haystack)[haystack_index]) == 0){
            printf("We are in the if statement\n");
            out_count++;
        }
    }
    printf("This is count %i\n", count);
    return out_count;
}
















