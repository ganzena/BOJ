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

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = {pair<int, int>(0, 1), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(-1, 0)};
int tcNum;
int M, N, K;

void init();
int BFS();

int main(int argc, const char * argv[]) {
    cin>>tcNum;
    for(int i = 0 ; i < tcNum ; i++){
        init();
        cout<<BFS()<<endl;
    }
    return 0;
}

int BFS(){
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 1 && visited[i][j] == false){
                queue<pair<int, int>> q;
                q.push(pair<int, int>(i, j));
                visited[i][j] = true;
                while(!q.empty()){
                    pair<int, int> now = q.front();
                    q.pop();
                    for(int i = 0 ; i < 4 ; i++){
                        pair<int, int> next = make_pair(now.first + dir.at(i).first, now.second + dir.at(i).second);
                        if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M){
                            continue;
                        }
                        if(map[next.first][next.second] == 1 & visited[next.first][next.second] == false){
                            visited[next.first][next.second] = true;
                            q.push(next);
                        }
                    }
                }
                count++;
            }
        }
    }
    return count;
}

void init(){
    cin>>M>>N>>K;
    map.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, 0));
    for(int i = 0 ; i < K ; i++){
        int m, n;
        cin>>m>>n;
        map[n][m] = 1;
    }
}
