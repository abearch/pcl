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

using namespace std;

typedef pair<int, int> term;
typedef vector<term> polynomial;

class Polynomial{
private:
    polynomial poly;
    
public:
    polynomial operator + (const polynomial &x);
    polynomial operator - (const polynomial &x);
    polynomial operator * (const polynomial &x);
    void display();
};


#endif
