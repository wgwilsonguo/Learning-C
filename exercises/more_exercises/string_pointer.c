#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
	char original_text[] = "This is the original message.";
	char *text_pointer = original_text; // points to "T" in original_text
	printf("This is what's in text_pointer %s", text_pointer);
	printf("\ntext_pointer[3] %c \n", text_pointer[3]);
	return 0;
}

