//
//  main.cpp
//  [2468] 안전 영역
//
//  Created by YOO TAEWOOK on 11/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = {pair<int, int>(0, 1), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(-1, 0)};

int N;
int top = 0;
int maximumSafe = 0;

void init();
void BFS();

int main(int argc, const char * argv[]) {
    init();
    BFS();
    cout<<maximumSafe<<endl;
    return 0;
}

void BFS(){
    for(int h = 0 ; h <= top ; h++){
        int safeCounter = 0;
        visited.assign(N, vector<bool>(N, false));
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(map[i][j] > h && visited[i][j] == false){
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            pair<int, int> next = make_pair(now.first + dir.at(k).first, now.second + dir.at(k).second);
                            
                            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N)
                                continue;
                            
                            if(map[next.first][next.second] > h && visited[next.first][next.second] == false){
                                visited[next.first][next.second] = true;
                                q.push(next);
                            }
                        }
                    }
                    safeCounter++;
                }
            }
        }
        maximumSafe = max(safeCounter, maximumSafe);
    }
}

void init(){
    cin>>N;
    map.assign(N, vector<int>(N, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
            top = max(top, map[i][j]);
        }
    }
}
