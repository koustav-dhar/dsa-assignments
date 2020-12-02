#include <stdio.h>

int isprime[10000];
void sieve()	// generating prime status of numbers using sieve of eratosthenes
{
	int n = 100;
	for(int i = 2; i < n; ++i)
	{
		if(!isprime[i])
		{
			for(int j = 2 * i; j < 10000; j += i)
				isprime[j] = 1;
		}
	}
}	

int main()
{
	int L[20][20];
	for(int i = 0; i < 20; ++i)
	{
		for(int j = 0; j < 20; ++j)
		{
			// generating 20 large random numbers
			if(j == 0){
				L[i][j] = 1 + rand() % 9;
			} else{
				L[i][j] = rand() % 10;
			}
		}
	}
	
	int primes[8];
	sieve();
	int cnt = 0;
	for(int i = 1001; cnt < 8; ++i)	// taking first 8 4-digit prime numbers
	{
		if(!isprime[i])
		{
			primes[cnt++] = i;
		}
	}
	
	for(int i = 0; i < 8; ++i)
	{
		printf("When mod = %d:\n", primes[i]);
		for(int j = 0; j < 20; ++j)
		{
			for(int k = 0; k < 20; ++k){
				printf("%d", L[j][k]);
			}
			int rem = 0, pow = 1;
			for (int k = 19; k >= 0; --k){
				rem = (rem + L[j][k] * pow) % primes[i];
				pow = (pow * 10) % primes[i];
			}
			printf(" %% %d = %d\n", primes[i], rem);	// printing the corresponding remainders
		}
	}
	
	return 0;
}
