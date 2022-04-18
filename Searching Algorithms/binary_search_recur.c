#include <stdio.h>

int binarySearchRecur (int arr[], int low, int high, int key) {

    if (low > high) {
        return -1 ;
    }
    
    while (low <= high){
        int mid = (low + high) / 2 ;
        
        if (key == arr[mid]) {
            return mid ;
        }else if (key < arr[mid]){
            return binarySearchRecur (arr, low, mid -1, key);
        }else {
            return binarySearchRecur (arr, mid + 1, high, key);
        }
    }

    return -1;
}

int main () {
    int nums [] = {3,5,7,20,30};
    int arr_size = sizeof(nums) / sizeof (nums[0]);
    int key = 0 ;
    int low = 0 ;
    int high = arr_size - 1 ;

    printf ("Enter the number : ");
    scanf ("%d", &key);

    int found_index = binarySearchRecur(nums, low, high, key) ;

    if (found_index != -1) {
        printf ("Found Index at : %d ", found_index);
    }else {
        printf ("Cannot Found ");
    }

    return 0 ;
}