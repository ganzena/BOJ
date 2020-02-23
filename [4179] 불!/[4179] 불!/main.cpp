//
//  main.cpp
//  [4179] 불!
//
//  Created by YOO TAEWOOK on 16/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map [1001][1001];
int visit[1001][1001] = {0, }; //불 방문은 2 지훈 방문은 1

queue<pair<int, int> > jihoonQ;
queue<pair<int, int> > fireQ;
vector<pair<int, int> > dir;

void init();
void solve();
void print();

int R, C;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    int time = 0; // 탈출하느네 걸리는 시간
    while(!jihoonQ.empty()){ //지훈이 큐가 비어버릴 경우 탈출 못하는 거임
        int fSize = (int)fireQ.size(); // 현재 들어있는 불의 사이즈
        for(int i = 0 ; i < fSize ; i++){ // 현재 불 사이즈 만큼만 BFS 진행
            pair<int, int> now = fireQ.front();
            fireQ.pop();
            visit[now.first][now.second] = 2;
            for(int j = 0 ; j < 4 ; j++){
                pair<int, int> next = make_pair(now.first + dir.at(j).first, now.second + dir.at(j).second);
                if(next.first >= R || next.first < 0 || next.second >= C || next.second < 0 || visit[next.first][next.second] == 2 || map[next.first][next.second] == '#'){
                    continue;
                }
                
                visit[next.first][next.second] = 2; //불의 방문은 2로
                fireQ.push(next);
            }
        }

        int jSize = (int)jihoonQ.size();
        for(int i = 0 ; i < jSize ; i++){ //현재 들어있는 지훈의 사이즈만큼만 진행
            pair<int, int> now = jihoonQ.front();
            jihoonQ.pop();
            visit[now.first][now.second] = 1;
            if(now.first >= R || now.first < 0 || now.second >= C || now.second < 0){ //만약 배열 바깥이라면 탈출한거임
                cout<<time<<endl; //현재시간 출력
                return;
            }
            for(int j = 0 ; j < 4 ; j++){
                pair<int, int> next = make_pair(now.first + dir.at(j).first, now.second + dir.at(j).second);
                if( visit[next.first][next.second] != 0 || map[next.first][next.second] == '#'){
                    continue; // visit이 0인곳만 통과 가능(이미 지훈이나 불이 방문한 경우는 안감)
                }
                
                visit[next.first][next.second] = 1; //visit을 1로 만듦
                jihoonQ.push(next);
            }
        }
        time++; //큐가 다 돌면 time++;
    }
   
    cout<<"IMPOSSIBLE"<<endl; //지훈이 큐가 비어버려서 나온 것이므로 불가능 출력
    return;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>R>>C;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin>>map[i][j];
            if(map[i][j] == 'F'){
                fireQ.push(make_pair(i, j));
            }else if(map[i][j] == 'J'){
                jihoonQ.push(make_pair(i, j));
            }
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}


