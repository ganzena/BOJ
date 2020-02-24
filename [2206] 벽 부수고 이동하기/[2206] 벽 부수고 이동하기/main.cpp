//
//  main.cpp
//  [2206] 벽 부수고 이동하기
//
//  Created by YOO TAEWOOK on 2018. 4. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Magic{
    pair<int, int> loc;
    int cnt;
};

int map[1000][1000][2];
bool visit[1000][1000][2];
vector<pair<int, int> > dir;
queue<Magic> q;

Magic magic;
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
        Magic now = q.front();
        q.pop();
        visit[now.loc.first][now.loc.second][now.cnt] = true;
        //마법을 쓸 경우
        if(now.cnt == 0){
            pair<int, int> nextLoc;
            for(int i = 0 ; i < 4 ; i++){
                nextLoc.first = now.loc.first + dir.at(i).first;
                nextLoc.second = now.loc.second + dir.at(i).second;
                
                if(nextLoc.first < 0 || nextLoc.second < 0 || nextLoc.first >= N || nextLoc.second >= M || visit[nextLoc.first][nextLoc.second][now.cnt + 1])
                    continue;
                
                visit[nextLoc.first][nextLoc.second][now.cnt + 1] = true;
                map[nextLoc.first][nextLoc.second][now.cnt + 1] = map[now.loc.first][now.loc.second][now.cnt] + 1;
                Magic next = {nextLoc, 1};
                q.push(next);
            }
        }
        //마법 안 쓸 경우
        pair<int, int> nextLoc;
        for(int i = 0 ; i < 4 ; i++){
            nextLoc.first = now.loc.first + dir.at(i).first;
            nextLoc.second = now.loc.second + dir.at(i).second;
            
            if(nextLoc.first < 0 || nextLoc.second < 0 || nextLoc.first >= N || nextLoc.second >= M || visit[nextLoc.first][nextLoc.second][now.cnt] || map[nextLoc.first][nextLoc.second][now.cnt] == -1)
                continue;
            
            visit[nextLoc.first][nextLoc.second][now.cnt] = true;
            map[nextLoc.first][nextLoc.second][now.cnt] = map[now.loc.first][now.loc.second][now.cnt] + 1;
            Magic next = {nextLoc, now.cnt};
            q.push(next);
        }
    }
    //print();
    int ans = 3000;
    if(map[N-1][M-1][0] != 0)
        ans = min(map[N-1][M-1][0], ans);
    if(map[N-1][M-1][1] != 0)
        ans = min(map[N-1][M-1][1], ans);
    if(ans == 3000) // 최소값이 갱신이 안 되었다
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    magic = {make_pair(0, 0), 0};
    q.push(magic);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int num;
            scanf("%1d", &num);
            map[i][j][0] = num;
            if(map[i][j][0] == 1)
                map[i][j][0] = -1;
            map[i][j][1] = map[i][j][0];
        }
    }
    map[0][0][0] = 1; //시작 weight는 1
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
