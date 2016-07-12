//
//  main.cpp
//  SolveQuadratic
//
//  Created by Brent Perry on 7/12/16.
//  Copyright © 2016 Brent Perry. All rights reserved.
//

#include "../../../std_lib_facilities.h"

void solve() {
    cout << "We're going to solve the quadratic equation: a*x*x + b*x + c = 0.\n";
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

int main()
{
    
    solve();
    
    
}
