//
//  main.cpp
//  [4811] 알약
//
//  Created by YOO TAEWOOK on 2018. 3. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX_TABLET 31

using namespace std;

int tabletNum;
vector< vector<long long int> > DP;
void Run(int);
int main(int argc, const char * argv[]) {
    DP.assign(MAX_TABLET, vector<long long int>(MAX_TABLET * 2, 1));
    while(1){
        cin>>tabletNum;
        if(tabletNum == 0){
            break;
        }
        Run(tabletNum);
    }

    return 0;
}

void Run(int whole){
    for(int i = 0 ; i < MAX_TABLET ; i++){
        for(int j = 0 ; j < MAX_TABLET*2 ; j++){
            if(i == 0){
                DP[i][j] = 1;
            }else if(i == 1){
                DP[i][j] = j + 1;
            }else if(j < 1){
                DP[i][j] = DP[i - 1][j + 1];
            }else{
                DP[i][j] = DP[i][j - 1] + DP[i - 1][j + 1];
            }
        }
        if(i == whole){
            cout<<DP[i][0]<<endl;
            return;
        }
    }
}
