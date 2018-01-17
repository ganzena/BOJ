//
//  main.cpp
//  [2775] 부녀회장이 될테야
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int test;
    cin>>test;
    
    for(int i = 0 ; i < test ; i++){
        int floor;
        int room;
        
        cin>>floor;
        cin>>room;
        
        vector<int> vector;
        
        for(int i = 0 ; i < 14 ; i++){
            vector.push_back(i + 1); // vector 초기화.
        }
        
        for(int j = 0 ; j < floor ; j++){
            for(int k = 1 ; k < room ; k++){
                vector[k] += vector[k - 1]; //전의 값과 현재의 값을 더한다.
            }
        }
        
        cout<<vector.at(room - 1)<<endl; // 0부터 시작이므로 -1 해줌.
    }
}

