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
    int ph = 0, px = 0;
    term pr;
    while (ph < poly.size() && px < x.poly.size()) {
        if (poly[ph].second > x.poly[px].second) {
            ret.poly.push_back(poly[ph]);
            ph++;
        } else if (poly[ph].second < x.poly[px].second) {
            ret.poly.push_back(x.poly[px]);
            px++;
        } else {
            pr.first = poly[ph].first + x.poly[px].first;
            pr.second = poly[ph].second;
            if (pr.first != 0)
                ret.poly.push_back(pr);
            ph++;
            px++;
        }
    }
    for (int i = ph; i < poly.size(); i++) {
        ret.poly.push_back(poly[i]);
    }
    for (int i = px; i < x.poly.size(); i++) {
        ret.poly.push_back(x.poly[i]);
    }
    return ret;
}

Polynomial Polynomial::operator - (const Polynomial &x) {
    Polynomial ret;
    int ph = 0, px = 0;
    term pr;
    while (ph < poly.size() && px < x.poly.size()) {
        if (poly[ph].second > x.poly[px].second) {
            ret.poly.push_back(poly[ph]);
            ph++;
        } else if (poly[ph].second < x.poly[px].second) {
            pr.first = 0 - x.poly[px].first;
            pr.second = x.poly[px].second;
            ret.poly.push_back(pr);
            px++;
        } else {
            pr.first = poly[ph].first - x.poly[px].first;
            pr.second = poly[ph].second;
            if (pr.first != 0)
                ret.poly.push_back(pr);
            ph++;
            px++;
        }
    }
    for (int i = ph; i < poly.size(); i++) {
        ret.poly.push_back(poly[i]);
    }
    for (int i = px; i < x.poly.size(); i++) {
        pr.first = 0 - x.poly[i].first;
        pr.second = x.poly[px].second;
        ret.poly.push_back(pr);
    }
    return ret;
}

Polynomial Polynomial::operator * (const Polynomial &x) {
    Polynomial ret;
    term pr;
    for (int i = 0; i < poly.size(); i++) {
        Polynomial tmp;
        for (int j = 0; j < x.poly.size(); j++) {
            pr.first = poly[i].first * x.poly[j].first;
            pr.second = poly[i].second + x.poly[j].second;
            tmp.push(pr);
        }
        ret = ret + tmp;
    }
    return ret;
}

bool Polynomial::operator == (const Polynomial &x) {
    bool ret = true;
    if (poly.size() != x.poly.size()) {
        ret = false;
    } else {
        for (int i = 0; i < poly.size(); i++) {
            if ((poly[i].first != x.poly[i].first) ||
                        (poly[i].second) != x.poly[i].second) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int Polynomial::getValue(int x) {
    int ret;
    for (int i = 0; i < poly.size(); i++) {
        ret += (int)pow(double(x), double(poly[i].second));
    }
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
    if (abs(poly[0].first) == 1) {
        if (poly[0].first == -1)
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

Polynomial Polynomial::Derive() {
    Polynomial ret;
    term pr;
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i].second == 0)
            continue;
        pr.first = poly[i].first * poly[i].second;
        pr.second = poly[i].second - 1;
        ret.poly.push_back(pr);
    }
    return ret;
}

term Polynomial::getTerm(int x) {
    return poly[x];
}

int Polynomial::getSize() {
    return poly.size();
}

void Polynomial::setPoly(polynomial newPoly)
{
    for (vector<pair<int, int> >::iterator it = newPoly.begin(); it != newPoly.end(); it ++)
    {
        poly.push_back(*it);
    }
}

