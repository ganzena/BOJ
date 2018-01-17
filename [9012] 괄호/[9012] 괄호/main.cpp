//
//  main.cpp
//  [9012] 괄호
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

bool VPSCheck(string str){
    stack<char> stack;
    for(int i = 0 ; i < str.length() ; i++){
        if(str.at(i) == '(')
            stack.push(str.at(i)); // '('일 경우 push를 한다.
        else{ // ')'일 경우
            if(!stack.empty()) // '('가 남아있을 경우 pop을 수행
                stack.pop();
            else //'('가 남아있지 않은 경우이므로 false를 return
                return false;
        }
    }
    
    return stack.empty();
}
int main()
{
    int cnt; //문자열의 갯수
    string str; //각 문자열을 받을 변수
    
    cin>>cnt;
    
    for(int i = 0 ; i < cnt ; i++){
        cin>>str;
        if(VPSCheck(str))
            cout<< "YES" <<endl;
        else
            cout<< "NO" <<endl;
    }
}

