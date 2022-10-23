#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes a filename string, reads the file contents, stores all the contents into a single string, then returns a pointer to that string
char *read_into_string(char *filename);

char *create_string(FILE *text_file, int size);

int get_total_characters(FILE *text_file);


int main(int argc, char *argv[]){
    printf("This program reads a .txt file into string\n");
    char filename[1024];
    printf("Please enter a filename(with .txt included): ");
    
    scanf("%s", filename);

    char *string_content = read_into_string(filename);

    if (string_content == NULL){
        printf("Error reading file.\n");
        return 1;
    }

    printf("\nFile Contents: \n%s\n", string_content);

    return 0;
}

int get_total_characters(FILE *text_file){
    fseek(text_file, 0, SEEK_END);
    int text_length = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);
    // fclose(text_file);
    return text_length;
}


char *read_into_string(char *filename){
    // printf("We're inside char *read_into_string(char *filename)");
    FILE *text_file;

    text_file = fopen(filename, "r");

    if (text_file == NULL){
        return NULL;
    }
    int text_length = get_total_characters(text_file);
    // return create_string(text_file, text_length);
    char *out = create_string(text_file, text_length);
    return out;
}

char *create_string(FILE *text_file, int size){
    char *content = malloc(sizeof(char) * (size + 1));
    char character;
    int index = 0;

    while( (character = fgetc(text_file) ) != EOF){
        content[index++] = character;
    }
    content[index] = '\0';
    // fclose(text_file);
    return content;
}










