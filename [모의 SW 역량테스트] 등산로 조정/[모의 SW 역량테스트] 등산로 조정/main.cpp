//
//  main.cpp
//  [모의 SW 역량테스트] 등산로 조정
//
//  Created by YOO TAEWOOK on 2018. 4. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

class Load{
public:
    int i, j;
    bool builded;
    Load(int i, int j, bool builded){
        this->i = i;
        this->j = j;
        this->builded = builded;
    }
};

int dis[8][8][2];
bool visit[8][8][2];
vector< vector<int> > mountain;
vector< vector<int> > copyMountain;
vector<pii> dir = {pii(1, 0), pii(0, 1), pii(-1, 0), pii(0, -1)};
queue<Load> topQ;
queue<Load> loadQ;
int mountainSize, buildMax, maxLen;

void init();
void DFS(int, int, bool, int);
int main(int argc, const char * argv[]) {
    int test, cnt = 1;
    cin>>test;
    while(cnt <= test){
        init();
        while(!topQ.empty()){
            DFS(topQ.front().i, topQ.front().j, topQ.front().builded, 1);
            topQ.pop();
        }
        printf("#%d %d\n", cnt, maxLen);
        cnt++;
    }
    return 0;
}

void DFS(int startI, int startJ, bool builded, int dist){
    dis[startI][startJ][builded] = dist;
    visit[startI][startJ][builded] = true;
    maxLen = max(maxLen, dist);
    for(int i = 0 ; i < 4 ; i++){
        int newI = startI + dir.at(i).first;
        int newJ = startJ + dir.at(i).second;
        if(newI >= 0 && newJ >= 0 && newI < mountainSize && newJ < mountainSize && visit[newI][newJ][builded] == false){
            //공사 안 해도 되는 경우(다음 지점이 높이가 낮고, 지금 접근하는 길의 길이가 더 짧을 때)
            if((mountain[startI][startJ] > mountain[newI][newJ]) && (dis[startI][startJ][builded] + 1 > dis[newI][newJ][builded])){
                DFS(newI, newJ, builded, dist + 1);
            }
            // 공사를 해야할 경우
            if((mountain[startI][startJ] <= mountain[newI][newJ]) && builded == false && (dis[startI][startJ][builded] + 1 > dis[newI][newJ][builded])){
                if(mountain[newI][newJ] - mountain[startI][startJ] + 1 <= buildMax){ //최대 공사 높이 안에서 공사가 가능한 경우
                    int temp = mountain[newI][newJ];
                    mountain[newI][newJ] = mountain[startI][startJ] - 1;
                    DFS(newI, newJ, true, dist + 1);
                    mountain[newI][newJ] = temp;
                }
            }
        }
    }
    dis[startI][startJ][builded] = 0;
    visit[startI][startJ][builded] = false;
}

void init(){
    int maxHeight = 0;
    
    cin>>mountainSize>>buildMax;
    mountain.assign(mountainSize, vector<int>(mountainSize));
    
    for(int i = 0 ; i < mountainSize ; i++){
        for(int j = 0 ; j < mountainSize ; j++){
            cin>>mountain[i][j];
            maxHeight = max(mountain[i][j], maxHeight);
        }
    }
    
    for(int i = 0 ; i < mountainSize ; i++){
        for(int j = 0 ; j < mountainSize ; j++){
            if(maxHeight == mountain[i][j])
                topQ.push(Load(i, j, false));
        }
    }
    
    memset(dis, 0, sizeof(dis));

    maxLen = 0;
}
