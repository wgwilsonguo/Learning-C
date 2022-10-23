#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_words(char *text){
	int count = 0;
	char separators[] = " \t\n";//" .,;\n\t!?:";
	int text_len = strlen(text);
	for(int index = 0; index < text_len; index++){
		while(index < text_len){
			if(strchr(separators, text[index]) != NULL){
				// This if statement checks if text[index] is a separator
				break;
			}
			index++;
		}
		// We'll reach this point when we find a word
		// printf("Right before count++ this is the character %c\n",text[index]);
		count++;
		// We might have multiple spaces, commas, periods, etc
		while(index < text_len){
			if(strchr(separators, text[index]) == NULL){
				// this if statement checks if text[index] is a letter word, 
				// if so we break.
				break;
			}
			index++;	
		}
	}
	return count;
}


int main(int argc, char *argv[]){
	// printf("This is a program that will count the number of words in the argument passed. \n");
	// printf("This is argv %s\n", argv[2]);
	// int num_words = count_words(*argv);
	// printf("This is num_words %i\n", num_words);
	// return 0;
	void *some_address = malloc(128);
	uint8_t *u8ptr;
	printf("This is someaddress %p\n", some_address);
	printf("This is someaddress %p\n", (uint8_t *)some_address);
	printf("This is the size of (uint8_t *) %lu\n", sizeof((u8ptr)) );

}



