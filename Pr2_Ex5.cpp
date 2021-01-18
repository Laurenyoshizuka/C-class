//
//  main.cpp
//  Pr2_Ex5
//
//  Created by Lauren Yoshizuka on 18/01/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void fibo(int *user_number, int *fib1, int *fib2, int *fib3)
{
    int i;
    for (i = 2; i <= *user_number; i++)
    {
        *fib3 = (*fib1) + (*fib2);
        *fib1 = *fib2;
        *fib2 = *fib3;
    }
}

int main()
{
    int num, fib_num1 = 0, fib_num2 = 1, fib_result = 0;
    int *user_number, *fib1, *fib2, *fib3;
    
    cout << "Enter a nubmer: ";
    cin >> num;
    
    fibo(&num, &fib_num1, &fib_num2, &fib_result);
    
    cout << "The " << num << "n-th Fibonacci nubmer is " << fib_result << endl;
    return 0;
}
