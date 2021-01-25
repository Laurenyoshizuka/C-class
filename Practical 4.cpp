#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

// function prototypes
void print_poly(int *, int); // display poly of degree n
int * read_poly(int &); // create poly of degree n
void calc_poly(int *, int, int &); // calculates the polynomial value
int * sum_poly(int *, int *, int, int, int &); // sum of 2 polynomials
int * prod_poly(int *, int *, int, int, int &); // product of 2 polynomials

// call them in main
int main()
{
    int n, m, degree_sum, degree_product, x, y;
    int *coeffs1, *coeffs2, *coeffs3, *coeffs4;
    
    coeffs1 = read_poly(n);
    calc_poly(coeffs1, n, x);
    coeffs2 = read_poly(m);
    calc_poly(coeffs2, m, y);
    coeffs3 = sum_poly(coeffs1, coeffs2, n, m, degree_sum);
    coeffs4 = prod_poly(coeffs1, coeffs2, n, m, degree_product);
    
    delete [] coeffs1;
    delete [] coeffs2;
    delete [] coeffs3;
    delete [] coeffs4;
    return 0;
    
}


// display the polynomial from user input below
void print_poly(int *coeffs, int n)
{
    cout << "here's the polynomial: " << '\n' ;
    cout << coeffs[0];

    if (n>0)
    {
        for (int i=1; i<=n; ++i)
        {
            cout << " + " << coeffs[i] << "x^" << i;
        }
    cout << endl << "polynomial degree: " << n << endl;
    }

}

// user provides poly degree n

int * read_poly(int &n)
{
    cout << "Enter a number for x's position: " << '\n';
    cin >> n;

    int *coeffs = new int[n+1];

    cout << "Enter the coefficients: " << endl;
    for(int i = 0; i<=n; ++i)
    {
        cout << "Coefficients " << i << " is: ";
        cin >> coeffs[i];
    }

    print_poly(coeffs, n);
    return coeffs;
}

// compute polynomial degree n given value of x
void calc_poly(int * coeffs, int n, int &x)
{
    cout << "what is the value of x: ";
    cin >> x;

    int result = 0;

    for (int i=0; i<=n; ++i)
    {
        result += *coeffs * pow(x,i);
        coeffs++;
    }
}

// compute sum of 2 polynomials
int * poly_sum (int * coeffs1, int coeffs2, int n, int m, int & degree_sum)
{
    if (m>=n)
    {
        degree_sum = m;
    }
    else {degree_sum = n;}

    int *coeffs = new int[degree_sum + 1];

    for (int i=0; i<= degree_sum; i++)
    {
        if (i<=n) {coeffs[i] += *coeffs1;}
        if (i<=m) {coeffs[i] += *coeffs2;}
        coeffs1 ++;
        coeffs2 ++;
    }

    print_poly(coeffs, degree_sum);
    return coeffs;
}

// calc polynomial product
int * prod_poly(int *coeffs1, int * coeffs2, int n, int m, int &degree_product)
{
    degree_product = m+n;
    cout << "Degree of polynomial product: " << degree_product << endl;

    int *coeffs = new int[degree_product + 1];

    for (int i=0; i<=degree_product; ++i)
    {
        for (int j=0; j<=i; ++j)
        {
            if (j<=n && i-j<=m) {coeffs[i] += coeffs1[j]+coeffs2[i-j];}
        }
    }
    print_poly(coeffs, degree_product);
    return coeffs;
}

