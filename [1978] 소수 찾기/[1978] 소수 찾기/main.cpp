//
//  main.cpp
//  [1978]소수 찾기
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool PrimeNumber(int);

int main()
{
    vector<int>::iterator iter;
    vector<int> vector;
    int counter = 0;
    int number;
    cin>>number;
    
    for(int i = 0 ; i < number ; i++){
        int num;
        cin>>num;
        vector.push_back(num);
    }
    
    for(iter = vector.begin() ; iter != vector.end() ; iter++){
        if(PrimeNumber(*iter)){
            counter++;
        }
    }
    
    cout<<counter<<endl;
}

bool PrimeNumber(int num){
    
    if(num == 1)
        return false;
    for(int i = 2; i < num ; i++){
        if(num % i == 0)
            return false;
    }
    
    return true;
}


