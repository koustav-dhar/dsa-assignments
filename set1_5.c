#include <stdio.h>

// This program doesn't generate true random non-repetitive strings. Since, non-repetitive was a must condition, 
// generating true random would've taken longer time, and even more theoretically.
// So I generated them using my pseudo-random method.

char a[10];
int cnt;
FILE* fout;
void generate_random_string()	// function to generate a random string of 10 length with all distinct characters
{
	int pos[26];
	for(int i = 0; i < 26; ++i)
		pos[i] = i;
	for(int i = 0; i < 26; ++i)
	{
		int j = rand() % 26;
		int temp = pos[i];
		pos[i] = pos[j];
		pos[j] = temp;
	}
	
	for(int i = 0; i < 10; ++i)
		a[i] = 65 + pos[i];
}
void permute(int l, int r)  // function to find permutations of number from l to r lexicographically
{  
	if(cnt == 100000)	// if no of strings generated reaches 1,00,000 then finish execution
		return;
    if (l == r)  
    {
    	fprintf(fout, "%s\n", a);	// storing the permutations of random strings in the file
    	++cnt;
    }
    else
    {  
        for (int i = l; i <= r; i++)  
        {  
  			char temp;
            
            temp = a[l];
            a[l] = a[i];
            a[i] = temp;
  
            permute(l+1, r);  
  
            temp = a[l];
            a[l] = a[i];
            a[i] = temp;
        }  
    }  
}  
int main()
{
	generate_random_string();
	fout = fopen("output5.txt", "w");
	permute(0, 9);
	fclose(fout);
	return 0;
}
