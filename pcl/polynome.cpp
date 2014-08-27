//
//  polynome.cpp
//  pcl
//
//  Created by silly on 8/25/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#include "polynome.h"

Polynomial Polynomial::operator + (const Polynomial &x) {
    Polynomial ret;
    return ret;
}

Polynomial Polynomial::operator - (const Polynomial &x) {
    Polynomial ret;
    return ret;
}

Polynomial Polynomial::operator * (const Polynomial &x) {
    Polynomial ret;
    return ret;
}

void printX(int x) {
    if (x > 1) {
        cout << "x^" << x;
    } else if (x == 1) {
        cout << "x";
    }
}

void Polynomial::display() {
    if (poly.size() == 0) {
        cout << 0 << endl;
        return;
    }
    if (poly[0].first == -1) {
        cout << '-';
    } else {
        cout << poly[0].first;
    }
    printX(poly[0].second);
    for (int i = 1; i < poly.size(); i++) {
        if (poly[i].first > 0)
            cout << "+";
        if (poly[i].first != 1) {
            if (poly[i].first == -1) {
                cout << '-';
            } else {
                cout << poly[i].first;
            }
        }
        printX(poly[i].second);
    }
    cout << endl;
}

void Polynomial::push(term &p) {
    poly.push_back(p);
}