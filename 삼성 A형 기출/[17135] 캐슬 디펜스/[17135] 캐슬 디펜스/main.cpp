//
//  main.cpp
//  [17135] 캐슬 디펜스
//
//  Created by YOO TAEWOOK on 2020/03/14.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Enemy{
    int x;
    int y;
    bool alive; // 생존 여부
};

vector<vector<int> > initMap; //초기 맵 상태
vector<vector<int> > map;

vector<pair<int, int> > archerV;
vector<Enemy> initEnemyV; //초기 적 상태
vector<Enemy> enemyV;

void init();
void solve(int ,int);
int kill(); // 적 죽이기
void move(); // 적 이동 시키기

int N, M, D;
int maxKill = -1;

int main(int argc, const char * argv[]) {
    init();
    solve(0, 0);
    cout<<maxKill<<endl;
    return 0;
}

int kill(){
    vector<Enemy>::iterator iter;
    for(int i =  0 ; i < archerV.size() ; i++){
        pair<int, int> archer = archerV.at(i);
        int minDist = INT_MAX;
        vector<Enemy>::iterator targetIter = enemyV.end() - 1; // .end()로 잡으면 안됨 (end()는 벡터의 끝 칸보다 한 칸 더 뒤)
        for(iter = enemyV.begin() ; iter != enemyV.end() ; iter++){
            int tempDist = abs(iter->x - archer.first) + abs(iter->y - archer.second);
            if(minDist > tempDist && tempDist <= D){
                minDist = tempDist;
                targetIter = iter;
            }else if(minDist == tempDist){
                if(targetIter->y > iter->y){
                    targetIter = iter;
                }
            }
        }
        if(minDist != INT_MAX) //최소 거리가 변경되었다면 죽은 적이 있다
            targetIter->alive = false; // 죽음 표시
    }
    int cnt = 0;
    for(iter = enemyV.begin() ; iter != enemyV.end() ; iter++){
        if(iter->alive == false){ // 죽음 표시 된 놈들 죽임
            cnt++;
            map[iter->x][iter->y] = 0;
            // 지워지면서 한 칸씩 떙겨짐 지워진 요소의 다음 위치를 가르키게됨
            // 따라서 위치 조정 안 해주면 해당 위치를 건너뛰게 되므로 보정해줘야함
            enemyV.erase(iter--);
        }
    }
    return cnt;
}

void move(){
    if(enemyV.empty())
        return;
    vector<Enemy>::iterator iter;
    for(iter = enemyV.begin() ; iter != enemyV.end() ; iter++){
        int xx = iter->x + 1;
        if(xx == N){ // 성 안으로 들어갔으므로 제외
            map[iter->x][iter->y] = 0;
            // 지워지면서 한 칸씩 떙겨짐 지워진 요소의 다음 위치를 가르키게됨
            // 따라서 위치 조정 안 해주면 해당 위치를 건너뛰게 되므로 보정해줘야함
            enemyV.erase(iter--);
        }else{
            map[iter->x++][iter->y] = 0;
            map[iter->x][iter->y] = 1;
        }
    }
}

void solve(int depth, int idx){
    if(depth == 3){
        map = initMap;
        enemyV = initEnemyV;
        int killed = 0;
        while(!enemyV.empty()){
            killed += kill();
            move();
        }
        maxKill = max(maxKill, killed);
        return;
    }
    
    for(int j = idx ; j < M ; j++){
        archerV.push_back(make_pair(N, j));
        solve(depth + 1, j + 1);
        archerV.pop_back();
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>D;
    initMap.assign(N + 1, vector<int>(M, 0));
    for(int i = 0 ; i < N + 1; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>initMap[i][j];
            if(initMap[i][j] == 1){
                Enemy temp;
                temp.x = i;
                temp.y = j;
                temp.alive = true;
                initEnemyV.push_back(temp);
            }
        }
    }
}
