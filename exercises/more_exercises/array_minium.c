#include <stdio.h>
#include <stdlib.h>

double find_minimum(double *double_numbers, double *minimumm, int array_length);

int main(int argc, char *argv[]){
    double nums[] = {15.223302353542309, 15.879303904904166, 4.693670357610394, 16.149701346749556, 1.3520091281262165, 21.891054065408706, 24.46558394925676, 22.83571656371407, 24.106567107085333, 0.11355167179725456};                 
    int array_length = sizeof(nums) / sizeof(nums[0]);
    double curr_min = nums[0];

    if (find_minimum(nums, &curr_min, array_length) == 1){
        printf("This is the minimum %f\n", curr_min);
    }

    return 0;
}

double find_minimum(double double_numbers[], double *minimumm, int array_length){
    // printf("This is double *minimumm %d", minimumm);
    printf("This might be a pointer %p\n", minimumm);
    if (array_length == 0){
        // *error = 0;
        // if 0 is returned, then the funciton has failed because the array is actually empty; otherwise return 1
        return 0;
    }
    *minimumm = double_numbers[0];
    for(int index = 0; index < array_length; index++){
        if(*minimumm > double_numbers[index]){
            *minimumm = double_numbers[index];
        }
    }
    return 1;
}

