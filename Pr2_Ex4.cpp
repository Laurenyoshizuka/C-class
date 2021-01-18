//
//  main.cpp
//  Pr2_Ex4
//
//  Created by Lauren Yoshizuka on 18/01/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void floyd(int num)
{
    int i, j , k;
    i = 1;
    j = 1;
    for (k=0; k<=j && j<= num;)
    {
        if (k!=j)
        {
            cout << i << " ";
            i += 1;
            k += 1;
        }
        else
        {
            cout << endl;
            j += 1;
            k = 0;
        }
    }
}

int main()
{
    int num;
    cout << "enter number of lines to show: ";
    cin >> num;
    floyd(num);
    return 0;
}
