//
//  main.cpp
//  [2146] 다리 만들기
//
//  Created by YOO TAEWOOK on 2020/05/10.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tile{
    int isSum; //섬인지 아닌지
    int no; //섬을 구분하기 위한 번호
};

vector<vector<Tile> > map;
vector<pair<int, int> > dir;

void init();
void search();
void mark(int, int, int);
void solve();

int N;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    
}

void search(){
    int no = 1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j].isSum == 1 && map[i][j].no == 0){
                mark(i, j, no);
                no++;
            }
        }
    }
}

void mark(int i, int j, int no){
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    map[q.front().first][q.front().second].no = no;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            pair<int, int> next = make_pair(now.first + dir.at(i).first, now.second + dir.at(i).second);
            if(next.first >= N || next.second >= N || next.first < 0 || next.second < 0)
                continue;
            if(map[next.first][next.second].isSum != 1 || map[next.first][next.second].no != 0)
                continue;
            map[next.first][next.second].no = no;
            q.push(next);
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N;
    map.assign(N, vector<Tile>(N, {0, 0}));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            int input;
            cin>>input;
            if(input == 1){
                map[i][j].isSum = 1;
            }
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
