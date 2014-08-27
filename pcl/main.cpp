//
//  main.cpp
//  pcl
//
//  Created by silly on 8/25/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#include <iostream>
#include "polynome.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Polynomial c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        term p;
        cin >> p.first >> p.second;
        c.push(p);
    }
    c.display();
    return 0;
}
