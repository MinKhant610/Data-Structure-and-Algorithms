#include <stdio.h>

int binarySearch (int arr[], int arr_size, int key) {

    int low = 0 ;
    int high = arr_size - 1 ;

    while (low <= high){
        int mid = (low + high) / 2 ;
        if (key == arr[mid]) {
            return mid ;
        }else if (key < arr[mid]){
            high = mid - 1 ;
        }else {
            low = mid + 1 ;
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

    int found_index = binarySearch(nums, arr_size, key) ;

    if (found_index != -1) {
        printf ("Found Index at : %d ", found_index);
    }else {
        printf ("Cannot Found ");
    }

    return 0 ;
}
