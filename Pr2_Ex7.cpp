//
//  main.cpp
//  Pr2_Ex7
//
//  Created by Lauren Yoshizuka on 18/01/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void power_fun(int, int, int, int);

int main()
{
    int n, m, result, i=1;
    cout << "Enter two numbers n & m (no comma): ";
    cin >> n >> m;
    result = n;
    power_fun(n,m,i,result);
    return 0;
}

void power_fun(int n, int m, int i, int result)
{
    if (n==1)
        cout << n << " power " << m << " is " << n;
    else
    {
        result = result * n;
        i += 1;
        if (i <= m-1)
            power_fun(n,m,i,result);
        else
        {
            cout << "n^m = " << result << endl;
            cout << i << " recursive calls were used." << endl;
        }
    }
}
