#include <stdio.h>

int linearSearch(int arr[],int arr_size, int key) {

    for (int i = 0; i < arr_size; i++) {
        if (key == arr [i]) {
            return i ;
        }
    }

    return -1;
}

int main () {
    int nums [] = {3,5,7,20,30};
    int arr_size = sizeof(nums) / sizeof (nums[0]);
    int key = 0 ;

    printf ("Enter the number : ");
    scanf ("%d", &key);

    int found_index = linearSearch(nums, arr_size, key) ;

    if (found_index != -1) {
        printf ("Found Index at : %d ", found_index);
    }else {
        printf ("Cannot Found ");
    }

    return 0 ;
}