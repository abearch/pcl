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

Polynomial pol;

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
    return ret = false;
}


//------------------------------
term getPiar(string s) {
    term ret;
    
    return ret;
}

pair<int, int> getPair(string s)
{
    pair<int, int> ans;
    int n = s.size();
    int i = 0;
    bool flag, fl = true;
    while (i < n)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            int k = 0;
            int j = i;
            if (s[i-1] == '-')
                flag = false;
            else
                flag = true;
            while (j < n)
            {
                if ('0' <= s[j] && s[j] <= '9')
                    k = k*10 + s[j] - '0';
                else break;
                j ++;
            }
            if (fl == true)
            {
                if (flag == true)
                    ans.first = k;
                else ans.first = -k;
                fl = false;
            }
            else
            {
                if (flag == true)
                    ans.second = k;
                else ans.second = -k;
            }
            i = j;
        }
        else i ++;
    }
    return ans;
}

polynomial getPoly(string s)
{
    int n = s.size();
    polynomial ans;
    string st;
    for (int i = 0; i < n; i ++)
    {
        st = "";
        while (s[i] != ')')
        {
            st += s[i];
            i ++;
        }
        st += s[i];
        i ++;
        ans.push_back(getPair(st));
    }
    return ans;
}

bool check(char c)
{
    if ('0' <= c <= '9' || c == '-' || c == '(' || c == ')' || c == ',')
        return true;
    return false;
}

int addPoly(string s)
{
    polynomial ans;
    string tmp;
    char unknown;
    bool fl = true, fl2 = true;
    tmp = "";
    
    for (int i = 0; i < s.size(); i ++)
   {
        if (fl == true && ('a' <= s[i] <= 'z' || 'A' <= s[i] <= 'Z'))
        {
            fl = false;
            unknown = s[i];
        }
        else if (fl == true) return 0;
       
        if (fl == false && fl2 == true && s[i] == '=')
        {
            fl2 = false;
        }
        else if (fl == false && fl2 == true) return 0;
       
        if (check(s[i]) == true && fl == false && fl2 == false) tmp += s[i];
    }
    
    ans = getPoly(tmp);
    pol.setPoly(ans);
    return 1;
}

/*
int addPoly(string input) {
    string tmp, pterm;
    term pr;
    Polynomial pol;
    
    //Check the input elements in char set or not, and get the input without space
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ')
            continue;
        if ((input[i] < 'a' || input[i] > 'z') && input[i] != ',' &&
                (input[i] < 0 || input[i] > '9') && input[i] != '-' &&
                input[i] != '(' && input[i] != ')' && input[i] != '=') {
            cout << tmp << endl;
            return 1;
        }
        tmp += input[i];
    }
    
    //check if the input at least with one term
    if (tmp[0] < 'a' || tmp[0] > 'z' || tmp[1] != '=' || tmp.size() < 7) {
        return 2;
    }
    
    //
    int pos = 2;
    while (pos < tmp.size()) {
        if (tmp[pos] != '(') {
            return 3;
        } else {
            pos++;
            bool isNega;
            int ft = 0, sd = 0;
            if (pos < tmp.size()) {
                isNega = false;
                if (tmp[pos] == '-') {
                    isNega = true;
                    pos++;
                }
                while (tmp[pos] >= '0' && tmp[pos] <= '9' && pos < tmp.size()) {
                    ft = ft * 10 + (tmp[pos] - '0');
                    pos++;
                }
                if (isNega) {
                    ft = ft * -1;
                }
                if (pos < tmp.size()) {
                    if (tmp[pos] != ',') {
                        return 4;
                    } else {
                        pos++;
                    }
                } else {
                    return 5;
                }
                if (tmp[pos] == '-') {
                    return 7;
                }
                while (tmp[pos] >= '0' && tmp[pos] <= '9' && pos < tmp.size()) {
                    sd = sd * 10 + (tmp[pos] - '0');
                    pos++;
                }
                if (pos < tmp.size()) {
                    if (tmp[pos] != ')') {
                        return 6;
                    } else {
                        pos++;
                    }
                } else {
                    return 7;
                }
            } else {
                return 8;
            }
            pr.first = ft;
            pr.second = sd;
            pol.push(pr);
        }
    }
    for (int i = 1; i < pol.getSize(); i++) {
        if (pol.getTerm(i-1).second < pol.getTerm(i).second)
            return 9;
    }
    polyList[tmp[0]] = pol;
    pol.display();
    return 0;
}
*/
 
void getPoly() {
    string input;
    int flag;
    cout << "Please enter a polynomial with the correct format" << endl;
    do {
        cout << ">>> ";
        getline(cin, input);
        flag = addPoly(input);
        if (flag != 0) {
            cout << "Invalid input, please try again." << endl;
            cout << "Exit code " << flag << endl;
        }
    } while (flag != 0);
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
