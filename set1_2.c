#include <stdio.h>

int fib_recurse(int n)	// function to find n'th fibonacci number recursively
{
	if(n == 1)	// first term
		return 0;	
	if(n == 2)	// second term
		return 1;
	return fib_recurse(n - 1) + fib_recurse(n - 2);	// recurrence
}

int fib_iterative(int n)	// function to find n'th fibonacci number iteratively
{
	int a = 0, b = 1, c;
	if(n == 1)	// first term
		return a;
	if(n == 2)	// second term
		return b;
	for(int i = 3; i <= n; ++i)
	{
		c = b + a;	// recurrence
		a = b;	// update
		b = c;	// terms
	}
	return c;
}

int get_overflow()	// find integer overflow point
{
	int res = 3;
	while(res < 101)
	{
		int prev1 = fib_iterative(res - 1), prev2 = fib_iterative(res - 2), curr = fib_iterative(res);	// getting 3 consecutive points
		// printf("prev1 = %d\tprev2 = %d\tcurr = %d\tdiff = %d\n", prev1, prev2, curr, curr - prev1);
		if(curr - prev1 != prev2 || curr < prev1 || curr < prev2)	// checking if the difference still stands and the consecutive numbers are in increasing order or not
			break;
		++res;
	}	
	return res;
}

long long int fib_correct(int n)	// function to find correct value of overflow point using long long integer
{
	long long int a = 0, b = 1, c;
	if(n == 1)
		return a;
	if(n == 2)
		return b;
	for(int i = 3; i <= n; ++i)
	{
		c = b + a;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	int n;
	printf("Enter value of n:\n");
	scanf("%d", &n);
	int val_recurse = fib_recurse(n);
	int val_iter = fib_iterative(n);
	printf("%dth fibonacci number is = %d (calculated recursively)\n", n, val_recurse);
	printf("%dth fibonacci number is = %d (calculated iteratively)\n", n, val_iter);
	int lim = get_overflow();
	printf("Integer Overflow for Fibonacci calculation occurs at n = %d\n", lim);
	printf("Compromised value of %dth fibonacci number = %d\n", lim, fib_iterative(lim));
	long long int res = fib_correct(lim);
	printf("Using long long int, we get correct value of %dth fibonacci number = %lld\n", lim, res);
	return 0;
}
