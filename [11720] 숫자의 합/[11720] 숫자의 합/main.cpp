//
//  main.cpp
//  [11720] 숫자의 합
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>


using namespace std;

int main(int argc, const char * argv[]) {
    int total = 0;
    int num;
    cin>>num;
    string input;
    cin>>input;
    for(int i = 0 ; i < num ; i++){
        total += input[i] - '0';
    }
    cout<<total<<endl;
    return 0;
}
