//
//  main.cpp
//  [1149] RGB거리
//
//  Created by YOO TAEWOOK on 2018. 3. 29..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii;
vector< vector<int> > DP;
int size, MIN = INT_MAX;

void run();
void print();
int row, col = 3;

int main(int argc, const char * argv[]) {
    cin>>row;
    DP.assign(row, vector<int>(col, 0));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>DP[i][j];
            
        }
    }
    run();
    //print();
    for(int j = 0 ; j < col ; j++)
        MIN = min(MIN, DP[row - 1][j]);
    cout<<MIN<<endl;
    return 0;
}

void run(){
    for(int i = 1 ; i < row ; i++){ //행
        for(int j = 0 ; j < col ; j++){ //열
            int minimum = INT_MAX;
            for(int k = 0 ; k < col ; k++){
                if(j == k)
                    continue;
                minimum = min(minimum, DP[i - 1][k]);
            }
            DP[i][j] = DP[i][j] + minimum;
        }
    }
}


void print(){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            printf("%d ", DP[i][j]);
        }cout<<endl;
    }
}

