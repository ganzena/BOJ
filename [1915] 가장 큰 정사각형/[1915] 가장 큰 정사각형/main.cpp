//
//  main.cpp
//  [1915] 가장 큰 정사각형
//
//  Created by YOO TAEWOOK on 2018. 5. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > map;
vector< vector<int> > DP;

int row, col;
void Init();
void Run();
int maxLen;

int main(int argc, const char * argv[]) {
    Init();
    Run();
    return 0;
}

void Init(){
    cin>>row>>col;
    map.assign(row, vector<int>(col));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            scanf("%1d", &map[i][j]);
            if(map[i][j] == 1)
                maxLen = 1;
        }
    }
}

void Run(){
    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(map[i][j] != 0){
                map[i][j] += min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]);
                maxLen = max(map[i][j], maxLen);
            }
        }
    }
    cout<<maxLen * maxLen<<endl;
}
