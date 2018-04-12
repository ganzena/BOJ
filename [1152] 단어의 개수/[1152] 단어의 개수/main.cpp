//
//  main.cpp
//  [1152] 단어의 개수
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    string input;
    getline(cin, input);
    int counter = 1;
    
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == ' '){ // 문자열의 첫 인덱스부터 공백문자가 있는지 확인한다.
            counter++;
        }
    }
    
    if (input[0] == ' ') { // 앞에 공백문자가 있을 경우 카운터를 감소시킨다.
        counter--;
    }
    if (input[input.length() - 1] == ' ') { // 끝에 공백문자가 있을 경우 카운터를 감소시킨다.
        counter--;
    }
    
    cout<<counter<<endl;
    
    
}
