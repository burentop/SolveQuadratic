//
//  main.cpp
//  SolveQuadratic
//
//  Created by Brent Perry on 7/12/16.
//  Copyright © 2016 Brent Perry. All rights reserved.
//

#include "../../../std_lib_facilities.h"

double a, b, c;

void solve() {
    
    cout << "Please enter the values for a, b & c - separated by spaces.\n";
    
    double a, b, c;
    while (cin >> a >> b >> c) {
        if (a == 0) {
            if (b == 0) {
                cout << "There is no root.\n";
            } else {
                cout << "x == " << -c / b << '\n';
            }
        } else if (b == 0) {
            double ca = -c / a;
            if (ca == 0) {
                cout << "x == 0\n";
            } else if (ca < 0) {
                cout << "There is no root.\n";
            } else {
                cout << "There are 2 roots: " << sqrt(ca) << " and " << -sqrt(ca) << '\n';
            }
        } else {
            double sq = b * b - 4 * a * c;
            if (sq == 0) {
                cout << "The root is " << -b / (2 * a) << '\n';
            } else if (sq < 0) {
                cout << "There is no root.\n";
            } else {
                cout << "There are 2 roots: " << setprecision(12) << (-b + sqrt(sq)) / (2 * a) << " and " << (-b - sqrt(sq)) / (2 * a) << '\n';
            }
        }
        
        cout << "Try again; enter a, b & c: \n";
    }
}

const double epsilon = 1.0e-7;

double verify(double x)
{
    double e = a * x * x + b * x + c;
    
    if (e == 0) return x;
    if (0 < e && epsilon < e)
        cout << "poor root; off by " << e << '\n';
    else if (e < -epsilon)
        cout << "poor root; off by " << e << '\n';
    return x;
}

void solve2()
{
    
    cout << "Please enter the values for a, b & c - separated by spaces.\n";
    
    double a, b, c;
    while (cin >> a >> b >> c) {
        if (a == 0) {
            if (b == 0) {
                cout << "There is no root.\n";
            } else {
                cout << "x == " << verify(-c / b) << '\n';
            }
        } else if (b == 0) {
            double ca = -c / a;
            if (ca == 0) {
                cout << "x == 0\n";
            } else if (ca < 0) {
                cout << "There is no root.\n";
            } else {
                cout << "There are 2 roots: " << verify(sqrt(ca)) << " and " << verify(-sqrt(ca)) << '\n';
            }
        } else {
            double sq = b * b - 4 * a * c;
            if (sq == 0) {
                cout << "The root is " << verify(-b / (2 * a)) << '\n';
            } else if (sq < 0) {
                cout << "There is no root.\n";
            } else {
                cout << "There are 2 roots: " << setprecision(12) << verify((-b + sqrt(sq)) / (2 * a)) << " and " << verify((-b - sqrt(sq)) / (2 * a)) << '\n';
            }
        }
        
        cout << "Try again; enter a, b & c: \n";
    }

}

int main()
{
    cout << "We're going to solve the quadratic equation: a*x*x + b*x + c = 0.\n";
    cout << "Would you like the answers to be verified? ('y' / 'n'): ";
    char input;
    cin >> input;
    cout << '\n';
    if (input == 'n') {
        solve();
    } else if (input == 'y') {
        solve2();
    } else {
        cout << "You didn't enter 'y' or 'n'.\n";
    }
    
    
    
}
