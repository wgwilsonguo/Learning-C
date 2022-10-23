#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    // argc in the number of paramters passed into the command line after we type "./ex08"
    // argv is an array of string characters that we pass into the command line after we type "./ex08"

    for(int index = 0; index < argc; index++){
        printf("This is the argument at the %ith position: %s\n", index, argv[index]);
    }

}


