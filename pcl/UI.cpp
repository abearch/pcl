//
//  UI.cpp
//  pcl
//
//  Created by silly on 8/27/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#include "UI.h"

void Welcome() {
    cout << "Polynomial Caulculator 0.0.6" << endl;
    cout << "Copyright (c) 2014 silly and chenfei." << endl;
    cout << "All rights reserved." << endl;
    cout << endl;
}

void ShowMenu() {
    cout << "             Menu" << endl;
    cout << endl;
    cout << "    1.Input a Polynomial." << endl;
    cout << "    2.Display Polynomials." << endl;
    cout << "    3.Polynome Addition." << endl;
    cout << "    4.Polynome Subtraction." << endl;
    cout << "    5.Polynome Multiplication." << endl;
    cout << "    6.Check Equation." << endl;
    cout << "    7.Derivation." << endl;
    cout << "    8.Get value." << endl;
    cout << "    9.Exit." << endl;
    cout << "    0.Show Menu." << endl;
    cout << ">>> ";
}

int GetOrder() {
    int ret;
    cin >> ret;
    return ret;
}

int Execute(int order) {
    int ret;
    switch (order) {
        case 0:
            ShowMenu();
            break;
            
        case 9:
            cout << "Byebye ~~~~ " << endl;
            return 0;
            
        default:
            break;
    }
    return ret;
}