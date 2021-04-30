const double epsilon = 1e-6;
/*
typedef struct {	// structure for Polynomial ADT
	int degree;		// stores the leading exponent of the polynomial
	float* coef;	// coefficients array, to be dynamically allocated
} polynomial;

polynomial init(int deg)	// function to initialise a zero polynomial with desired degree
{
	polynomial p;
	p.degree = deg;	// setting the degree of the polynomial
	p.coef = (float*)malloc((deg + 1) * sizeof(float));	// dynamically allocating the coefficients array
	for (int i = 0; i < p.degree; ++i){
		p.coef[i] = 0.0;	// initialising with 0 
	}
	return p;	// returning the initialised zero polynomial with desired degree
}

bool is_zero(polynomial poly)	// function to check if the passed polynomial is a zero degree zero polynomial
{
	if (poly.degree == 0){	// degree must be zero
		if (abs(poly.coef[0]) <= epsilon){	// checking if the constant term is zero
			return true;
		} else{
			return false;
		}
	} else{
		return false;
	}
}

int get_degree(polynomial p)	// gets the leading exponent of the passed polynomial
{
	return p.degree;
}

float get_coef(polynomial poly, int exp)	// returns the coefficient of the passed polynomial of the specific exponent
{
	if (exp >= MAX_DEGREE)	// if the passed exponent is greater than the degree of the polynomial
		return 0.0;
	else{
		return poly.coef[exp];
	}
}

polynomial add(polynomial a, polynomial b)	// function to add two polynomials
{
	polynomial c = init(max(a.degree, b.degree));	// degree of the sum is max of the two degrees
	for (int i = 0; i <= c.degree; ++i){
		float ai, bi;
		if (i > a.degree){	// if the current exponent is greater than degree of a
			ai = 0.0;
		} else{
			ai = a.coef[i];
		}
		if (i > b.degree){	// if the current exponent is greater than degree of b
			bi = 0.0;
		} else{
			bi = b.coef[i];
		}
		c.coef[i] = ai + bi;	// setting c's coefficient values
	}
	return c;
}

polynomial mult(polynomial a, polynomial b)	// function to multiply two polynomials
{
	polynomial c = init(a.degree + b.degree);	// degree of the product is sum of the two degrees
	for (int i = 0; i <= a.degree; ++i) {
		for (int j = 0; j <= b.degree; ++j) {
			c.coef[i + j] += a.coef[i] * b.coef[j];	// setting c's coefficient values
		}
	}
	return c;
}
*/



#define MAX 100
#define MAX_POLY 10

typedef struct {	// a polynomial term
	float coeff;
	int exp;
} polynomial;

polynomial terms[MAX];
int terms_rem = 0;

typedef struct {	// start and finish indices of a polynomial
	int start;
	int finish;
} poly;

// function to check if a polynomial is zero polynomial
int is_zero (poly p)
{
	return p.finish < p.start;
}

float get_coef(poly A, int e)	// returns the coefficient of the passed polynomial of the specific exponent
{
	for (; A.start <= A.finish; ++A.start) {
		if (terms[A.start].exp == e)
			return terms[A.start].coeff;
	}
	return 0;
}

// function to add a term to a polynomial
void add_term (float c, int e)
{
	if (terms_rem >= MAX) {
		printf ("Too many terms in the polynomial.\n");
		exit (0);
	}
	terms[terms_rem].coeff = c;
	terms[terms_rem++].exp = e;
}

// function to add two polynomials
void add (poly A, poly B, poly* X) {
	float coefficient;
	X -> start = terms_rem;	// marking the start of sum polynomial
	while (A.start <= A.finish && B.start <= B.finish) {	// applying merge algorithm
		if (terms[A.start].exp < terms[B.start].exp) {
			add_term(terms[B.start].coeff, terms[B.start].exp);
			++B.start;
		} else if (terms[A.start].exp == terms[B.start].exp) {
			coefficient = terms[A.start].coeff + terms[B.start].coeff;
			if (coefficient)
				add_term(coefficient, terms[A.start].exp);
			++A.start;
			++B.start;
		} else {
			add_term(terms[A.start].coeff, terms[A.start].exp);
			++A.start;
		}
	}
	for (; A.start <= A.finish; A.start++)
		add_term(terms[A.start].coeff, terms[A.start].exp);
	for (; B.start <= B.finish; B.start++)
		add_term(terms[B.start].coeff, terms[B.start].exp);
	X -> finish = terms_rem - 1;	// marking the end of sum polynomial
}

// function to update a term, if exponent not present, then add
void update (float coefficient, int exponent, poly* X) {
	for (int i = X -> start; i <= X -> finish; i++)
		if (terms[i].exp == exponent) {
			terms[i].coeff += coefficient;
			return;
		}
	add_term (coefficient, exponent);
	X -> finish = terms_rem - 1;
}

// function to multiply two polynomials
void multiply (poly A, poly B, poly* X) {
	X -> start = terms_rem;
	X -> finish = terms_rem - 1;
	for (int i = A.start; i <= A.finish; i++)
		for (int j = B.start; j <= B.finish; j++) {
			float coefficient = terms[i].coeff * terms[j].coeff;
			int exponent = terms[i].exp + terms[j].exp;
			if (coefficient)
				update (coefficient, exponent, X);
		}
}

// function to multiply a polynomial with a constant
void cMult (poly A, float c)
{
	for (int i = A.start; i <= A.finish; ++i) {
		terms[i].coeff *= c;
	}
}

// function to return the degree of the polynomial
int get_degree(poly p)
{
	if (is_zero(p))
		return -1;
	else
		return terms[p.start].exp;
}

// function to input a polynomial
void input (poly* A, int p) {
	if (p >= MAX_POLY) {
		printf ("Too many polynomials.\n");
		exit (0);
	}
	A -> start = terms_rem;
	int n;
	printf ("Enter number of terms: ");
	scanf ("%d", &n);
	printf ("Enter terms <coeff-i, exp-i>, in decreasing order of term exponents:\n");
	for (int i = 0; i < n; i++) {
		int e;
		float c;
		scanf ("%f %d", &c, &e);
		if (c)
			add_term (c, e);
	}
	A -> finish = terms_rem - 1;
}

// function to display the polynomial
void display (poly A) {
	if (is_zero(A)) {
		printf ("Zero Polynomial.\n");
		return;
	}
	printf ("Polynomial: ");
	for (; A.start < A.finish; A.start++)
		if (fabs(terms[A.start].coeff - 1.000) <= epsilon)
			printf ("x^%d + ", terms[A.start].exp);
		else
			printf ("%.3fx^%d + ", terms[A.start].coeff, terms[A.start].exp);
	if (terms[A.finish].exp == 0)
		printf ("%.3f\n", terms[A.finish].coeff);
	else
		printf("%.3fx^%d\n", terms[A.finish].coeff, terms[A.finish].exp);
}
