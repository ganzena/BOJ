//
//  main.cpp
//  [2018 상][15683] 감시
//
//  Created by YOO TAEWOOK on 2020/04/27.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct CCTV {
    pair<int, int> loc; // CCTV의 좌표
    int type; // CCTV 넘버
};

vector< vector<int> > map;
vector<CCTV> cctvVector;
vector<int> rotateNum; // CCTV가 회전할 횟수 {0, 4, 2, 4, 4, 1};
//    0
//3       1
//    2
int N, M;
int missArea = 100;

void init(); // 초기화
void DFS(int); //
void checkMiss(); // 감시 안 되는 영역 체크
void update(int, CCTV); // 감시 가능한 영역 체크

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

void DFS(int depth){ //depth는 CCTV 벡터의 인덱스
    if(depth == (int)cctvVector.size()){ // 모든 CCTV의 감시 영역을 업데이트 했을 때
        checkMiss();
        return;
    }
    CCTV now = cctvVector.at(depth);
    vector< vector<int> > copied; // 원래 맵을 보존하기 위한 임시 맵
    for(int i = 0 ; i < rotateNum.at(now.type) ; i++){ // CCTV의 회전 가능 수 만큼 for문이 돈다
        copied = map; // 원래의 맵 옮기기
        if(now.type == 1){
            update(i, now);
        }else if(now.type == 2){
            update(i, now);
            update(i + 2, now);
        }else if(now.type == 3){
            update(i, now);
            update(i + 1, now);
        }else if(now.type == 4){ // CCTV가 감시하는 방향만큼 update문을 수행
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
        map = copied; // 원상 복구
    }
}

void update(int dir, CCTV cctv){ // 감시 당하는 영역은 7로 표기
    dir = dir % 4; // 4 방향 중의 하나를 정하기 위해 mod 연산 수행
    if(dir == 0){ //북
        for(int i = cctv.loc.first ; i >= 0 ; i--){
            if(map[i][cctv.loc.second] == 6) // 벽 만나면 끝
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
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){ // CCTV일 경우
                CCTV temp = {make_pair(i, j), map[i][j]};
                cctvVector.push_back(temp); // CCTV 벡터에 추가
            }
        }
    }
    // 회전수를 저장 (Index는 CCTV 번호)
    rotateNum.push_back(0);
    rotateNum.push_back(4);
    rotateNum.push_back(2);
    rotateNum.push_back(4);
    rotateNum.push_back(4);
    rotateNum.push_back(1);
}
