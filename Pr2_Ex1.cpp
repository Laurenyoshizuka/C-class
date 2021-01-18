//
//  main.cpp
//  Practiacal 2_YOSHIZUKA
//
//  Created by Lauren Yoshizuka on 14/01/2021.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x,y,r, x_point, y_point;
    double distance;
    cout << "Enter x coordinate for center: " << endl;
    cin >> x;
    cout << "Enter y coordinate for center: " << endl;
    cin >> y;
    cout << "Enter the length of radius: " << endl;
    cin >> r;
    cout << "Enter the x coordinate for a point to check if it's in the circle: ";
    cin >> x_point;
    cout << "Enter the y coordinate for a point to check if it's in the circle: ";
    cin >> y_point;
    distance = sqrt((pow((x_point-x),2)+pow((y_point-y),2)));
    
    if (r>=distance)
    {
        cout << '(' << x_point  << ',' << y_point << ')' << " is in the circle." << endl;
    }
    else cout << '(' << x_point << ',' << y_point << ')' << " is not in the circle." << endl;
}
