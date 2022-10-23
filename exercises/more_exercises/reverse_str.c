#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void rev_str(char *text){
    int total_length = strlen(text);
    int text_len = total_length/2;
    char temp;
    for(int index = 0; index < text_len; index++){
        // printf("This is text[%i] %c\n", index, text[index]);
        // printf("This is text[%i] %c\n", total_length - index - 1, text[total_length - index - 1]);
        temp = text[index];
        text[index] = text[total_length - index - 1];
        text[total_length - index - 1] = temp;
        // printf("\n This is the string after a single iteration swap \n%s\n", text);
        // printf("This is text[%i] %c\n", index, text[index]);
        // printf("This is text[%i] %c\n", text_len - index - 1, text[total_length - index - 1]);
    }
    printf("This is the text inside the rev_str function\n %s\n", text);
}

int main(int argc, char *argv[]){
    char msg[] = "Listening to Supreme Court Case Maynard et al v. Snapchat Inc";
    printf("Inside the main function, this is the msg\n %s\n", msg);

    rev_str(msg);

    printf("This should be reversed \n%s\n", msg);
}



