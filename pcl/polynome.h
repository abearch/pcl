//
//  polynome.h
//  pcl
//
//  Created by silly on 8/25/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#ifndef pcl_polynome_h
#define pcl_polynome_h

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> term;
typedef vector<term> polynomial;

class Polynomial{
private:
    polynomial poly;
    
public:
    Polynomial operator + (const Polynomial &x);
    Polynomial operator - (const Polynomial &x);
    Polynomial operator * (const Polynomial &x);
    bool operator == (const Polynomial &x);
    int getValue(int);
    term getTerm(int);
    int getSize();
    void display();
    void push(term &p);
    Polynomial Derive();
};


#endif
