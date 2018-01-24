//
//  main.cpp
//  [2504] 괄호의 값
//
//  Created by YOO TAEWOOK on 2018. 1. 21..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

// 곱셈의 분배 법칙을 잘 이용할것 A(B + C) = AB +AC
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    cin>>input;
    int result = 0; // 결과값
    int mul = 1; // 곱하기
    stack<char> stack;
    for(int i = 0 ; i < input.length() ; i++){
        if(input.at(i) == '('){
            mul *= 2;
            stack.push(input.at(i));
            if(input.at(i + 1) == ')'){ //바로 닫힐 시에 곱한 값을 더한다.
                result += mul;
            }
        } else if(input.at(i) == '['){
            mul *= 3;
            stack.push(input.at(i));
            if(input.at(i + 1) == ']'){
                result += mul;
            }
        }
        else if(input.at(i) == ')' && !stack.empty()){ //push에서 곱해준 만큼 나눠준다.
            mul /= 2;
            stack.pop();
        } else{
            mul /= 3;
            stack.pop();
        }
    }
    
    if(stack.empty())
        cout<<result<<endl;
    else
        cout<<0<<endl;
    
    return 0;
}
