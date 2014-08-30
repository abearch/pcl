//
//  main.cpp
//  pcl
//
//  Created by silly on 8/25/14.
//  Copyright (c) 2014 silly. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include "polynome.h"
#include "UI.h"

using namespace std;

map<char, Polynomial> polyList;

int getInput() {
    int ret;
    string input;
    cout << ">>> ";
    getline(cin, input);
    if (input == "help") {
        help();
    }
    return ret;
}

int isOrder(string input) {
    int ret, i = 0;
    string tmp = "";
    while (i < input.size() && input[i] == ' ') i++;
    while (i < input.size() && input[i] != ' ') tmp += input[i++];
    while (i < input.size()) {
        if (input[i++] != ' ') {
            return -1;
        }
    }
    if (tmp.size() == 1) {
        if (tmp[0] >= '0' && tmp[0] <= '9') {
            ret = tmp[0] - '0';
        }
    } else if (tmp == "exit") {
        ret = 9;
    } else if (tmp == "help"){
        ret = 10;
    } else {
        ret = -1;
    }
    return ret;
}

int getOrder() {
    int ret;
    string input;
    cout << ">>> ";
    getline(cin, input);
    ret = isOrder(input);
    while (!(ret >= 0 && ret <= 10)) {
        cout << "Inupt invalid, please try again." << endl;
        cout << ">>> ";
        getline(cin, input);
        ret = isOrder(input);
    }
    return ret;
}

bool isPoly(string input) {
    bool ret;
    return ret;
}

Polynomial toPoly(string input) {
    Polynomial ret;
    term pr;
    
    return ret;
}

Polynomial getPoly() {
    Polynomial ret;
    string input, tmp;
    bool flag;
    do {
        cout << "Please enter a polynomial" << endl;
        getline(cin, input);
        flag = isPoly(input);
        if (flag) {
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == ' ')
                    continue;
                tmp += input[i];
            }
            ret = toPoly(tmp);
            polyList[tmp[0]] = ret;
        }
    } while (!flag);
    return ret;
}



void Addition() {
    
}

void displayPoly() {
    
}

void Subtraction() {
    
}

void Multiplication() {
    
}

void checkEqual() {
    
}

void Derivation() {
    
}

void getValue() {
    
}

void Exit() {
    cout << endl;
    cout << "Thank you for your using. sa yo na la." << endl;
}

int Execute(int order) {
    int ret = 1;
    switch (order) {
        case 1:
            getPoly();
            break;
        case 2:
            displayPoly();
            break;
        case 3:
            Addition();
            break;
        case 4:
            Subtraction();
            break;
        case 5:
            Multiplication();
            break;
        case 6:
            checkEqual();
            break;
        case 7:
            Derivation();
            break;
        case 8:
            getValue();
            break;
        case 9:
            return 0;
            break;
        case 10:
            help();
            break;
        case 0:
            break;
        default:
            break;
    }
    return ret;
}

void model1() {
    int order;
    cout << endl;
    do {
        showMenu();
        order = getOrder();
        Execute(order);
    } while (order != 9);
}

void model2() {
    /*/int ret;
    string input;
    do {
        cout << ">>> ";
        getline(cin, input);
        
    } while ();
    //return ret = 1;
     */
}

void selectModel() {
    string input, tmp;
    int feedback = 0;
    do {
        if (feedback == -1) {
            cout << "Input invalid, please type again." << endl;
        } else  {
            cout << endl;
            cout << "There is two model of pcl, please select what you want." << endl;
            cout << "    1.Normal PCL(Menu)." << endl;
            cout << "    2.Quick PCL(no Menu)." << endl;
            cout << "    0.Exit. " << endl << endl;
        }
        cout << ">>> ";
        getline(cin, input);
        tmp = "";
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == ' ')
                continue;
            tmp += input[i];
        }
        if (tmp.size() == 1 && (tmp[0] >= '0' && tmp[0] <= '2')) {
            int selected = tmp[0] - '0';
            switch (selected) {
                case 0:
                    Exit();
                    return;
                    break;
                case 1:
                    model1();
                    feedback = 1;
                    break;
                case 2:
                    model2();
                    feedback = 1;
                    break;
                default:
                    break;
            }
        } else if (tmp == "exit") {
            Exit();
            return;
        } else {
            feedback = -1;
        }
    } while (feedback);
}

int main(int argc, const char * argv[]) {
    Welcome();
    selectModel();
    return 0;
}
