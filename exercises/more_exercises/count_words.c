#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int count_num_words(char *text){
    // Counts the number of whitespace delimited words in input_string
    int count = 0;
	char separators[] = " \t\n";//" .,;\n\t!?:";
	int text_len = strlen(text);

	for(int index = 0; index < text_len; index++){
		while(index < text_len){
			if(strchr(separators, text[index]) == NULL){ // inside if statement if character belongs to a word i.e. it is not a separator
                count++;

				break;
			}
			index++;
		}
		while(index < text_len){
			if(strchr(separators, text[index]) != NULL){
                // if inside if-statement character is a separator
				break;
			}
			index++;	
		}
	}
	return count;
}

int main(int argc, char *argv[]){

    // char some_text[] = "       White space before these words.\0";
    char some_text[] = "        dfagfshsgh          ";
    // printf("%c\n", some_text[37]);
    int count = count_num_words(some_text);
    printf("%d\n", count);
    return 0;
}