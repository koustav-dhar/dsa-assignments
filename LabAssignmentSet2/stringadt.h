#define MAX 100

typedef struct {	// structure for String ADT	
	char* s;		// pointer for dynamic character array to store the string
} String;

// function to return a null string whose
// maximum length is m characters
String null (int m) {
	String a;	// initialising a variable of type string
	a.s = (char*)malloc((m + 1) * sizeof(char));	// dynamically allocating (m + 1) characters
													// 1 character extra for the '\0' delimeter.
	a.s[0] = '\0';	// making the string a null (empty) string
	return a;	// returning the string
}

// function to return number of characters in a string
int length (String a) {
	int len = 0;	// initialising len as 0
	while (a.s[len] != '\0') {	// traversing till '\0' delimeter is not reached
		++len;	// incrementing len
	}
	return len;	// returning len (number of characters)
}

// function to compare two strings, whether equal, lesser
// or greater lexicographically
// returns 0 if equal, -1 if first string is lexicographically lesser
// 1 if first string is lexicographically greater
int compare (String a, String b) {
	int lena = length(a) ,lenb = length(b);	// getting length's of both the strings
	int i = 0; 
	while (i < lena && i < lenb) {	// while within the bounds of both strings
		if (a.s[i] == b.s[i]) {	// continue to next iteration if same characters
			++i;
			continue;
		}
		else if (a.s[i] < b.s[i])	// if character of first string is less than the second one
			return -1;			// the first string must be lexicographically lesser
		else 			// if character of second string is less than the first one
			return 1;	//	the first string must be lexicographically greater
		++i;	// incrementing the index
	}
	// the index has reached the shorter length string's end
	if (i == lena && i == lenb)	// if both of the string has come to their end
		return 0;				// then both must be equal
	else if (i != lena)			// if first string has a larger length
		return 1;				// first string must be lexicographically greater
	else						// if second string has a larger length
		return -1;				// first string must be lexicographically lesser
}

// function to check if given string is a null string or not
// returns true if it's a null string, else false
bool isnull (String a) {
	int lena = length(a);	// getting length of a
	String nulla = null(lena);	// creating a null string of length same as a
	if (compare(a, nulla) == 0){	// if it's equal to a null string
		return true;
	} else {	// if it's not equal to a null string
		return false;
	}
}

// function to concat two strings; if two strings a and b are passed, 
// returns a new string with a and b concatenated
String concat (String a, String b) {
	int lena = length(a) ,lenb = length(b);	// getting length's of both the strings
	String c = null(lena + lenb);	// creating an empty string with length as sum of the two string's lengths
	int i = 0, j = 0;
	while (i < lena) {	// while within the bounds of string a
		c.s[i] = a.s[i];	// copying a into c
		++i;	// incrementing index
	}
	while (j < lenb) {	// while within the bounds of string b
		c.s[i] = b.s[j];	// concating b into c
		++i;	// incrementing
		++j;	// indices
	}
	c.s[i] = '\0';	// setting the '\0' delimeter character
	return c;
}

// function to return the substring of the given string
// the substring starts at index i, and of length j
String substr(String a, int i, int j) {
	int lena = length(a);	// getting length of a
	if (i >= 0 && i < lena && j >= 0 && i + j - 1 < lena) {	// checking the validity of the substring
		String sub = null(j);	// getting a null string to store the substring
		int ind = i;
		while (ind < i + j) {	// traversing the substring
			sub.s[ind - i] = a.s[ind];	// copying the substring
			++ind;	// incrementing index
		}
		sub.s[j] = '\0';
		return sub;
	} else {
		String sub = null(lena);
		return sub;	// returns a null string
	}
}

// function to input a string
String input() {
	char str[MAX];
	printf("Enter the string: \n");
	scanf(" %[^\n]s", str);	// input a string
	int lenstr = 0;
	while (str[lenstr] != '\0') {	// finding it's length
		++lenstr;
	}
	String a = null(lenstr);
	for (int i = 0; i <= lenstr; ++i) {
		a.s[i] = str[i];
	}
	return a;
}

// function to output a string
void output(String a) {
	printf("%s\n", a.s);	// print the string
}

// free dynamically allocated memory of the string
void clear(String * a) {
	free(a->s);
}
