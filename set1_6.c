#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXCHAR 100
#define INT 2147483647

unsigned int get_length(char *name){	// function to get length of names of students

	int cnt = 0, i;
	int len = strlen(name);	// getting the string size
	for(i = 0; i != len; i++)
	{
   		if(!isspace(name[i]))	// ignoring the spaces in name length
   		{
   			cnt++;
   		}
	}

	return cnt;
}
int main()
{
	int i = 0, total;
	char  str[MAXCHAR];
	FILE *of;
	of = fopen("data_6.txt","w");	// opening the file

	if(of == NULL){	// show error if file couldn't be opened
		fprintf(stderr,"\nError to open the file\n");
		exit(1);
	}

	printf("Enter number of students: \n");
	scanf("%d" ,&total);
	printf("Enter name of students according to roll numbers: \n");
	while (total > 0){	
    	scanf(" %[^\n]s", str);	// getting names as input
    	fprintf(of, "%s\n", str); 	// writing them in the file
    	--total;
    }

    fclose(of);	// closing the file
    
    FILE *fread;
    if((fread = fopen("data_6.txt","r")) == NULL)	// opening the file and checking if it has opened
    {
    	fprintf(stderr,"\nError to open the file\n");
    	exit(1);
    }

    char name[50];
    int min = INT;
    int max = 0;
    char temp[50];
   

    while(fgets(name,sizeof(name),fread)!= NULL)	// getting all the names from the file
    {
    	if(get_length(name) > max)	// finding max name length
		{
			max = get_length(name);
		}
		if(get_length(name) < min)	// finding min name length
		{
		 	min = get_length(name);
		}
		i++;
	}
	int go;
	
	rewind(fread);	// seek the file pointer to beginning of the file again
	
	
	char names[i][50];

	for(go = 0; go < i; go++)
	{
		fgets(names[go], sizeof(names[go]), fread);	// storing the names in a array of strings
	}
	
	// sorting the array of strings using bubble sort
	for(int k = 0; k < i; k++){
		for(int j = k+1; j < i; j++){
			if(strcmp(names[k],names[j]) > 0){
				strcpy(temp,names[k]);
            	strcpy(names[k],names[j]);
            	strcpy(names[j],temp);
			}
		}
	}

	FILE *fout;
	fout = fopen("set1_6_sorted.txt", "w");	// opening the file for stroing the sorted order
	for(int j = 0; j < i; ++j)
	{
		fputs(names[j], fout);	// writing the sorted order
		fprintf(fout, "\n");
	}

	fprintf(stdout,"Highest is :%d, Lowest is :%d\n",max,min);
	
	fclose(fread);
	fclose(fout);
	return 0;
}
