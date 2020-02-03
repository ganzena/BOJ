//
//  main.cpp
//  [1526] 가장 큰 금민수
//
//  Created by YOO TAEWOOK on 30/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int input, result = 0;
int sum = 0;

void solve(int);

int main(int argc, const char * argv[]) {
    //freopen("input.txt", "r", stdin);
    cin>>input;
    solve(-1);
    cout<<result<<endl;
    return 0;
}

void solve(int num){
    
    if(num > input) // num 이 input보다 크면 리턴
        return;
    
    result = max(num, result);
    solve(num == -1 ? 4 : num * 10 + 4); //초기 값을 4로 하며 이후 4를 덧붙여가는 방식
    solve(num == -1 ? 7 : num * 10 + 7); //초기 값을 7로 하며 이후 7을 덧붙여가는 방식
}
