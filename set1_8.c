#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool checkprime(int n)	// function to check if n is prime or not
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	char name[50];
	printf("Enter your name in upper case : \n");
	fgets(name, sizeof(name), stdin);	// get name as input in upper case
	
	int firststep[50];
	for(int i = 0; name[i] != '\0'; ++i)
	{
		// printf("%c : %d\n", name[i], name[i]);
		firststep[i] = name[i];	// storing ASCII values of corresponding characters in an array
	}
	
	int ascii[100], i = 0;
	for(i = 0; name[i] != '\0'; ++i)
	{
		// since the ASCII values of upper case alphabets are of 2 digits, breaking the digits in 2 spaces
		// storing the number after juxtaposing as an array, to avoid integer overflow
		ascii[2 * i] = firststep[i] / 10;
		ascii[2 * i + 1] = firststep[i] % 10;
	}
	printf("The ASCII of the above name is : ");
	for(int j = 0; j < 2 * i; ++j)
		printf("%d", ascii[j]);	// printing the number after juxtaposing
	printf("\n");
	
	// dividing the number in two halves
	int A[50], B[50], j = 0;
	for(j = 0; j < i; ++j)
		A[j] = ascii[j];
	for( ; j < 2 * i; ++j)
		B[j - i] = ascii[j];
	// printing the two halves
	printf("The first half is : ");
	for(int j = 0; j < i; ++j)
		printf("%d", A[j]);
	printf("\n");
	printf("The second half is : ");
	for(int j = 0; j < i; ++j)
		printf("%d", B[j]);
	printf("\n");
	
	int len = i, final[50], carry = 0;
	for(j = 0; j < i; ++j)
	{
		// calculating their sum keeping a carry for each index
		final[j] = (A[len - 1 - j] + B[len - 1 - j] + carry) % 10;
		carry = (A[len - 1 - j] + B[len - 1 - j] + carry) / 10;	
	}
	if(carry > 0)
	{
		final[len] = carry;
		++len;
	}
	printf("Sum of the two halves is : ");
	for(j = len - 1; j >= 0; --j)
		printf("%d", final[j]);	// printing the sum of two halves
	printf("\n");
	
	int primes[8], cnt = 0;	
	for(int p = 1001; cnt < 8; ++p)
	{
		if(checkprime(p))	// getting first 8 4-digit primes 
		{
			primes[cnt++] = p;
		}
	}
	printf("Now the remainder when the final number is divided by the following primes are : \n");
	for(i = 0; i < 8; ++i)
	{
		int rem = 0, pow = 1;
		for(j = 0; j < len; ++j)
		{
			rem = (rem + final[j] * pow) % primes[i];	// finding the remainder of the numbers with the primes generated using modular arithmetic
			pow = (pow * 10) % primes[i];
		}
		for(j = len - 1; j >= 0; --j)
			printf("%d", final[j]);
		printf(" %% %d = %d\n", primes[i], rem);	// printing the remainders
	}

	return 0;
}
