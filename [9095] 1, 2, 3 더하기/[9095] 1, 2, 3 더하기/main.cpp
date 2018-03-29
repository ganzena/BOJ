//
//  main.cpp
//  [9095] 1, 2, 3 더하기
//
//  Created by YOO TAEWOOK on 2018. 3. 29..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_SIZE 12

using namespace std;

vector<int> DP(MAX_SIZE, 0);
void run();
int main(int argc, const char * argv[]) {
    int testNum;
    cin>>testNum;
    run();
    while(testNum--){
        int target;
        cin>>target;
        cout<<DP[target]<<endl;
    }
    return 0;
}
void run(){
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for(int i = 4 ; i < MAX_SIZE ; i++){
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }
}
