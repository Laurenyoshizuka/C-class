//
//  main.cpp
//  Ex 2
//
//  Created by Lauren Yoshizuka on 14/01/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
/*
double object_position (double v,double x0,double j,double a)
{
    return x0 + (v * j) + (0.5) * a * pow(j,2);
}

int main()
{
    int n, i =0 ;
    double x0, v, a, j=0.0, t;
    
    cout << "Enter the object's initial position speed and acceleration (no commas): ";
    cin >> x0 >> v >> a;
    cout << "How many times shoud the object's position be displayed: ";
    cin >> n;
    cout <<  "How many times (in seconds) should the position be updated: ";
    cin >> t;
    
    while (i < n)
    {
        cout << "At time: ";
        cout << fixed;
        cout.precision(1);
        cout << setw(4) << j << " the position is ";
        cout.precision(3);
        cout << setw(6) << object_position(v, x0, j, a) << endl;
        i += 1;
        j += t;
    }
    return 0;
}
*/

void body_position (int initial_position, int speed, int acc, int times, float sec)
{
    int i;
    float t, new_position;
    t = 0.0;
    cout << "Acceleration: " << acc << " Initial speed: " << speed << " Initial position: " << initial_position << " Number of updates: " << times << "Time delta (in seconds): " << sec << endl;
    
    while (i<=times)
    {
        new_position = initial_position + speed * t + (.5) * acc * pow(t,2);
        cout << "At time " << t << " the position is " << new_position << endl;
        i+=1;
        t += sec;
    }
}

int main()
{
    int initial_position, speed, acc, times;
    float sec;
    cout << "Enter the initial position, speed, and acceleration (w/o commas): ";
    cin >> initial_position >> speed >> acc ;
    cout << "How many times should the position be displayed: ";
    cin >> times;
    cout << "How many times should the object's position be updated (in seconds): ";
    cin >> sec;
    body_position(initial_position, speed, acc, times, sec);
}
