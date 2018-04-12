//
//  main.cpp
//  [모의 SW 역량테스트] 미생물 격리
//
//  Created by YOO TAEWOOK on 2018. 4. 11..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 100

using namespace std;
struct Micro{
    int num; //미생물 갯수
    int dir; //방향
    int maximum; //현재 칸에 방문한 최대 미생물갯수
    
};
typedef pair<int, int> pii;
queue<pii> lifeQ;
vector< vector<Micro> > map;
vector< vector<Micro> > copyMap;
vector< vector<Micro> > initMap;
vector<pii> dir = {pii(-1, 0), pii(1, 0), pii(0, -1), pii(0, 1)};
int test, cellSize, timeLimit, groupNum, counter = 0;

void init();
void move();
void count();
void print();
int reverseDir(int);
int main(int argc, const char * argv[]) {
    int cnt = 0;
    cin>>test;
    while(cnt < test){
        init();
        while(timeLimit--){
            move();
        }
        count();
        cnt++;
        printf("#%d %d\n", cnt, counter);
    }
    return 0;
}
void move(){
    queue<pii> copyQ;
    while(!lifeQ.empty()){
        int i = lifeQ.front().first;
        int j = lifeQ.front().second;
        int curDir = map[i][j].dir;
        int newI = i + dir.at(curDir).first;
        int newJ = j + dir.at(curDir).second;
        lifeQ.pop();
        if(newI >= 0 && newJ >= 0 && newI < cellSize && newJ < cellSize){
            if(newI == 0 || newI == cellSize - 1 || newJ == 0 || newJ == cellSize - 1){// 약품이 있는 경우
                copyMap[newI][newJ].num = map[i][j].num / 2;// 미생물 수가 반으로 줄고
                copyMap[newI][newJ].dir = reverseDir(map[i][j].dir); //방향이 반대로 바뀐다.
                copyMap[newI][newJ].maximum = copyMap[newI][newJ].num;
                if(copyMap[newI][newJ].num == 0)
                    continue;
            }else{//약품이 없는 경우
                if(copyMap[newI][newJ].num != 0){ //이미 미생물이 있는 경우
                    if(copyMap[newI][newJ].maximum < map[i][j].num){ //새로 들어온 미생물 수가 더 많을 때
                        copyMap[newI][newJ].maximum = map[i][j].num; //유입한 미생물 숫자 최대치 업데이트
                        copyMap[newI][newJ].dir = map[i][j].dir; //방향 변경
                    }
                    copyMap[newI][newJ].num += map[i][j].num;
                    continue;
                }else{ //미생물이 없는 경우
                    copyMap[newI][newJ] = map[i][j];
                }
            }
        }
        copyQ.push(pii(newI, newJ));
    }
    for(int i = 0 ; i < cellSize ; i++){
        for(int j = 0 ; j < cellSize ; j++){
            copyMap[i][j].maximum = copyMap[i][j].num;
        }
    }
    lifeQ = copyQ;
    map = copyMap;
    copyMap = initMap;
}

void count(){
    for(int i = 0 ; i < cellSize ; i++){
        for(int j = 0 ; j < cellSize ; j++){
            counter += map[i][j].num;
        }
    }
}

int reverseDir(int curDir){
    if(curDir == 0){
        return 1;
    }else if(curDir == 1){
        return 0;
    }else if(curDir == 2){
        return 3;
    }else if(curDir == 3){
        return 2;
    }
    return -1;
}

void init(){//맵 초기화
    cin>>cellSize>>timeLimit>>groupNum;
    map.assign(cellSize, vector<Micro>(cellSize, {0,-1,0}));
    copyMap = map;
    initMap = map;
    while(!lifeQ.empty())
        lifeQ.pop();
    while(groupNum--){
        int i, j, microNum, curDir;
        cin>>i>>j>>microNum>>curDir;
        curDir--;
        map[i][j] = {microNum, curDir, microNum};
        lifeQ.push(pii(i, j));
    }
    counter = 0;
}
