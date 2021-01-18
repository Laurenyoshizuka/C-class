//
//  main.cpp
//  Pr2_Ex3
//
//  Created by Lauren Yoshizuka on 16/01/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void swap (int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x, y;
    
    cout << "enter two numbers to swap (no comma): ";
    cin >> x >> y;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
    swap(x, y);
    
    cout << "----PERFORM THE SWAP----" << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
    return 0;
}
