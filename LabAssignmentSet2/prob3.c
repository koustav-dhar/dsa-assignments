#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "listadt.h"
#include "listadtnosentinel.h"

int menu() {
	printf("Select what to perform.\n");
	printf("Press 1 to insert an element in the list.\n");
	printf("Press 2 to get the length of the list.\n");
	printf("Press 3 to get i\'th element of the list.\n");
	printf("Press 4 to view the list.\n");
	printf("Press 5 to update an element of the list.\n");
	printf("Press 6 to delete i\'th element of the list.\n");
	printf("Press 7 to search for an element in the list.\n");
	printf("Press 8 to exit.\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}

int main() {
	
	printf("Select what kind of list you want to use: \n");
	printf("Press 1 for list with sentinel.\n");
	printf("Press 2 for list without sentinel.\n");
	int choice;
	scanf("%d", &choice);
	if (choice == 1) { // list with sentinel
		List l;
		init_list(&l);
		int i, val;
		while (1) {
			switch (menu()) {
				case 1: // insert an element
					printf("Enter the position of insertion: \n");
					scanf("%d", &i);
					printf("Enter the value to be inserted: \n");
					scanf("%d", &val);
					insert_ith(&l, i, val);
					break;
				case 2: // get length of the list
					printf("Length of the list: %d\n", length_list(l));
					break;
				case 3:	// get i'th index of the list
					printf("Enter the index whose value you want to get: \n");
					scanf("%d", &i);
					val = get_ith(l, i);
					if (val != SENTINEL) {
						printf("Value at index %d is %d\n", i, val);
					}
					break;
				case 4: // view the list
					read_list(l);
					break;
				case 5:	// update list
					printf("Enter the index to be updated: \n");
					scanf("%d", &i);
					printf("Enter the new value: \n");
					scanf("%d", &val);
					update_ith(&l, i, val);
					break;
				case 6:	// delete an element
					printf("Enter index to be deleted: \n");
					scanf("%d", &i);
					delete_ith(&l, i);
					break;
				case 7:	// search for an element
					printf("Enter element to be searched: \n");
					scanf("%d", &val);
					if (search(l, val)) {
						printf("Element found.\n");
					} else {
						printf("Element not found.\n");
					}
					break;
				case 8:	// exit
					exit(0);
					break;
				default:
					printf("Invalid Choice.\n");
					break;
			}
		}	
	} else if (choice == 2) {	// list without sentinel
		ListNS l;
		init_ListNS(&l);
		int i, val;
		while (1) {
			switch (menu()) {
				case 1: // insert an element
					printf("Enter the position of insertion: \n");
					scanf("%d", &i);
					printf("Enter the value to be inserted: \n");
					scanf("%d", &val);
					insert_ithNS(&l, i, val);
					break;
				case 2: // get length of the list
					printf("Length of the list: %d\n", length_ListNS(l));
					break;
				case 3:	// get i'th index of the list
					printf("Enter the index whose value you want to get: \n");
					scanf("%d", &i);
					val = get_ithNS(l, i);
					if (val != INT_MIN) {
						printf("Value at index %d is %d\n", i, val);
					}
					break;
				case 4: // view the list
					read_ListNS(l);
					break;
				case 5:	// update list
					printf("Enter the index to be updated: \n");
					scanf("%d", &i);
					printf("Enter the new value: \n");
					scanf("%d", &val);
					update_ithNS(&l, i, val);
					break;
				case 6:	// delete an element
					printf("Enter index to be deleted: \n");
					scanf("%d", &i);
					delete_ithNS(&l, i);
					break;
				case 7:	// search for an element
					printf("Enter element to be searched: \n");
					scanf("%d", &val);
					if (searchNS(l, val)) {
						printf("Element found.\n");
					} else {
						printf("Element not found.\n");
					}
					break;
				case 8:	// exit
					exit(0);
					break;
				default:
					printf("Invalid Choice.\n");
					break;
			}
		}
	} else {	// invalid case
		printf("Invalid Choice. Exiting...\n");
	}
	
	
	return 0;
}
