//
//  main.cpp
//  [1193] 분수 찾기
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
    // 다음 대각선으로 넘어갈 때마다 대각선의 구성 분수들의 분모와 분자 합이 2, 3, 4, 5 식으로 늘어남
    // 입력 예제인 14의 경우 2/4로 분모 분자의 합이 6이다.
    for(i = 1 ; input > 0 ; i++) //i == 분모 + 분자
        input -= i;
    // i가 짝수인 경우 순서가 진행됨에 따라 분모 증가 분자 감소, 홀수인 경우 분모 감소 분자 증가
    // 이때 input(변경 후)은 시작 지점으로부터 몇 번째 있는지 알려주는 지표가 된다.
    // 14의 경우 현재 input은 -1로 시작점에서 1번 진행되었음을 의미한다.
    // 분모는 i(분모 + 분자)에서 분자의 최소값인 1을 빼준 후, input(음수)을 더한다.
    // 분자는 분자의 최소값인 1에서 input(음수)를 뺀다.
    // i가 홀수인 경우 분모와 분자의 위치가 바뀐다.
    if(i % 2 == 0){
        cout<< 1 - input <<"/"<< i - 1 + input <<endl;;
    }else{ // 홀수인 경우
        cout<< i - 1 + input <<"/"<< 1 - input <<endl;;
    }
}
