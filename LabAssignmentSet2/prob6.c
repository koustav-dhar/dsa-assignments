#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int minarr (int arr[], int n)
{
	int res = arr[0];
	for (int i = 0; i < n; ++i) {
		if (arr[i] < res) {
			res = arr[i];
		}
	}
	return res;
}

int maxarr (int arr[], int n)
{
	int res = arr[0];
	for (int i = 0; i < n; ++i) {
		if (arr[i] > res) {
			res = arr[i];
		}
	}
	return res;
}

void sort (int arr[], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int medianarr (int arr[], int n)
{
	sort(arr, n);
	int res = arr[(n / 2)];
	return res;
}

int main () {

	int n, k;
	printf("Enter no of elements: \n");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d elements: \n", n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}	
	printf("Enter sliding windows filter size choice (3 / 4 / 5): \n");
	scanf("%d", &k);
	if (k == 3 || k == 5 || k == 7) {
		int minfilter[n], maxfilter[n], medianfilter[n];
		for (int i = 0; i < n; ++i) {
			int filter[k], x = 0;
			for (int j = i - (k / 2); j <= i + (k / 2); ++j) {
				if (j >= 0 && j < n) {
					filter[x] = arr[j];
				} else {
					filter[x] = 0;
				}
				++x;
			}
			minfilter[i] = minarr(filter, k);
			maxfilter[i] = maxarr(filter, k);
			medianfilter[i] = medianarr(filter, k);
		}
		printf("Max filter output: ");
		for(int i = 0; i < n; ++i) {
			printf("%d ", maxfilter[i]);
		}
		printf("\n");
		printf("Min filter output: ");
		for(int i = 0; i < n; ++i) {
			printf("%d ", minfilter[i]);
		}
		printf("\n");
		printf("Median filter output: ");
		for(int i = 0; i < n; ++i) {
			printf("%d ", medianfilter[i]);
		}
		printf("\n");
	} else {
		printf("Invalid filter size entered. Exiting...\n");
		exit(0);
	}

	return 0;
}
