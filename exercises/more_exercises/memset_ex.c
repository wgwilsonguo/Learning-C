#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    // char *s1 = "0XFF";
    // // int **nums = malloc(sizeof(int) * 10);
    // // free(nums);
    // int cmp_val = strncmp(s1, "0X", strlen("0X"));
    // printf("This is cmp_val %d\n", cmp_val);
    int num1 = 0x10;
    int *num2 = &num1;

    if (1){
        printf("%d\n", (int)num2);
    }

    return 0;
}
