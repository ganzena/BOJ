//
//  main.cpp
//  [7576] 토마토
//
//  Created by YOO TAEWOOK on 2018. 3. 8..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

//정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tomato{
    pair<int, int> loc;
    int day;
};

vector<vector<int> > map;
vector<vector<bool> > visit;
queue<Tomato> q;
vector<pair<int, int> > dir;

int N, M;
int ans = 0;
int unmatureNum = 0;

void init();
void solve();

int main(){
    init();
    solve();
    return 0;
}

void solve(){
    if(q.empty())
        cout<<-1<<endl;
    while(!q.empty()){
        Tomato now = q.front();
        q.pop();
        ans = now.day;
        pair<int, int> nextLoc;
        for(int i = 0 ; i < 4 ; i++){
            nextLoc.first = now.loc.first + dir.at(i).first;
            nextLoc.second = now.loc.second + dir.at(i).second;
            if(nextLoc.first < 0 || nextLoc.second < 0 || nextLoc.first >= N || nextLoc.second >= M || visit[nextLoc.first][nextLoc.second] || map[nextLoc.first][nextLoc.second] != 0)
                continue;
            
            visit[nextLoc.first][nextLoc.second] = true;
            map[nextLoc.first][nextLoc.second] = 1;
            unmatureNum--; //토마토 익힐때마다 감소
            Tomato next = {nextLoc, now.day + 1};
            q.push(next);
        }
    }
    if(unmatureNum == 0) // 모든 토마토가 익은 경우
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>M>>N;
    map.assign(N, vector<int>(M, 0));
    visit.assign(N, vector<bool>(M, false));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
            if(map[i][j] == 0)
                unmatureNum++; //추후 이 값이 0이 아닐 경우 다 익지 못 했으므로 -1 출력
            else if(map[i][j] == 1)
                q.push({make_pair(i, j), 0});
        }
    }
    
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(0,-1));
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(-1,0));
}
