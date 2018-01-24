//
//  main.cpp
//  [2750] 수 정렬하기
//
//  Created by YOO TAEWOOK on 2018. 1. 20..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    vector<int> vector;
    
    for(int i = 0 ; i < test ; i++){
        int input;
        cin>>input;
        vector.push_back(input);
    }
    
    sort(vector.begin(), vector.end());
    
    for(int i = 0 ; i < vector.size() ; i++)
        cout<<vector[i]<<endl;
    
    
    return 0;
}
