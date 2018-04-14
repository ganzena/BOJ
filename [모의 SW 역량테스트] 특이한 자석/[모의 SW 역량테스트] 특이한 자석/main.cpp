//
//  main.cpp
//  [모의 SW 역량테스트] 특이한 자석
//
//  Created by YOO TAEWOOK on 2018. 4. 13..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#define TOOTH 8

using namespace std;
typedef pair<int, int> pii;
queue<pii> commandQ; //자석 번호, 회전방향
vector< deque<int> > jasukVector;
vector<int> rotateRecord(5); // -1 역방향 0 회전 안함 1 시계방향
void init();
void rotateClock(int);
void rotateReverse(int);
void setRotation(int, int);
void doRotation();
void count();
int getScore(int);
int commandNum, result = 0;
int main(int argc, const char * argv[]) {
    int test, cnt = 1;
    cin>>test;
    while(cnt <= test){
        init();
        while(!commandQ.empty()){
            int jasukNo = commandQ.front().first;
            int rotateDir = commandQ.front().second;
            setRotation(jasukNo, rotateDir);
            doRotation();
            rotateRecord.assign(5, 0);
            commandQ.pop();
            
        }
        count();
        printf("#%d %d\n", cnt, result);
        cnt++;
    }
    return 0;
}

void count(){
    for(int i = 1 ; i < 5 ; i++){
        result += getScore(i);
    }
}

int getScore(int jasukNo){
    if(jasukVector[jasukNo].front() == 1){
        if(jasukNo == 1){
            return 1;
        }else if(jasukNo == 2){
            return 2;
        }else if(jasukNo == 3){
            return 4;
        }else if(jasukNo == 4){
            return 8;
        }
    }
    
    return 0;
}

void doRotation(){
    for(int i = 1 ; i < 5 ; i++){
        int dir = rotateRecord[i];
        if(dir == 1){
            rotateClock(i);
        }else if(dir == -1){
            rotateReverse(i);
        }
    }
}

void setRotation(int movedJasuk, int rotateDir){
    rotateRecord[movedJasuk] = rotateDir;
    for(int i = movedJasuk ; i < 4 ; i++){
        if(jasukVector[i].at(2) != jasukVector[i + 1].at(6)){
            rotateRecord[i + 1] = rotateRecord[i] * -1;
        }else{
            rotateRecord[i + 1] = 0;
        }
    }
    
    for(int i = movedJasuk ; i > 1 ; i--){
        if(jasukVector[i].at(6) != jasukVector[i - 1].at(2)){
            rotateRecord[i - 1] = rotateRecord[i] * -1;
        }else{
            rotateRecord[i - 1] = 0;
        }
    }
}

void rotateClock(int jasukNo){
    int temp = jasukVector[jasukNo].back();
    jasukVector[jasukNo].pop_back();
    jasukVector[jasukNo].push_front(temp);
}

void rotateReverse(int jasukNo){
    int temp = jasukVector[jasukNo].front();
    jasukVector[jasukNo].pop_front();
    jasukVector[jasukNo].push_back(temp);
}

void init(){
    cin>>commandNum;
    jasukVector.assign(5, deque<int>());
    
    for(int i = 1 ; i < 5 ; i++){
        for(int j = 0 ; j < TOOTH ; j++){
            int temp;
            cin>>temp;
            jasukVector[i].push_back(temp);
        }
    }
    
    while(commandNum--){
        int jasukNo, dir;
        cin>>jasukNo>>dir;
        commandQ.push(pii(jasukNo, dir));
    }
    
    result = 0;
}
