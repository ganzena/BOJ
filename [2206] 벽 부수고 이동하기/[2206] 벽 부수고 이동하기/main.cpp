//
//  main.cpp
//  [2206] 벽 부수고 이동하기
//
//  Created by YOO TAEWOOK on 2018. 4. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;

class Location{
public:
    int i, j;
    bool skill;
    Location(int i, int j, bool skill){
        this->i = i;
        this->j = j;
        this->skill = skill;
    }
};
vector<vector<int> > map;
//0은 벽 안 부심 1은 벽 부심
int dis[1000][1000][2]; // 폭탄을 썼을 때와 안 썼을때의 거리를 각각 저장
//bool visited[1000][1000][2]; // 폭탄 쓰고 방문했나 아닌가
queue<Location> locQ;
vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};

int initI = 0, initJ = 0;
int endI, endJ;
int height, width;

void BFS();
void DFS(int, int, bool);
void init();
void print();
int main(int argc, const char * argv[]) {
    init();
    BFS();
    print();
    
    return 0;
}

void init(){
    cin>>height>>width;
    map.assign(height, vector<int>(width));
    endI = height - 1;
    endJ = width - 1;
    locQ.push(Location(initI, initJ, false));
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            int temp;
            scanf("%1d", &temp);
            map[i][j] = temp;
        }
    }
    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j < 1000 ; j++){
            for(int k = 0 ; k < 2 ; k++){
                dis[i][j][k] = INT_MAX;
            }
        }
    }
}

void DFS(){
    
}

void BFS(){
    dis[initI][initJ][0] = 1;
    while(!locQ.empty()){
        int startI = locQ.front().i;
        int startJ = locQ.front().j;
        bool useSkill = locQ.front().skill;
        locQ.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newI = startI + dir.at(i).first;
            int newJ = startJ + dir.at(i).second;
            if(newI >= 0 && newJ >= 0 && newI < height && newJ < width){
                if(map[newI][newJ] == 0 && (dis[startI][startJ][useSkill] + 1 < dis[newI][newJ][useSkill])){ // 벽이 없는 경우 그냥 통과
                    dis[newI][newJ][useSkill] = dis[startI][startJ][useSkill] + 1;
                    locQ.push(Location(newI, newJ, useSkill));
                }
                
                if(map[newI][newJ] == 1 && useSkill == false && (dis[startI][startJ][0] + 1 < dis[newI][newJ][1])){ //벽인 경우, 벽을 안부시고 왔을 때의 거리에서 +1 한 값이 해당 위치의 벽을 부쉇을 때 거리보다 짧다면
                    dis[newI][newJ][1] = dis[startI][startJ][0] + 1;
                    locQ.push(Location(newI, newJ, true)); // 벽을 부셨으니 true;
                }
            }
        }
    }
}

void print(){
    if(dis[endI][endJ][0] == INT_MAX && dis[endI][endJ][1] == INT_MAX)
        cout<<-1<<endl;
    else
        cout<<min(dis[endI][endJ][0], dis[endI][endJ][1])<<endl;
}
