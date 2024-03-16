#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int array[], int start, int end){

    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void nextPermut(int input, int permut[]){

    int index = input-1;

    while (index > 0 && permut[index - 1] >= permut[index]){
        index--;
    }

    if (index == 0){
        reverse(permut, 0, input-1);
        return;
    }

    int index2 = input-1;
    while (permut[index2] <= permut[index-1]){
        index2--;
    }

    int temp = permut[index-1];
    permut[index-1] = permut[index2];
    permut[index2] = temp;

    reverse(permut, index, input-1);
}

int main(){

    int input;
    int permut[input];

        printf(": ");
        scanf("%d", &input);
        printf(": \n");

    for (int i = 0; i < input; i++){
        scanf("%d", &permut[i]);
    }

    nextPermut(input, permut);

    for (int i = 0; i < input; i++){
        printf("%d ", permut[i]);
    }

    return 0;
}
