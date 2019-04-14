//
//  main.cpp
//  [14502] 연구소
//
//  Created by YOO TAEWOOK on 2018. 3. 20..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int> > map;
vector<vector<int> > copiedMap;
vector<pair<int, int> > dir;
queue<pair<int, int> > virusQ;
int N, M;
int maximum = 0;

void init();
void DFS(int, int, int);
void BFS();
void checkSafe();

void print(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    init();
    DFS(0, 0, 0);
    cout<<maximum<<endl;
    return 0;
}

void DFS(int depth, int startI, int startJ){
    if(depth == 3){
        copiedMap = map;
        //print();
        BFS();
        checkSafe();
        map = copiedMap;
        return;
    }
    for(int i = startI ; i < N ; i++){
        for(int j = startJ ; j < M ; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                DFS(depth + 1, i, 0);
                map[i][j] = 0;
            }
        }
    }
}

void BFS(){
    queue<pair<int, int> > copyQ = virusQ;
    while(!copyQ.empty()){
        pair<int, int> now = copyQ.front();
        copyQ.pop();
        for(int i = 0 ; i < 4 ; i++){
            pair<int, int> next = make_pair(now.first + dir.at(i).first, now.second + dir.at(i).second);
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)
                continue;
            if(map[next.first][next.second] != 0)
                continue;
            map[next.first][next.second] = 2;
            copyQ.push(next);
        }
    }
}
void checkSafe(){
    int counter = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 0)
                counter++;
        }
    }
    maximum = max(counter, maximum);
}
void init(){
    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
            if(map[i][j] == 2)
                virusQ.push(make_pair(i, j));
        }
    }
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
