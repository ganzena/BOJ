//
//  main.cpp
//  [1463] 1로 만들기
//
//  Created by YOO TAEWOOK on 2018. 3. 29..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_SIZE 1000001

using namespace std;

vector<int> DP(MAX_SIZE, 0);

void run(int);

int main(int argc, const char * argv[]) {
    int target;
    cin>>target;
    run(target);
    return 0;
}

void run(int target){
    for(int i = 1 ; i < MAX_SIZE ; i++){
        if(i == target){
            cout<<DP[i]<<endl;
            return;
        }else{
            int mul3 = i * 3;
            int mul2 = i * 2;
            int add1 = i + 1;
            if(mul3 < MAX_SIZE){
                if(DP[mul3] == 0)
                    DP[mul3] = DP[i] + 1;
                else
                    DP[mul3] = min(DP[mul3], DP[i] + 1);
            }
            if(mul2 < MAX_SIZE){
                if(DP[mul2] == 0)
                    DP[mul2] = DP[i] + 1;
                else
                    DP[mul2] = min(DP[mul2], DP[i] + 1);
            }
            if(add1 < MAX_SIZE){
                if(DP[add1] == 0)
                    DP[add1] = DP[i] + 1;
                else
                    DP[add1] = min(DP[add1], DP[i] + 1);
            }
        }
    }
}
