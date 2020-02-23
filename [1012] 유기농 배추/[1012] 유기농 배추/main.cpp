//
//  main.cpp
//  [1012] 유기농 배추
//
//  Created by YOO TAEWOOK on 10/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > map;
vector<vector<bool> > visit;
vector<pair<int, int> > dir;
queue<pair<int, int> > q;

void init();
void solve(pair<int, int>);

int tc, N, M, B;
int worm;

int main(int argc, const char * argv[]) {
    freopen("input.txt","r",stdin);
    cin>>tc;
    while(tc-- > 0){
        init();
        while(!q.empty()){ //붙어있는 배추 무리를 센다
            pair<int, int> now = q.front();
            q.pop();
            if(visit[now.first][now.second]) //이미 방문되었던 배추이므로 제외한다
                continue;
            solve(now);
            worm++; //한 무리가 찾아졌으므로 벌레의 수를 증가시킨다.
        }
        cout<<worm<<endl;
    }
}

void init(){
    cin>>M>>N>>B;
    map.assign(N, vector<int>(M, 0));
    visit.assign(N, vector<bool>(M, false));
    
    for(int i = 0 ; i < B ; i++){
        int x,y;
        cin>>y>>x;
        map[x][y] = 1;
        q.push(make_pair(x, y));
    }
    worm = 0;
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}

void solve(pair<int, int> start){
    queue<pair<int, int> > tQ;
    tQ.push(start);
    while(!tQ.empty()){
        pair<int, int> now = tQ.front();
        tQ.pop();
        pair<int, int> next;
        for(int i = 0 ; i < 4 ; i++){
            next.first = now.first + dir.at(i).first;
            next.second = now.second + dir.at(i).second;
            
            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M || visit[next.first][next.second] || map[next.first][next.second] == 0)
                continue;
            
            visit[next.first][next.second] = true;
            tQ.push(next);
        }
    }
}
