//
//  main.cpp
//  pcl
//
//  Created by silly on 8/25/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#include <iostream>
#include "polynome.h"
#include "UI.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int order, feedback;
    Welcome();
    ShowMenu();
    do {
        
        order = GetOrder();
        feedback = Execute(order);
    } while (feedback);
    /*
    Polynomial a, b, c;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        term p;
        cin >> p.first >> p.second;
        a.push(p);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        term p;
        cin >> p.first >> p.second;
        b.push(p);
    }
    c = a + b;
    c.display();
    c = a - b;
    c.display();
    */
    return 0;
}
