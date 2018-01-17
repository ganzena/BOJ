//
//  main.cpp
//  [4673] 셀프 넘버
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

#define MAX 10000
int Creator(int);

int main()
{
    map<int, bool>::iterator iter;
    map<int, bool> map;
    for(int i = 1 ; i <=MAX ; i++){
        map.insert(pair<int, bool>(i, true));
    }
    
    for(iter = map.begin() ; iter != map.end() ; iter++){
        map.find(Creator(iter->first))->second = false;
    }
    
    for(iter = map.begin(); iter != map.end() ; iter++){
        if(iter->second){
            cout<<iter->first<<endl;
        }
    }
    
    
    return 0;
}

int Creator(int input){
    int temp = input;
    
    int tthousand = temp / 10000;
    int thousand = temp % 10000 / 1000;
    int hundred = temp % 10000 % 1000 / 100;
    int ten = temp % 10000 % 1000 % 100 / 10;
    int one = temp % 10000 % 1000 % 100 % 10;
    
    return input + tthousand + thousand + hundred + ten + one;
}

