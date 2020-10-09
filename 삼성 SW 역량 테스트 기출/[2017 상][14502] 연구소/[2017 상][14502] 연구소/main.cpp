//
//  main.cpp
//  [2017 상][14502] 연구소
//
//  Created by YOO TAEWOOK on 2020/04/27.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

// 0은 빈칸 1은 벽 2는 바이러스

int N, M, maximum = INT_MIN;
vector<vector<int> > initMap;
vector<pair<int, int> > dir;
queue<pair<int, int> > initVirusQ;

void init();
void solve(int, int, int);
void spread();

int main(int argc, const char * argv[]) {
    init();
    solve(0, 0, 0);
    cout<<maximum<<endl;
    return 0;
}

void spread(){
    queue<pair<int, int> > virusQ = initVirusQ;
    vector<vector<int> > map = initMap;
    
    while(!virusQ.empty()){
        pair<int, int> start = virusQ.front();
        virusQ.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            pair<int, int> next = make_pair(start.first + dir.at(i).first, start.second + dir.at(i).second);
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)
                continue;
            if(map[next.first][next.second] == 2 || map[next.first][next.second] == 1)
                continue;
                
            map[next.first][next.second] = 2; // 바이러스 퍼짐
            virusQ.push(next);
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 0) // 안전 영역 체크 
                cnt++;
        }
    }
    maximum = max(maximum, cnt);
}

void solve(int depth, int r, int c){
    if(depth == 3){
        spread();
        return;
    }

    for(int i = r ; i < N ; i++){
        for(int j = c ; j < M ; j++){
            if(initMap[i][j] == 0){ //벽을 세울 수 있음
                initMap[i][j] = 1;
                solve(depth + 1, r, 0);
                initMap[i][j] = 0;
            }
        }
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N>>M;
    initMap.assign(N, vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>initMap[i][j];
            if(initMap[i][j] == 2)
                initVirusQ.push(make_pair(i,j));
        }
    }
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
