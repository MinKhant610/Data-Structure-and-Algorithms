#include <stdio.h>

void bubbleSort (int arr[],int arr_size) {
    int i,j,temp;
    
    for (i = 0; i < arr_size; i++) {
        for (j = 0; j < arr_size-i-1; j++){
            if (arr[j] > arr [j+1]) {
                temp = arr [j];
                arr[j] = arr [j+1];
                arr[j+1] = temp;

            }
        }
    }
    printf ("Sorted Data :");
    for (i = 0; i < arr_size; i++) {
        printf("%d ",arr[i]);
    }
}

int main () {
    int nums[] = {9,8,4,6,5,0,1} ;
    int arr_size = sizeof (nums) / sizeof (nums[0]);
    bubbleSort (nums, arr_size);
    return 0;
}