//
//  main.cpp
//  [14923] 미로 탈출
//
//  Created by YOO TAEWOOK on 2018. 3. 21..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Human{
    pair<int, int> loc;
    int magic; // 마법 사용 횟수
    int weight; // 사용한 총 비용
};

int map[1000][1000][2];
bool visit[1000][1000][2];
vector<pair<int, int> > dir;
queue<Human> q;

int N, M;
pair<int, int> fin;
Human human = {make_pair(0, 0),0,0};

void init();
void solve();
void print();

int main(){
    init();
    solve();
}

void print(){
    for(int k = 0 ; k < 2 ; k++){
        cout<<k<<" 번 째"<<endl;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ;j++){
                cout<<map[i][j][k]<<"\t";
            }cout<<endl;
        }cout<<endl;
    }
}

void solve(){
    while(!q.empty()){
        Human now = q.front();
        visit[now.loc.first][now.loc.second][now.magic] = true;
        q.pop();
        if(now.magic < 1){ //마법을 써서 이동하는 경우
            pair<int, int> loc;
            for(int i = 0 ; i < 4 ; i++){
                loc.first = dir.at(i).first + now.loc.first;
                loc.second = dir.at(i).second + now.loc.second;
                
                if(loc.first >= N || loc.second >= M || loc.first < 0 || loc.second < 0 || visit[loc.first][loc.second][now.magic + 1])
                    continue;
                
                Human next = {loc, now.magic + 1, now.weight + 1};
                visit[next.loc.first][next.loc.second][next.magic] = true;
                map[next.loc.first][next.loc.second][next.magic] = next.weight;
                q.push(next);
            }
        }
        
        // 마법을 안 쓰고 이동하는 경우
        pair<int, int> loc;
        for(int i = 0 ; i < 4 ; i++){
            loc.first = dir.at(i).first + now.loc.first;
            loc.second = dir.at(i).second + now.loc.second;
            
            if(loc.first >= N || loc.second >= M || loc.first < 0 || loc.second < 0 || visit[loc.first][loc.second][now.magic] || map[loc.first][loc.second][now.magic] == -1)
                continue;
            
            Human next = {loc, now.magic, now.weight + 1};
            visit[next.loc.first][next.loc.second][next.magic] = true;
            map[next.loc.first][next.loc.second][next.magic] = next.weight;
            q.push(next);
        }
    }
    
    //print();
    int ans = 3000;
    for(int k = 0 ; k < 2 ; k++){
        if(map[fin.first][fin.second][k] > 0){
            ans = min(ans, map[fin.first][fin.second][k]);
        }
    }
    if(ans == 3000)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    cin>>human.loc.first>>human.loc.second;
    cin>>fin.first>>fin.second;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j][0];
            if(map[i][j][0] == 1)
                map[i][j][0] = -1; // 벽을 -1로 바꿈
            map[i][j][1] = map[i][j][0];
        }
    }
    // map에 맞게 위치 보정
    human.loc.first--;
    human.loc.second--;
    fin.first--;
    fin.second--;
    
    q.push(human);

    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
    
}
