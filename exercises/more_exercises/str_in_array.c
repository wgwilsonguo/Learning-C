#include <stdio.h>
#include <string.h>

int is_in_array(char *word_arr[], char *word2){
    // Returns 1 if word2 is in word_arr otherwise returns 0
    int index = 0;
    while (word_arr[index]){
        if (strcmp(word_arr[index], word2) == 0){
            printf("The word, %s, is in the array!\n", word_arr[index]);
            return 1;
        }
        index++;
    }
    return 0;
}

int main(void){
    char *string_array[] = {"The", "impression", "I", "had", "was", "that", "we", "were", "leaving", "the", "West", "and", "entering", "the", "East;", "the", "most", "western", "of", "splendid", "bridges", "over", "the", "Danube,", "which", "is", "here", "of", "noble", "width", "and", "depth,", "took", "us", "among", "the", "traditions", "of", "Turkish", "rule."};
    char needle[] = "that";

    int res = is_in_array(string_array, needle);
    printf("This is the result %d\n", res);
}