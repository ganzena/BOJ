//
//  main.cpp
//  [14500] 테트로미노
//
//  Created by YOO TAEWOOK on 2018. 3. 14..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;

vector<pair<int, int>> dir = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

int N, M;
int maximum = 0;

void init();
void run();
void DFS(int, pair<int, int>, int);
void vertical(pair<int, int>);
void horizontal(pair<int, int>);
int main(int argc, const char * argv[]) {
    init();
    run();
    cout<<maximum<<endl;
    return 0;
}

void run(){
    visited.assign(N, vector<bool>(M, false));

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
//            visited.assign(N, vector<bool>(M, false));
            pair<int, int> start = make_pair(i, j);
            DFS(0, start, 0);
            vertical(start);
            horizontal(start);
        }
    }
}

void vertical(pair<int, int> start){
    // ㅓ ㅏ
    int left = 0, right = 0;
    if(start.first < N - 1 && start.first > 0){ // 가운데가 기준
        if(start.second > 0)
            left = map[start.first][start.second] + map[start.first][start.second - 1] + map[start.first + 1][start.second] + map[start.first - 1][start.second];
        if(start.second < M - 1)
            right = map[start.first][start.second] + map[start.first][start.second + 1] + map[start.first + 1][start.second] + map[start.first - 1][start.second];
    }
    left = max(left, right);
    maximum = max(left, maximum);
}

void horizontal(pair<int, int> start){
    // ㅜ ㅗ
    int up = 0, down = 0;
    if(start.second < M - 1 && start.second > 0){
        if(start.first > 0)
            up = map[start.first][start.second] + map[start.first - 1][start.second] + map[start.first][start.second - 1] + map[start.first][start.second + 1];
        if(start.first < N - 1)
            down = map[start.first][start.second] + map[start.first + 1][start.second] + map[start.first][start.second - 1] + map[start.first][start.second + 1];
    }
    up = max(up, down);
    maximum = max(up, maximum);
}

void DFS(int depth, pair<int, int> start, int sum){
    if(depth == 4){
        maximum = max(maximum , sum);
        return;
    }
    visited[start.first][start.second] = true;
    for(int i = 0 ; i < 4 ; i++){
        pair<int, int> next = make_pair(start.first + dir.at(i).first, start.second + dir.at(i).second);
        if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M || visited[next.first][next.second])
            continue;
        sum += map[next.first][next.second];
        visited[next.first][next.second] = true;
        DFS(depth + 1, next, sum);
        visited[next.first][next.second] = false;
        sum -= map[next.first][next.second];
    }
    visited[start.first][start.second] = false;

}

void init(){
    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
        }
    }
}
