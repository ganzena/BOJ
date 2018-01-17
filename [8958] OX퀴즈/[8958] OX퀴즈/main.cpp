//
//  main.cpp
//  [8958] OX퀴즈
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int number;
    cin>>number;
    string input;
    bool flag = false;
    int total = 0;
    int score = 1;
    while(number > 0) {
        cin>>input;
        for(int i = 0 ; i < input.length() ; i++){
            if(flag){ //이전 값이 'O'
                if(input.at(i) == 'X') {
                    flag = false;
                    score = 1;
                }else {
                    total += score++;
                }
            }else{ //이전 값이 'X'
                if(input.at(i) == 'O') {
                    total += score++;
                    flag = true;
                }else {
                    score = 1;
                }
            }
        }
        cout<<total<<endl;
        score = 1;
        flag = false;
        total = 0;
        number--;
    }
}

