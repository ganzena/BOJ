//
//  main.cpp
//  [2292] 벌집
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int input;
    int i;
    cin>>input;
    input--;
    for(i = 1 ; input > 0 ; i++){
        input = input - i * 6;
    }
    
    cout<< i << endl;
}
