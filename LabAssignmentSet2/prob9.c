#include <stdio.h>
#include <stdlib.h>

// function to check sorted order
// returns 0 if unsorted
// returns 1 if sorted in non-decreasing order
// returns -1 if sorted in non-increasing order
int returnsortedorder (int arr[], int n) 
{
	while ()
	if (arr[0] <= arr[1]) {
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				return 0;
			}
		}
		return 1;
	} else {
		
	}
}

int main () {

	int n, m;
	printf("Enter 2 arrays in sorted order in same sorting order to merge them in same sorted order.\n");
	printf("Enter size of first array: \n");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d elements in sorted order: \n");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("Enter size of second array:\n");
	scanf("%d", &m);
	int b[m];
	printf("Enter %d elements in same sorted array as the first array:\n");
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	int oka = 0, okb = 0;
	

	return 0;
}
