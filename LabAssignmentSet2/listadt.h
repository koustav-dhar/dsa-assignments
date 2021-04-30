#define MAX 100				// maximum size of the lists
#define SENTINEL INT_MIN	// setting the minimum value an integer can store as sentinel

typedef struct {
	int elements[MAX];
} List;

// function to initialize an empty list
void init_list (List* l) {
	for (int i = 0; i < MAX; ++i) {
		l->elements[i] = 0;	
	}
	l->elements[0] = SENTINEL;	// marking the begining of the list as its end
}

// function to return the number of elements in the list
int length_list (List l) {
	int len = 0;	// initialize len as 0
	while (len < MAX && l.elements[len] != SENTINEL) {	// while sentinel isn't reached
		++len;	// incrementing len
	}
	return len;
}

// function to get the i'th value of the list
int get_ith (List l, int i) {
	int len = length_list(l);	// getting the length of the given list
	--i;	// converting into 0-based index
	if (i >= 0 && i < len) {	// checking if valid index
		return l.elements[i];	// returns i'th value
	} else {
		printf ("Out of bounds.\n");
		return SENTINEL;	// returns sentinel
	}
}

void read_list (List l) {
	int len = length_list(l);	// getting the length of the given list
	printf("How you want to view the list? \n");
	printf("Press 1 to view in original order.\n");
	printf("Press 2 to view in reverse order.\n");
	int choice;
	scanf("%d", &choice);	// getting choice of the display order
	switch (choice) {
		case 1:	// forward order printing
			printf("The list in original order is: \n");
			for (int i = 0; i < len; ++i) {		// traversing in normal order
				printf("%d ", l.elements[i]);
			}
			printf("\n");
			break;
		case 2:	// backward order printing
			printf("The list in reverse order is: \n");
			for (int i = len - 1; i >= 0; --i) {	// traversing in reverse order	
				printf("%d ", l.elements[i]);
			}
			printf("\n");
			break;
		default:	// invalid choice
			printf("Invalid Choice.\n");
			break;
	}
}

// function to update value of i'th index
void update_ith (List* l, int i, int newval) {
	int len = length_list(*l);	// getting the length of the given list
	--i;	// converting into 0-based index
	if (i >= 0 && i < len) {	// checking if valid index
		l->elements[i] = newval; // updating the value
	} else {
		printf ("Out of bounds.\n");
	}
}

// function to insert a value at i'th index in the list
void insert_ith (List* l, int i, int val) {
	int len = length_list(*l);	// getting the length of the given list
	if (len == MAX - 1) {	// check if space is there to insert an element
		printf("No space in the list to insert an element.\n");
	} else {
		if (i >= 1 && i <= len + 1) {	// checling validity of index for insertion
			--i;	// converting into 0-based index
			for (int j = len; j > i; --j) {
				l->elements[j] = l->elements[j - 1];	// shifting the elements to the right of i'th index by 1 index
			}
			l->elements[i] = val;	// inserting the value;
			l->elements[len + 1] = SENTINEL;	// updating the end of the list
		} else {
			printf("Out of bounds. Enter a proper index for insertion.\n");
		}
	}
}

// function to remove the value at i'th index in the list
void delete_ith (List* l, int i) {
	int len = length_list(*l);	// getting the length of the given list
	if (i >= 1 && i <= len) {	// checking the validity of the index for deletion
		--i;	// converting to 0-based index
		for (int j = i; j < len; ++j) {
			l->elements[j] = l->elements[j + 1];	// shifting the elements from i'th index to the end left by 1 index
		}
	} else {
		printf("Out of bounds. Enter a proper index for deletion.\n");
	}
}

// function to search for a value in the given list
bool search (List l, int val) {
	int len = length_list(l);	// getting the length of the given list
	for (int i = 0; i < len; ++i) {	// traversing the list
		if (l.elements[i] == val) {	// if the value is found
			return true;
		}
	}
	return false;	// if the value isn't found
}


