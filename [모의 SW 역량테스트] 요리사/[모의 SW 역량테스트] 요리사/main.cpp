//
//  main.cpp
//  [모의 SW 역량테스트] 요리사
//
//  Created by YOO TAEWOOK on 2018. 4. 13..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;

vector< vector<int> > table;
vector< vector<int> > copyTable;
vector<int> ingredient;
vector<int> food1;
void init();
void cook(int, int);
int tableSize, halfSize, minimum = INT_MAX;
int main(int argc, const char * argv[]) {
    int test, cnt = 1;
    cin>>test;
    
    while(cnt <= test){
        init();
        cook(0, 0);
        printf("#%d %d\n", cnt, minimum);
        cnt++;
    }
    return 0;
}

void cook(int start, int depth){
    if(depth == halfSize){ // 요리를 다 정했다.
        vector<int> food2;
        int foodSum1 = 0, foodSum2 = 0;
        for(int i = 0 ; i < tableSize ; i++){ //재료 벡터
            bool in = false;
            for(int j = 0 ; j < halfSize ; j++){ //음식A 벡터
                if(ingredient[i] == food1[j]){
                    in = true;
                    break;
                }
            }
            if(!in)
                food2.push_back(ingredient[i]);
        
        }
        for(int i = 0 ; i < halfSize ; i++){
            for(int j = 0 ; j < halfSize ; j++){
                foodSum1 += table[food1[i]][food1[j]];
                foodSum2 += table[food2[i]][food2[j]];
            }
        }
        minimum = min(minimum, abs(foodSum2 - foodSum1));
        return;
    }
    
    for(int i = start ; i < tableSize ; i++){
        food1[depth] = ingredient[i];
        cook(i + 1, depth + 1);
    }
}

void init(){
    cin>>tableSize;
    table.assign(tableSize, vector<int>(tableSize));
    ingredient.assign(tableSize, 0); //재료 번호가 담겨있음
    for(int i = 0 ; i < tableSize ; i++){
        ingredient[i] = i;
        for(int j = 0 ; j < tableSize ; j++){
            cin>>table[i][j];
        }
    }
    
    copyTable = table;
    halfSize = tableSize/2;
    food1.assign(halfSize, 0);
    minimum = INT_MAX;
}
