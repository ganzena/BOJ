//
//  main.cpp
//  [2581] 소수
//
//  Created by YOO TAEWOOK on 2018. 2. 18..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;

bool isPrime(int num){
    if(num == 1 || num == 0) // 1은 소수가 아니다.
        return false;
    for(int i = 2 ; i < num ; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int start, end, result = 0;
    int min = -1;
    bool isFirst = false;
    cin>>start>>end;
    for(int i = start ; i <= end ; i++){
        if(isPrime(i)){
            if(!isFirst){
                isFirst = true;
                min = i;
            }
            result += i;
        }
    }
    if(result == 0){
        cout<<min<<endl;
    } else{
        cout<<result<<endl;
        cout<<min<<endl;
    }
    return 0;
}
