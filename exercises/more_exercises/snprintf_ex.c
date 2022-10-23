#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


int myprint(FILE *stream, int num_chars, const char *format, ...){
    // int fprintf(FILE *stream, const char *format, ...)
    // fputs(const char *str, FILE *stream)
    char buff[num_chars];
    va_list args;
    va_start (args, format);

    vsnprintf(buff, num_chars, format, args);
    fputs(buff, stream);
    return 0;
} 


int main(int argc, char *argv[]){
    // char buff[30];
    char string[] = "abcdefghijklmnopqrstuvwxyz";

    printf("%d\n", (int)strlen("abcdefghijklmnopqrstuvwxyz"));
    // myprint(stdout, 26, "%s\n", string);
    // int out = snprintf(buff, 30, "%s", string);
    // fprintf(stdout, "%d\n", out);
    // puts(buff);

    return 0;
}