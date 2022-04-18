#include <stdio.h>

void swap (int arr[], int i, int j ) {
	int temp = arr[i];
	arr[i] = arr[j] ;
	arr[j] = temp;
}

void selectionSort(int arr[], int arr_size){
	int i,j;
	
	for (i = 0; i < arr_size - 1; i++ ){
		int min = i;
		
		for (j = i+1; j < arr_size; j++) {
			if (arr[j] < arr [min]) {
				min = j;
			}
		}
		
		swap(arr, min, i);
	}
	
	printf("Sorted Data: ");
	for (i = 0; i < arr_size; i++) {
		printf ("%d ", arr[i]);
	}
}

int main (){
	int nums [] = {9,7,8,5,6,3,2,1};
	int arr_size = sizeof(nums) / sizeof(nums[0]);
	selectionSort(nums, arr_size);
	return 0;
}
