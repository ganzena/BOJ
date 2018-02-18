//
//  main.cpp
//  [2908] 상수
//
//  Created by YOO TAEWOOK on 2018. 2. 16..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {// 734 893 437
    string num1, num2;
    cin>>num1>>num2;
    
    int a, b;
    char temp;
    temp = num1.at(num1.size() - 1);
    num1.at(num1.size() - 1) = num1.at(0);
    num1.at(0) = temp;
    temp = num2.at(num2.size() - 1);
    num2.at(num2.size() - 1) = num2.at(0);
    num2.at(0) = temp;
    
    a = stoi(num1);
    b = stoi(num2);

    if(a > b)
        cout<<a<<endl;
    else
        cout<<b<<endl;
    return 0;
}
