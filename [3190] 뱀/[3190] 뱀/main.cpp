//
//  main.cpp
//  [3190] 뱀
//
//  Created by YOO TAEWOOK on 2018. 3. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAP_SIZE 101

using namespace std;

typedef pair<int, char> pic;
typedef pair<int, int> pii;
vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)}; //0 NORTH 1 WEST 2 SOUTH 3 EAST
vector< vector<pii> > map;
vector<char> timeVector(10000, 'S');
void PrintMap();
void move(int, int);
int turnLeft(int);
int turnRight(int);

int map_size, appleNum, cmdNum, snakeLen = 1, snakeHeadDir = 3, totalSec = 0;
pii snakeHead(1, 1);
pii snakeTail(1, 1);
int main(int argc, const char * argv[]) {
    cin>>map_size;
    map_size++;
    cin>>appleNum;
    map.assign(map_size, vector<pii>(map_size, pii(0, 4)));
    while(appleNum--){
        int appleI, appleJ;
        cin>>appleI>>appleJ;
        map[appleI][appleJ].first = 1;
    }
    cin>>cmdNum;
    while(cmdNum--){
        int second;
        char dir;
        cin>>second>>dir;
        timeVector[second] = dir;
    }
    
    map[1][1].first = 2;
    map[1][1].second = 3;

    move(1, 1);
    
    cout<<totalSec<<endl;
    return 0;
}

void move(int startI, int startJ){
    for(totalSec = 1 ; totalSec < timeVector.size() ; totalSec++){
        snakeHead.first = snakeHead.first + dir.at(snakeHeadDir).first;
        snakeHead.second = snakeHead.second + dir.at(snakeHeadDir).second;

        if(snakeHead.first > 0 && snakeHead.first < map_size && snakeHead.second > 0 && snakeHead.second < map_size){ //맵 안에 들어왔을때
            if(map[snakeHead.first][snakeHead.second].first == 2) // 자기 몸통에 박으면 끝
                break;
            if(map[snakeHead.first][snakeHead.second].first == 1){ //사과 있음
                map[snakeHead.first][snakeHead.second].first = 2; //뱀 머리가 앉음
                map[snakeHead.first][snakeHead.second].second = snakeHeadDir; //방향 표시
            }else{ //사과 없음
                map[snakeHead.first][snakeHead.second].first = 2; //뱀 머리가 앉음
                map[snakeHead.first][snakeHead.second].second = snakeHeadDir; //방향 표시
                int newTailI = snakeTail.first + dir.at(map[snakeTail.first][snakeTail.second].second).first; //꼬리의 새로운 위치 지정
                int newTailJ = snakeTail.second + dir.at(map[snakeTail.first][snakeTail.second].second).second; //꼬리의 새로운 위치 지정
                map[snakeTail.first][snakeTail.second].first = 0; //예전꼬리 초기화
                map[snakeTail.first][snakeTail.second].second = 4; //예전꼬리 초기화
                snakeTail.first = newTailI; //꼬리의 새로운 위치 지정
                snakeTail.second = newTailJ; //꼬리의 새로운 위치 지정
            }
        }else{
            break;
        }
        if(timeVector[totalSec] == 'L'){
            int nextDir = turnLeft(snakeHeadDir);
            map[snakeHead.first][snakeHead.second].second = nextDir;
            snakeHeadDir = nextDir;
        }else if(timeVector[totalSec] == 'D'){
            int nextDir = turnRight(snakeHeadDir);
            map[snakeHead.first][snakeHead.second].second = nextDir;
            snakeHeadDir = nextDir;
        }
    }
}

int turnLeft(int curDir){
    if(curDir == 3)
        return 0;
    else
        return ++curDir;
}

int turnRight(int curDir){
    if(curDir == 0)
        return 3;
    else
        return --curDir;
}
