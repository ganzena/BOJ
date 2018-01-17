//
//  main.cpp
//  [11721] 열 개씩 끊어 출력하기
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    cin>>input;
    int counter = 0;
    for(int i = 0 ; i<input.length(); i++){
        if(counter++ < 10)
            cout<<input[i];
        else{
            counter = 0;
            i--;
            cout<<endl;
        }
    }
    return 0;
}
