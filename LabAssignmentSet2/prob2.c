//including the necesseary header files
#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"



//driver code to utilise the function
int main() {
	
	//menu based program to implement the same
	while (1) {
		printf("\n1. Transpose \n2. Add Matrices\n3. Multiply Matrices\n4. Zero Matrix\n5. exit\n");
		int ch;
		scanf("%d", &ch);
		sparse *s1, *s2, *s3, *s4;
		switch (ch) {
		case 1: 
			printf("Enter the matrix -> \n");
			s1 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			s2 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			getMatrix(s1);
			fastTranspose(s1, s2); //call for the transpose function
			displayMatrix(s2);
			break;
		case 2: 
			printf("Enter the first matrix -> \n");
			s1 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			getMatrix(s1);
			printf("Enter the second Matrix -> \n");
			s2 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			getMatrix(s2);
			s3 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			addMatrix(s1, s2, s3); //call for the addition function
			printf("Addtion of the two matrices generates the following --> \n");

			displayMatrix(s3);
			break;
		case 3:
			printf("Enter the first matrix -> \n");
			s1 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			getMatrix(s1);
			printf("Enter the second Matrix -> \n");
			s2 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			getMatrix(s2);
			s4 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			matrixMult(s1, s2, s4); //call for the multiplication function
			printf("Multiplication of the two matrices generates the following --> \n");

			displayMatrix(s4);
			break;
		case 4: 
			s1 = (sparse*)malloc(MAX_TERMS * sizeof(sparse));
			getMatrix(s1);
			int result = isNonZero(s1);
			if (!result) //cond check
				printf("Entered Matrix is a zero matrix \n");
			else
				printf("Entered Matrix is not a zero matrix \n");
			break;
		case 5: exit(0);
		}
	}
	return 0;
}
