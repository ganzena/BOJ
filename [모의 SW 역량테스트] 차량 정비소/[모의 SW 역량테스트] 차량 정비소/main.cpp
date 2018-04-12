//
//  main.cpp
//  [모의 SW 역량테스트] 차량 정비소
//
//  Created by YOO TAEWOOK on 2018. 4. 12..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Customer{
    int visitTime; //방문 시간
    int number; // 고객 넘버링
    int receptionNum; //이용한 접수 창구 번호
    int repairNum; //이용한 정비 창구 번호
    bool receptionComplete;
    bool repairComplete;
};

struct Desk{
    int deskNum;
    int totalTime; // 총 걸리는 시간
    int customerNum;
    int spendTime; // 고객이 현재 소비한 시간
};
vector<Desk> receptionDesk;
vector<Desk> repairDesk;
vector<Customer> customerVec;
vector<Customer> completeVec;
queue<Customer> repairQ;
int test, receptionNum, repairNum, totalCustomer, lostReception, lostRepair, total = 0;

void init();
void move(); //이동
void run(); //업무
void check(); //완료된 사람 체크
int main(int argc, const char * argv[]) {
    
    int cnt = 0;
    cin>>test;
    while(cnt < test){
        init();
        while(!customerVec.empty()){
            move();
            run();
            if(!completeVec.empty())
                check();
        }
        cnt++;
        printf("#%d %d\n", cnt, cnt);
    }
    return 0;
}

void move(){ //이동만 함
    //    접수창고, 정비창구 갈 때 빈곳으로 가서 받고 없으면 기다림
    //    접수 창구의 우선순위는 아래와 같다.
    //    ① 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로 우선 접수한다.
    //    ② 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로 간다.
    
    //    정비 창구의 우선순위는 아래와 같다.
    //    ① 먼저 기다리는 고객이 우선한다.
    //    ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
    //    ③ 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.
    for(int i = 0 ; i < totalCustomer ; i++){
        if(customerVec[i].receptionNum == 0){ //아직 접수 안함
            for(int j = 0 ; j < receptionNum ; j++){
                if(receptionDesk[j].customerNum == 0){ //이용 중인 고객이 없으면
                    receptionDesk[j].customerNum = customerVec[i].number;
                    customerVec[i].receptionNum = receptionDesk[j].deskNum;
                }else{ //이용 중인 고객이 있다면
                    continue;
                }
            }
        }else{
            if(customerVec[i].receptionNum == 0){ //아직 접수 안함
                for(int j = 0 ; j < repairNum ; j++){
                    if(repairDesk[j].customerNum == 0){
                        
                    }
                }
            }else{
                
            }
        }
    }
}

void run(){
    for(int i = 0 ; i < receptionNum ; i++){ //접수 창구에서
        if(receptionDesk[i].customerNum != 0){ //사람이 있다면
            receptionDesk[i].spendTime++; //업무를 1단위 하고
            if(receptionDesk[i].spendTime == receptionDesk[i].totalTime){ //완료가 되면
                for(int j = 0 ; j < totalCustomer ; j++){ //해당 고객을 찾아서 표시해야함
                    if(receptionDesk[i].customerNum == customerVec[j].number){
                        customerVec[j].receptionComplete = true;
                        repairQ.push(customerVec[j]);
                    }
                }
                receptionDesk[i].spendTime = 0; //고객 1명이 끝나면 초기화
                receptionDesk[i].customerNum = 0;
            }
        }
    }
    
    for(int i = 0 ; i < repairNum ; i++){
        if(repairDesk[i].customerNum != 0){ //사람이 있다면
            repairDesk[i].spendTime++; //업무를 1단위 하고
            if(repairDesk[i].spendTime == repairDesk[i].totalTime){ //완료가 되면
                vector<Customer>::iterator removeIter;
                for(removeIter = customerVec.begin() ; removeIter != customerVec.end() ; removeIter++){ //해당 고객을 찾아서 표시해야함
                    if(repairDesk[i].customerNum == removeIter->number){
                        removeIter->repairComplete = true;
                        completeVec.push_back(*removeIter);
                        customerVec.erase(removeIter);
                        break;
                    }
                }
                repairDesk[i].spendTime = 0; //고객 1명이 끝나면 초기화
                repairDesk[i].customerNum = 0;
            }
        }
    }
}

void check(){
    for(int i = 0 ; i < completeVec.size() ; i++){
        if(completeVec[i].receptionNum == lostReception && completeVec[i].repairNum == lostRepair){
            total += customerVec[i].number;
        }
    }
}


void init(){
    cin>>receptionNum>>repairNum>>totalCustomer>>lostReception>>lostRepair;
    // 접수 창구 갯수 >> 정비 창구 갯수 >> 방문한 고객의 수 >> 지갑 두고 간 놈 접수창구 >> 지갑 두고 간놈 정비창구
    receptionDesk.assign(receptionNum, {0,});
    repairDesk.assign(repairNum, {0,});
    customerVec.assign(totalCustomer, {0,});
    
    for(int i = 0 ; i < receptionNum ; i++){
        int timeLimit;
        cin>>timeLimit;
        receptionDesk[i] = {i + 1, timeLimit, 0, };
    }
    
    for(int i = 0 ; i < repairNum ; i++){
        int timeLimit;
        cin>>timeLimit;
        repairDesk[i] = {i + 1, timeLimit, 0, };
    }
    
    for(int i = 0 ; i < totalCustomer ; i++){
        int visitTime;
        cin>>visitTime;
        customerVec[i] = {visitTime, i + 1, 0, 0, false, false};
    }
    
    total = 0;
    
    
    
}
