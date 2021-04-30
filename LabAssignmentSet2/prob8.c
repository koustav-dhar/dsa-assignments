#include <stdio.h>
#include <stdlib.h>

int main () {

	int n;
	printf("Enter number of elements: \n");
	scanf("%d", &n);
	if (n < 1) {
		printf("Invalid number of elements. Exiting...\n");
		exit(0);
	}
	int arr[n];
	printf("Enter %d elements: \n", n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) {
		printf("The array is sorted. No order because only 1 element is present.\n");
	} else {
		if (arr[0] > arr[1]) {
			int ok = 1;
			for (int i = 0; i < n - 1; ++i) {
				if (arr[i] <= arr[i + 1]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				printf("The array is sorted in descending order.\n");
			} else {
				printf("The array is unsorted.\n");
			}
		} else {
			int ok = 1;
			for (int i = 0; i < n - 1; ++i) {
				if (arr[i] >= arr[i + 1]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				printf("The array is sorted in ascending order.\n");
			} else {
				printf("The array is unsorted.\n");
			}
		}
	}
	
	
	return 0;
}
