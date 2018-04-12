//
//  main.cpp
//  [7576] 토마토
//
//  Created by YOO TAEWOOK on 2018. 3. 8..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

//정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dirX = {0, 0, 1, -1};
vector<int> dirY = {1, -1, 0, 0};

const int MATURE = 1, UNMATURE = 0, EMPTY = -1;
int ROW, COL;
int DAY = 0;
bool SUCCESS = false;
int maturedNum = 0, unmaturedNum = 0;
queue<pair<int, int> > maturedQueue;
void BFS(vector< vector<int> >&);
int lastX, lastY;
int main(int argc, const char * argv[]) {
    cin>>COL>>ROW;
    vector< vector<int> > space(ROW, vector<int>(COL)); // 창고
    vector< vector<bool> > visited(ROW, vector<bool>(COL, false)); // 방문 벡터
    
    for(int i = 0 ; i < ROW ; i++){
        for(int j = 0 ; j < COL ; j++){
            cin>>space[i][j];
            if(space[i][j] == 1){
                maturedNum++; // 익은 토마토 수 세기
                maturedQueue.push(pair<int, int>(i, j)); //초기 익은 토마토 큐에 넣기
            }else if(space[i][j] == 0){
                unmaturedNum++; // 안 익은 토마토 수 세기
            }
        }
    }
    
    lastX = maturedQueue.back().first; // 각 주기가 끝날 때를 알 수 있도록 큐의 가장 마지막 pair의 x값을 저장
    lastY = maturedQueue.back().second;// 각 주기가 끝날 때를 알 수 있도록 큐의 가장 마지막 pair의 y값을 저장
    
    if(maturedNum == ROW*COL){ // 처음부터 모든 칸에 익은 토마토만 있을 경우
        cout<<0<<endl;
        return 0;
    }
    
    if(maturedNum == 0){ // 처음부터 모든 칸에 익은 토마토가 없을 경우
        cout<<-1<<endl;
        return 0;
    }
    
    BFS(space);
    
    if(unmaturedNum == 0)
        cout<<DAY<<endl;
    else
        cout<<-1<<endl;
    
    
    return 0;
}

void BFS(vector< vector<int> > &space){
    while(!maturedQueue.empty()){
        int x = maturedQueue.front().first;
        int y = maturedQueue.front().second;
        maturedQueue.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            if(newX >= 0 && newX < ROW && newY >= 0 && newY < COL){
                if(space[newX][newY] == UNMATURE){
                    space[newX][newY] = 1;
                    maturedNum++;
                    unmaturedNum--;
                    maturedQueue.push(pair<int, int>(newX, newY));
                }
            }
        }
        if(lastX == x && lastY == y){ // lastX, lastY는 큐의 맨 마지막에 있던 좌표(하루가 지났음을 알려줌)
            if(!maturedQueue.empty()){ // 이 때 큐가 비어있지 않다는건 새로 익은 토마토들이 있다는 것
                lastX = maturedQueue.back().first; //lastX lastY 새롭게 설정
                lastY = maturedQueue.back().second;
                DAY++;
            }
        }
    }
}

