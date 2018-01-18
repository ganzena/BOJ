//
//  main.cpp
//  [2577] 숫자의 개수
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    map<int, int>::iterator iter;
    map<int, int> map;
    int input1, input2, input3;
    int result;
    cin>>input1>>input2>>input3;
    
    result = input1 * input2 * input3;
    
    for(int i = 0 ; i < 10 ; i++)
        map.insert(pair<int, int>(i, 0));

    while(result != 0){
        int target = result % 10;
        result /= 10;
        map[target]++;
    }
    
    for(iter = map.begin() ; iter != map.end() ; iter++)
        cout<<iter->second<<endl;
    
    
    return 0;
}
