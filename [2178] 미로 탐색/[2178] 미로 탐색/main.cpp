//
//  main.cpp
//  [2178] 미로 탐색
//
//  Created by YOO TAEWOOK on 2018. 3. 21..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

vector<vector<int> > map;
vector<vector<bool> > visit;
vector<pair<int, int> > dir;

queue<pair<int, int> > q;

int N, M;

void init();
void solve();

int main(){
    init();
    solve();
    return 0;
}

void solve(){
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        if(now.first == N - 1  && now.second == M - 1){ //끝에 다다르면
            cout<<map[now.first][now.second]<<endl;
            return;
        }
        visit[now.first][now.second] = true;
        pair<int, int> next;
        for(int i = 0 ; i < 4 ;i++){
            next.first = now.first + dir.at(i).first;
            next.second = now.second + dir.at(i).second;
            
            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M || visit[next.first][next.second] || map[next.first][next.second] < 0)
                continue;
            
            visit[next.first][next.second] = true;
            map[next.first][next.second] = map[now.first][now.second] + 1;
            q.push(next);
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));
    visit.assign(N, vector<bool>(M, false));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int num;
            scanf("%1d", &num); //숫자가 붙어있어서 이렇게 받음
            
            map[i][j] = num;
            //길과 벽 새로 셋팅
            if(map[i][j] == 1)
                map[i][j] = 0;
            else
                map[i][j] = -1;
        }
    }
    map[0][0] = 1; //시작 weight == 1
    q.push(make_pair(0, 0));
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
