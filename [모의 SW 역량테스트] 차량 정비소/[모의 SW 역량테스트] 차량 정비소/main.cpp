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
#include <algorithm>
using namespace std;


struct Customer{
    int visitTime; //방문 시간
    int number; // 고객 넘버링
    int receptionNum; //이용한 접수 창구 번호
    int repairNum; //이용한 정비 창구 번호
};

struct Desk{
    int deskNum;
    int totalTime; // 총 걸리는 시간
    int spendTime; // 고객이 현재 소비한 시간
    Customer customer;
};
vector<Desk> receptionDesk;
vector<Desk> repairDesk;
queue<Customer> completeQ;
queue<Customer> receptionQ;
queue<Customer> repairQ;
vector<Customer> tempQ;
int test, receptionNum, repairNum, totalCustomer, lostReception, lostRepair, total = 0;

int totalTime = 0;
void init();
void move(); //이동
void run(); //업무
void check(); //완료된 사람 체크
bool compare(const Customer, const Customer);

int main(int argc, const char * argv[]) {
    int cnt = 0;
    cin>>test;
    while(cnt < test){
        init();
        while(completeQ.size() < totalCustomer){
            move();
            totalTime++;
            run();
        }
        check();
        cnt++;
        if(total == 0)
            printf("#%d %d\n", cnt, -1);
        else
            printf("#%d %d\n", cnt, total);
    }
    return 0;
}

void move(){ //이동만 함
    while(!receptionQ.empty() && receptionQ.front().visitTime <= totalTime){ //호출 순가나 이미 방문해 있을 때
        int i;
        for(i = 0 ; i < receptionNum ; i++){
            if(receptionDesk[i].customer.number == 0){ // 아무도 없다!
                receptionDesk[i].customer = receptionQ.front();
                receptionDesk[i].customer.receptionNum = receptionDesk[i].deskNum;
                receptionQ.pop();
                break;
            }
        }
        if(i == receptionNum)
            break;
    }
    
    while(!repairQ.empty()){
        int i;
        for(i = 0 ; i < repairNum ; i++){
            if(repairDesk[i].customer.number == 0){
                repairDesk[i].customer = repairQ.front();
                repairDesk[i].customer.repairNum = repairDesk[i].deskNum;
                repairQ.pop();
                break;
            }
        }
        if(i == repairNum)
            break;
    }
}

void run(){
    for(int i = 0 ; i < receptionNum ; i++){ //접수 창구에서
        if(receptionDesk[i].customer.number != 0){ //사람이 있다면
            receptionDesk[i].spendTime++; //업무를 1단위 하고
            if(receptionDesk[i].spendTime == receptionDesk[i].totalTime){ //완료가 되면
                tempQ.push_back(receptionDesk[i].customer);
                receptionDesk[i].spendTime = 0; //고객 1명이 끝나면 초기화
                receptionDesk[i].customer = {};
            }
        }
    }
    
    if(!tempQ.empty()){
        sort(tempQ.begin(), tempQ.end(), compare);
        for(int i = 0 ; i < tempQ.size() ; i++){
            repairQ.push(tempQ[i]);
        }
        while(!tempQ.empty())
            tempQ.pop_back();
    }
    
    for(int i = 0 ; i < repairNum ; i++){
        if(repairDesk[i].customer.number != 0){ //사람이 있다면
            repairDesk[i].spendTime++; //업무를 1단위 하고
            if(repairDesk[i].spendTime == repairDesk[i].totalTime){ //완료가 되면
                completeQ.push(repairDesk[i].customer);
                repairDesk[i].spendTime = 0; //고객 1명이 끝나면 초기화
                repairDesk[i].customer = {};
            }
        }
    }
}

bool compare(const Customer x, const Customer y){
    return x.receptionNum < y.receptionNum;
}

void check(){
    while(!completeQ.empty()){
        if(completeQ.front().receptionNum == lostReception && completeQ.front().repairNum == lostRepair){
            total+=completeQ.front().number;
        }
        completeQ.pop();
    }
}

void init(){
    cin>>receptionNum>>repairNum>>totalCustomer>>lostReception>>lostRepair;
    // 접수 창구 갯수 >> 정비 창구 갯수 >> 방문한 고객의 수 >> 지갑 두고 간 놈 접수창구 >> 지갑 두고 간놈 정비창구
    receptionDesk.assign(receptionNum, {0,});
    repairDesk.assign(repairNum, {0,});
    
    for(int i = 0 ; i < receptionNum ; i++){ //접수창구 초기화
        int timeLimit;
        cin>>timeLimit;
        receptionDesk[i] = {i + 1, timeLimit, 0, };
    }
    
    for(int i = 0 ; i < repairNum ; i++){ //정비창구 초기화
        int timeLimit;
        cin>>timeLimit;
        repairDesk[i] = {i + 1, timeLimit, 0, };
    }
    
    for(int i = 0 ; i < totalCustomer ; i++){ //고객배열 초기화
        int visitTime;
        cin>>visitTime;
        receptionQ.push({visitTime, i + 1, 0, 0, });
    }
    
    total = 0;
    totalTime = 0;
}
