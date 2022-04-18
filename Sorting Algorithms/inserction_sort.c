#include <stdio.h>

void inserction_sort(int arr[], int arr_size){
	int i,j,temp;
	for (i = 1; i < arr_size; i++) {
		j = i ;
		while (j > 0 && arr[j-1] > arr[j]) {
			temp = arr [j];
			arr[j] = arr [j-1];
			arr[j-1] = temp;
			j--;
		}
	}
	printf("Sorted Data: ");
	for (i = 0; i < arr_size; i++ ){
		printf ("%d ",arr[i]);
	}
}

int main () {
	int nums[] = {9,7,8,5,6,4,3,2,1};
	int arr_size = sizeof(nums) / sizeof(nums[0]);
	inserction_sort(nums, arr_size);
	return 0;
}	
