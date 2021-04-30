#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stringadt.h"

int menu() {
	printf("Select what to perform.\n");
	printf("Press 1 to get length of a string.\n");
	printf("Press 2 to compare two strings lexicographically.\n");
	printf("Press 3 to concatenate two strings.\n");
	printf("Press 4 to find a substring of a string.\n");
	printf("Press 5 to exit.\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}

int main() {

	String a, b, c;
	int val, i, j;
	while (1) {
		switch (menu()) {
			case 1:	// get length of string
				a = input();
				printf("Length of the entered string is %d.\n", length(a));
				clear(&a);
				break;
			case 2:	// compare two strings
				a = input();
				b = input();
				val = compare(a, b);
				if (val == 0) {
					printf("Both the strings are equal.\n");
				} else if (val == 1) {
					printf("First string is lexicographically greater.\n");
				} else if (val == -1) {
					printf("Second string is lexicographically greater.\n");
				}
				clear(&a);
				clear(&b);
				break;
			case 3:	// concatenate two strings
				a = input();
				b = input();
				c = concat(a, b);
				printf("Concatenated string is: ");
				output(c);
				clear(&a);
				clear(&b);
				clear(&c);
				break;
			case 4:	// find substring
				a = input();
				printf("Length of the entered string is %d.\n", length(a));
				printf("Enter starting index of substring(0-based): \n");
				scanf("%d", &i);
				printf("Enter length of the substring: \n");
				scanf("%d", &j);
				b = substr(a, i, j);
				if (isnull(b)) {	// checking if the substring is valid or not, if not valid substr will return a null string
					printf("Invalid Substring Requested.\n");			
				} else {
					printf("Substring Requested: ");
					output(b);
				}
				clear(&a);
				clear(&b);
				break;
			case 5:	// exit
				exit(0);
				break;
			default: // invalid case
				printf("Invalid Choice.\n");
				exit(0);
		}
	}	
	
	return 0;
}
