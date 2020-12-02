#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long ll;

//function to perform linear search on integer
void linearSearchInt(){
	int n;	
	printf("Enter the number of terms :- ");
	scanf("%d", &n);
	printf("\n");
	
	int *arr = (int*)malloc(n * sizeof(int));
	
	printf("Enter the Array elements :- \n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int ele;
	printf("Enter the element to be searched :- \n");
	scanf("%d", &ele);
	
	int ans = 0;
	
	//linear search step
	for(int i = 0; i < n; i++){
		if(ele == arr[i])
		{
			ans = 1;
			break;
		}
	}
	
	if(ans & 1)
		printf("Element found :) \n");
	else
		printf("Element not found :( \n");
}


//function to perform binary search for integers
void binarySearchInt(){
	int n;	
	printf("Enter the number of terms :- ");
	scanf("%d", &n);
	printf("\n");
	
	int *arr = (int*)malloc(n * sizeof(int));
	
	printf("Enter the Array elements in sorted order :- \n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int ele;
	printf("Enter the element to be searched :- \n");
	scanf("%d", &ele);
	
	int ans = 0;
	int lo = 0, hi = n - 1;
	
	//loop to perform the binary search function
	while(lo <= hi){
		int mid = lo + (hi - lo) / 2;
		
		if(arr[mid] == ele){
			ans = 1;
			break;
		}
		else if(arr[mid] > ele){
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	
	if(ans & 1)
		printf("Element is found \n");
	else {
		int flag = 0;
		for(int i = 0; i < n - 1; i++)
			if(arr[i] > arr[i + 1])
				flag = 1;
		
		if(flag & 1)
			printf("Array entered is not sorted\n");
		else
			printf("Element Not found\n");
	}	
}

//performing linear search on strings
void linearSearchStrings(){
	char words[50][50];
	
	int n;
	printf("Enter the number of words :- ");
	scanf("%d", &n);
	//printf("\n");
	
	printf("Enter the words in ascending order :- ");
	
	for(int i = 0; i < n; i++){
		scanf("%s", words[i]);
	}
	
	char key[50];
	printf("Enter the element to be searched :- ");
	scanf("%s", key);
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(key, words[i]) == 0)
		{
			ans = 1;
			break;
		}
	}	
	
	if(ans & 1)
		printf("Element found :) \n");
	else
		printf("Element not found :( \n");
	
}


//function to perform binary search on strings or char array
void binarySearchStrings(){
	char words[50][50];
	
	int n;
	printf("Enter the number of words :- ");
	scanf("%d", &n);
	//printf("\n");
	
	printf("Enter the words in ascending order :- ");
	
	for(int i = 0; i < n; i++){
		scanf("%s", words[i]);
	}
	
	char key[50];
	printf("Enter the element to be searched :- ");
	scanf("%s", key);
	
	int lo = 0, hi = n - 1, ans = 0;
	while(lo <= hi){
		int mid = lo + (hi - lo)/2;
		int val = strcmp(words[mid], key);
		
		if(val == 0)
		{
			ans = 1;
			break;
		}
		else if( val > 0 )
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	
	if(ans & 1)
		printf("Element found !!!\n");
	else
		printf("Element Not Found :(\n");
}


//linear search on floating point numbers
void linearSearchFloat(){
	int n;	
	printf("Enter the number of terms :- ");
	scanf("%d", &n);
	printf("\n");
	
	float *arr = (float*)malloc(n * sizeof(float));
	
	printf("Enter the Array elements :- \n");
	for(int i = 0; i < n; i++)
		scanf("%f", &arr[i]);
	
	float ele;
	printf("Enter the element to be searched :- \n");
	scanf("%f", &ele);
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		if(arr[i] == ele)
		{
			ans = 1;
			break;
		}
	}
	if(ans & 1)
		printf("Element found !!!\n");
	else
		printf("Element Not Found :(\n");
	
}

//binary search on floating point numbers
void binarySearchFloat(){
	int n;	
	printf("Enter the number of terms :- ");
	scanf("%d", &n);
	printf("\n");
	
	float *arr = (float*)malloc(n * sizeof(float));
	
	printf("Enter the Array elements in sorted order :- \n");
	for(int i = 0; i < n; i++)
		scanf("%f", &arr[i]);
	
	float ele;
	printf("Enter the element to be searched :- \n");
	scanf("%f", &ele);
	
	int ans = 0;
	int lo = 0, hi = n - 1;
	
	//loop to perform the binary search function
	while(lo <= hi){
		int mid = lo + (hi - lo) / 2;
		
		if(arr[mid] == ele){
			ans = 1;
			break;
		}
		else if(arr[mid] > ele){
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	
	if(ans & 1)
		printf("Element is found \n");
	else {
		int flag = 0;
		for(int i = 0; i < n - 1; i++)
			if(arr[i] > arr[i + 1])
				flag = 1;
		
		if(flag & 1)
			printf("Array entered is not sorted\n");
		else
			printf("Element Not found\n");
	}	
}	


int main() {
	
	while(1){
		printf("Choose among the data type for performing binary search 1. integer 2. strings 3. floating point number 4. exit:-");
		
		int ch;
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				{
					int type;
					printf("Enter the type of search (linear 1/ binary 2) :- ");
					scanf("%d", &type);
					
					if(type == 1)
						linearSearchInt();
					else if(type == 2)
						binarySearchInt();
					else
						printf("Invalid Choice \n");
				}
				break;
			case 2:
				{
					int type;
					printf("Enter the type of search (linear 1/ binary 2) :- ");
					scanf("%d", &type);
					
					if(type == 1)
						linearSearchStrings();
					else if(type == 2)
						binarySearchStrings();
					else
						printf("Invalid Choice \n");
				}
				break;
			case 3:
			{
				int type;
				printf("Enter the type of search (linear 1/ binary 2) :- ");
				scanf("%d", &type);
					
				if(type == 1)
					linearSearchFloat();
				else if(type == 2)
					binarySearchFloat();
				else
					printf("Invalid Choice \n");
			}
			break;
			case 4: 
				exit(0);
			default:
				printf("Invalid Choice.\n");
				exit(0);
		}
	}
	
	return 0;
}
