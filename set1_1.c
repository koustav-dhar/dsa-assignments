#include <stdio.h>

int factorial_recurse(int n)	// function to calculate factorial recursively
{
	if(n <= 1)	// breaking condition
		return 1;
	
	return n * factorial_recurse(n - 1);
}

int factorial_iterative(int n)	// function to calculate factorial iteratively
{
	int res = 1;
	for(int i = 1; i <= n; ++i)
	{
		res *= i;	
	}
	return res;
}

int get_overflow()	// finding point where integer overflow occurs
{
	int curr = 1, prev = 1, res = 1;
	while(curr / prev == res)	// checking condition
	{
		prev = curr;
		++res;
		curr = factorial_iterative(res);	// calculating using previously defined factorial function
	}
	return res;
}

long long int factorial_correct(int n)	// finding correct factorial value of the overflow point using long long integer
{
	long long int res = 1;
	for(int i = 1; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

int main()
{
	int n;
	printf("Enter value of n:\n");
	scanf("%d", &n);
	int val_recurse = factorial_recurse(n);
	int val_iter = factorial_iterative(n);
	printf("%d! calculated recursively = %d\n", n, val_recurse);
	printf("%d! calculated iteratively = %d\n", n, val_iter);
	printf("\n");
	int lim = get_overflow();
	printf("Integer Overflow occurs at n = %d\n", lim);
	long long int res = factorial_correct(lim);
	printf("Using long long int, we get %d! = %lld\n", lim, res);
	return 0;	
}
