//
//  main.cpp
//  [16235] 나무 재테크
//
//  Created by YOO TAEWOOK on 31/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/**
 N * N 크기의 땅을 1 * 1 칸으로 나눠 놓음
 r = i / c = j r과 c는 1부터 시작
 모든 칸에는 5씩 양분이 있다.
 한 칸에 여러개의 나무가 있을 수 있다.
 1칸에 포함해야하 정보
 - 남아있는 양분 량
 - 심어져있는 나무들
 
 
 
 사계절 루틴
 1.봄
 - 나무가 자기 나이 만큼 양분을 먹고, 나이가 1 증가함
 - 자기가 있는 1 * 1 칸에 있는 양분만 먹음
 - 나이가 어린 나무부터 양분을 먹고, 자기 나이만큼 양분을 먹을 수 없는 나무는 즉사
 
 2. 여름
 - 봄에 죽은 나무가 양분으로 변함
 - (각각의 죽은 나무의 나이) / 2 가 나무가 있던 칸에 양분으로 추가
 
 3. 가을
 - 나이가 5배수인 나무만 번식
 - 인접한 8개의 칸에 나이가 1인 나무가 생김 / 칸을 벗어나는 건 없음
 
 4. 겨울
 - 로봇이 땅에 양분을 추가함
 
 */
using namespace std;

struct Field{
    int curNutrient;
    vector<int> trees;
    vector<int> deads;
};

int N, M, K; // N : 땅 크기 / M : 나무 갯수 / K : 기준 햇수

vector<vector<int>> nutrient;
vector<vector<Field>> map;
vector<pair<int, int>> dir = {pair<int, int>(0, 1), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(-1, 0), pair<int, int>(1, 1), pair<int, int>(-1, 1), pair<int, int>(1, -1), pair<int, int>(-1, -1)};
void init();
void spring();
void summer();
void fall();
void winter();
void print();

int main(int argc, const char * argv[]) {
    init();
    while(K != 0){
        spring();
        summer();
        fall();
        winter();
        K--;
    }
    print();
    
    return 0;
}

void spring(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j].trees.empty())
                continue;
            
            sort(map[i][j].trees.begin(), map[i][j].trees.end());
            vector<int>::iterator iter;
            for(iter = map[i][j].trees.begin() ; iter != map[i][j].trees.end() ; iter++){
                if(map[i][j].curNutrient < (*iter)){
                    vector<int>::iterator deadIter;
                    for(deadIter = iter ; deadIter != map[i][j].trees.end() ; deadIter++){
                        map[i][j].deads.push_back(*deadIter);
                    }
                    map[i][j].trees.erase(iter, map[i][j].trees.end());
                    break;
                }else{
                    map[i][j].curNutrient -= *iter;
                    (*iter)++;
                }
            }
        }
    }
}

void summer(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j].deads.empty())
                continue;
            for(int k = 0 ; k < map[i][j].deads.size() ; k++){
                map[i][j].curNutrient += map[i][j].deads[k] / 2;
            }
            map[i][j].deads.clear();
        }
    }
}

void fall(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            pair<int, int> now = make_pair(i, j);
            for(int k = 0 ; k < map[i][j].trees.size() ; k++){
                if(map[i][j].trees[k] % 5 != 0)
                    continue;
                
                for(int d = 0 ; d < dir.size() ; d++){
                    pair<int, int> next = make_pair(now.first + dir.at(d).first, now.second + dir.at(d).second);
                    if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N)
                        continue;
                    map[next.first][next.second].trees.push_back(1);
                }
            }
        }
    }
}

void winter(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            map[i][j].curNutrient += nutrient[i][j];
        }
    }
}

void print(){
    int num = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            num += map[i][j].trees.size();
        }
    }
    cout<<num<<endl;
}

void init(){
    cin>>N>>M>>K;
    nutrient.assign(N, vector<int>(N, 0));
    map.assign(N, vector<Field>(N, Field {5, }));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>nutrient[i][j];
        }
    }
    
    for(int i = 0 ; i < M ; i++){
        int r, c, age;
        cin>>r>>c>>age;
        map[r-1][c-1].trees.push_back(age);
    }
}
