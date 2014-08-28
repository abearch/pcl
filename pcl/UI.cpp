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

void Exit() {
    cout << endl;
    cout << "Thank you for your using. sa yo na la." << endl;
}

int Execute(int order) {
    int ret;
    switch (order) {
        case 1:
            break;
            
        case 2:
            break;
         
        case 3:
            break;
            
        case 4:
            break;
            
        case 5:
            break;
            
        case 6:
            break;
            
        case 7:
            break;
            
        case 8:
            break;
            
        case 9:
            Exit();
            return 0;
            
        case 0:
            ShowMenu();
            break;
        
        default:
            break;
    }
    return ret;
}