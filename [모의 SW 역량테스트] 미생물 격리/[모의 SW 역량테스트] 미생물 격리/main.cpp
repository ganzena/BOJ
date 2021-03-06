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
queue<pii> lifeQ; //미생물 좌표 들어있는 큐
vector< vector<Micro> > map; //원본 맵
vector< vector<Micro> > copyMap; //원본맵에서 이동해올거임
vector< vector<Micro> > initMap; //미생물 하나도 없는 맵
vector<pii> dir = {pii(-1, 0), pii(1, 0), pii(0, -1), pii(0, 1)}; // 동서남북
int test, cellSize, timeLimit, groupNum, counter = 0;

void init(); //초기화
void move(); //움직임
void count(); //미생물 수 세기
void print();
int reverseDir(int); //반대 방향으로 바꾸기
int main(int argc, const char * argv[]) {
    int cnt = 0;
    cin>>test;
    while(cnt < test){
        init(); //초기화
        while(timeLimit--){ //격리 시간만큼 움직임
            move();
        }
        count();
        cnt++;
        printf("#%d %d\n", cnt, counter);
    }
    return 0;
}
void move(){
    queue<pii> copyQ; // 원래 있는 미생물 큐에서 움직일때마다 카피큐로 들어감
    while(!lifeQ.empty()){
        int i = lifeQ.front().first;
        int j = lifeQ.front().second;
        int curDir = map[i][j].dir;
        int newI = i + dir.at(curDir).first;
        int newJ = j + dir.at(curDir).second;
        lifeQ.pop();
        if(newI >= 0 && newJ >= 0 && newI < cellSize && newJ < cellSize){ //맵 안쪽에 들어왔을때
            if(newI == 0 || newI == cellSize - 1 || newJ == 0 || newJ == cellSize - 1){// 약품이 있는 경우
                copyMap[newI][newJ].num = map[i][j].num / 2;// 미생물 수가 반으로 줄고
                copyMap[newI][newJ].dir = reverseDir(map[i][j].dir); //방향이 반대로 바뀐다.
                copyMap[newI][newJ].maximum = copyMap[newI][newJ].num; //현재 들어온 최대 미생물은 그대로
                if(copyMap[newI][newJ].num == 0)
                    continue;
            }else{//약품이 없는 경우
                if(copyMap[newI][newJ].num != 0){ //이미 미생물이 있는 경우
                    if(copyMap[newI][newJ].maximum < map[i][j].num){ //새로 들어온 미생물 수가 더 많을 때
                        copyMap[newI][newJ].maximum = map[i][j].num; //현재 들어온 최대 수의 미생물로 업데이트
                        copyMap[newI][newJ].dir = map[i][j].dir; //방향 변경
                    }
                    copyMap[newI][newJ].num += map[i][j].num; //미생물 수 더해준다
                    continue;
                }else{ //미생물이 없는 경우
                    copyMap[newI][newJ] = map[i][j];
                }
            }
        }
        copyQ.push(pii(newI, newJ)); // 미생물이 움직인 좌표를 카피큐에 넣어줌
    }
    
    for(int i = 0 ; i < cellSize ; i++){
        for(int j = 0 ; j < cellSize ; j++){
            copyMap[i][j].maximum = copyMap[i][j].num; //움직임이 끝났으므로 이 순간 최대로 들어왔던 미생물 수를 현재 미생물 수로 업데이트
        }
    }
    lifeQ = copyQ; //다음 큐로 복사
    map = copyMap; //움직인 맵으로 업데이트
    copyMap = initMap; //미생물이 없는 빈 맵으로 업데이트
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
    while(!lifeQ.empty()) //미생물큐 비워줌
        lifeQ.pop();
    while(groupNum--){ //미생물 수 받아줌
        int i, j, microNum, curDir; //좌표, 좌표, 미생물 수 , 현재방향
        cin>>i>>j>>microNum>>curDir;
        curDir--;
        map[i][j] = {microNum, curDir, microNum}; //맵에 미생물 정보 박아줌
        lifeQ.push(pii(i, j)); //미생물이니까 미생물 큐에 넣어줌
    }
    counter = 0; //카운터 초기화
}
