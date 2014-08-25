//
//  main.cpp
//  pcl
//
//  Created by silly on 8/25/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> term;
typedef vector<term> polynomial;

class Polynomial{
private:
    polynomial poly;
    
public:
    polynomial operator + (const polynomial x) {
        polynomial ret;
        return ret;
    }
    
    polynomial operator - (const polynomial x) {
        polynomial ret;
        return ret;
    }
    
    polynomial operator * (const polynomial x) {
        polynomial ret;
        return ret;
    }
    
    void display() {
        
    }
};

const int MN = 10010;

int main(int argc, const char * argv[]) {
    return 0;
}
