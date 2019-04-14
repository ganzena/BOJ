//
//  main.cpp
//  [15683] 감시
//
//  Created by YOO TAEWOOK on 2018. 4. 16..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct CCTV {
    pair<int, int> loc;
    int type;
};

vector< vector<int> > map;
vector<CCTV> cctvVector;
vector<int> rotateNum; // = {0, 4, 2, 4, 4, 1};
//    0
//3       1
//    2
int N, M;
int missArea = 100;

void init();
void DFS(int);
void checkMiss();
void update(int, CCTV);

int main(int argc, const char * argv[]) {
    init();
    DFS(0);
    cout<<missArea<<endl;
    return 0;
}
void checkMiss(){
    int temp = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 0)
                temp++;
        }
    }
    missArea = min(missArea, temp);
}

void DFS(int depth){
    if(depth == (int)cctvVector.size()){
        checkMiss();
        return;
    }
    CCTV now = cctvVector.at(depth);
    vector< vector<int> > copied;
    for(int i = 0 ; i < rotateNum.at(now.type) ; i++){
        copied = map;
        if(now.type == 1){
            update(i, now);
        }else if(now.type == 2){
            update(i, now);
            update(i + 2, now);
        }else if(now.type == 3){
            update(i, now);
            update(i + 1, now);
        }else if(now.type == 4){
            update(i, now);
            update(i + 1, now);
            update(i + 2, now);
        }else if(now.type == 5){
            update(i, now);
            update(i + 1, now);
            update(i + 2, now);
            update(i + 3, now);
        }
        DFS(depth + 1);
        map = copied;
    }
}

void update(int dir, CCTV cctv){
    dir = dir % 4;
    if(dir == 0){ //북
        for(int i = cctv.loc.first ; i >= 0 ; i--){
            if(map[i][cctv.loc.second] == 6)
                return;
            map[i][cctv.loc.second] = 7;
        }
    }else if(dir == 1){ //동
        for(int j = cctv.loc.second ; j < M ; j++){
            if(map[cctv.loc.first][j] == 6)
                return;
            map[cctv.loc.first][j] = 7;
        }
    }else if(dir == 2){ //남
        for(int i = cctv.loc.first ; i < N ; i++){
            if(map[i][cctv.loc.second] == 6)
                return;
            map[i][cctv.loc.second] = 7;
        }
    }else if(dir == 3){ //서
        for(int j = cctv.loc.second ; j >= 0 ; j--){
            if(map[cctv.loc.first][j] == 6)
                return;
            map[cctv.loc.first][j] = 7;
        }
    }
}


void init(){
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                CCTV temp = {make_pair(i, j), map[i][j]};
                cctvVector.push_back(temp);
            }
        }
    }
    rotateNum.push_back(0);
    rotateNum.push_back(4);
    rotateNum.push_back(2);
    rotateNum.push_back(4);
    rotateNum.push_back(4);
    rotateNum.push_back(1);
}

