//
//  main.cpp
//  [1475] 방 번호
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string input; //문자열로 입력 받음
    cin>>input;
    map<int, int> map;
    int setNum = 0;
    
    
    for(int i = 0 ; i < 10 ; i++){ //map으로 key는 각 일의 자리 숫자를, value(count)는 0을 삽입한다.
        map.insert(pair<int, int>(i, 0));
    }
    
    for(int i = 0 ; i < input.size() ; i++){
        int num = input.at(i) - 48; // 문자열의 각 문자를 정수로 변환하기 위해 각각의 문자에서 48을 뺀다.
        map.at(num)++;
    }
    
    // 6과 9의 카운트 값을 더한다.
    // 짝수일 경우와 홀수일 경우 필요한 숫자가 달라지므로 나눠서 처리한다.
    int sum = map.at(6) + map.at(9);
    if(sum % 2 == 0){
        sum = sum / 2;
        map.at(6) = sum;
        map.at(9) = sum;
    } else{
        sum = sum / 2 + 1;
        map.at(6) = sum;
        map.at(9) = sum;
    }
    
    for(int i = 0 ; i < map.size() - 1 ; i++){ //count 된 값 중 최대값은 필요한 세트 수를 뜻한다.
        setNum = max(setNum, map.at(i));
    }
    
    cout<<setNum<<endl;
}

