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
    int cnt1 = 0; //() 체크
    int cnt2 = 0; //[] 체크
    stack<char> stack;
    for(int i = 0 ; i < input.length() ; i++){
        if(input.at(i) == '('){
            cnt1++;
            mul *= 2;
            stack.push(input.at(i));
            if(input.at(i + 1) == ')'){ //바로 닫힐 시에 곱한 값을 더한다.
                result += mul;
            }
        } else if(input.at(i) == '['){
            cnt2++;
            mul *= 3;
            stack.push(input.at(i));
            if(input.at(i + 1) == ']'){
                result += mul;
            }
        }
        else if(input.at(i) == ')' && !stack.empty()){ //push에서 곱해준 만큼 나눠준다.
            cnt1--;
            mul /= 2;
            stack.pop();
        } else if(input.at(i) == ']' && !stack.empty()){
            cnt2--;
            mul /= 3;
            stack.pop();
        }
    }
    
    if(stack.empty() && cnt1 == 0 && cnt2 == 0)
        cout<<result<<endl;
    else
        cout<<0<<endl;
    
    return 0;
}
