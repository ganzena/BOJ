//
//  main.cpp
//  [12100] 2048 (Easy)
//
//  Created by YOO TAEWOOK on 2018. 3. 30..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> copied;
vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1) };
int N;

void init();
void DFS(int);
void move(int);
int main(int argc, const char * argv[]) {
    init();
    DFS(0);
    return 0;
}

void DFS(int depth){
    
    if(depth >= 5){
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++){
        copied = map;
        move(i);
        DFS(depth + 1);
        map = copied;
    }
}

void move(int d){ // 0 : N, 1 : E, 2 : S, 3 : W
    //    if(d == 0){
    //        for(int j = 0 ; j < N ; j++){
    //            for(int i = 0 ; i < N ; i++){
    //                pair<int, int> now = make_pair(i, j);
    //                pair<int, int> next = make_pair(i + dir.at(d).first, j + dir.at(d).n)
    //            }
    //        }
    //    }else if(d == 1){
    //
    //    }else if(d == 2){
    //
    //    }else if(d == 3){
    //
    //    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j == 0])
                continue;
            pair<int, int> now = make_pair(i, j);
            while(1){
                pair<int, int> next = make_pair(now.first + dir.at(d).first, now.second + dir.at(d).second);
                if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N){
                    break;
                }
                if(map[next.first][next.second] != 0 || map[next.first][next.second] != map[now.first][now.second]){
                    break;
                }
            }
            
        }
    }
}

void init(){
    cin>>N;
    map.assign(N, vector<int>(N, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }
}
