//
//  main.cpp
//  Pr2_Ex6
//
//  Created by Lauren Yoshizuka on 18/01/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void fibo(int *, int *, int *, int *, int);  //5 global arguments

int main()
{
    int number, first_fib = 0, sec_fib = 1, result = 0, i=2;
    int *user_num, *fib1, *fib2, *fib3;
    cout << "enter a number: ";
    cin >> number;
    fibo(&number, &first_fib, &sec_fib, &result, i);
    return 0;
}

void fibo(int *user_num, int *fib1, int *fib2, int *fib3, int i)
{
    *fib3 = (*fib1) + (*fib2);
    *fib1 = *fib2;
    *fib2 = *fib3;
    i += 1;
    
    if (i <= *user_num)
        fibo(user_num, fib1, fib2, fib3, i);
    else
    {
        cout << "The " << *user_num << "-th Fibonacci number is " << *fib3 << endl;
        cout << i-2 << " recursive calls were needed." << endl;
    }
}
