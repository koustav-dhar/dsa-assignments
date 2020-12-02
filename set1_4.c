#include <stdio.h>

int main()
{
	const int n = 1e5; // setting n as 1,00,000
	int arr[n];
	
	//	Initialising to identity permutation.
	for(int i = 0; i < n; ++i)
	{
		arr[i] = i + 1;
	}
	
	//	Generating a random permutation by swapping between random indices
	for(int i = 0; i < n; ++i)
	{
		int j = rand() % n;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	//	Storing the array in file
	FILE *fout;
	fout = fopen("set1_04.txt", "w");
	for(int i = 0; i < n; ++i)
	{
		fprintf(fout, "%d\n", arr[i]);
	}
	printf("\n");
	fclose(fout);
	return 0;
}
