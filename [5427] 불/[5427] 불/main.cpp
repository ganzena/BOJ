//
//  main.cpp
//  [5427] 불
//
//  Created by YOO TAEWOOK on 2018. 3. 29..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};

vector< vector<pib> > building;
queue<pii> fire;
queue<pii> human;

void fireBFS();
bool humanBFS();
void Print();
int testNum, row, col, cost = 1;
bool trap = true, isFire = false;

int main(int argc, const char * argv[]) {
    cin>>testNum;
    while(testNum--){
        cin>>col>>row;
        building.assign(row, vector<pib>(col, pib(0, false)));
        string str;
        for(int i = 0 ; i < row ; i++){
            cin>>str; //불 -1, 벽 -2, 나머지는 0
            for(int j = 0 ; j < col ; j++){
                if(str.at(j) == '#'){ // 벽
                    building[i][j] = pib(-2, true);
                }else if(str.at(j) == '*'){ // 불
                    isFire = true; //불이 있다를 표시
                    building[i][j] = pib(-1, true);
                    fire.push(pii(i, j));
                }else if(str.at(j) == '@'){
                    human.push(pii(i, j));
                }
            }
        }
        while(1){
            if(isFire) // 불이 있을때만 하기
                fireBFS();
            if(humanBFS()){ // 탈출(맵 밖으로 나감)하면 true
                cout<<cost<<endl;
                break;
            }
            if(trap){ //탈출을 못 할 경우
                cout<<"IMPOSSIBLE"<<endl;
                break;
            }
            
            cout<<cost<<endl;
            Print();
            cout<<endl;
            trap = true;
            cost++;
        }
        //변수들 초기화
        trap = true;
        cost = 1;
        while(!fire.empty()) //큐 초기화
            fire.pop();
        while(!human.empty()) //큐 초기화
            human.pop();
    }
    return 0;
}

void fireBFS(){
    queue<pii> copyFire;
    while(!fire.empty()){
        int fireI = fire.front().first;
        int fireJ = fire.front().second;
        fire.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newI = fireI + dir.at(i).first;
            int newJ = fireJ + dir.at(i).second;
            if(newI >= 0 && newJ >= 0 && newI < row && newJ < col && building[newI][newJ].first >= 0){
                building[newI][newJ] = pib(-1, true); // 불 번짐
                copyFire.push(pii(newI, newJ));
            }
        }
    }
    fire = copyFire;
}

bool humanBFS(){
    queue<pii> copyHuman;
    bool out = false; // 탈출 여부
    while(!human.empty()){
        int humanI = human.front().first;
        int humanJ = human.front().second;
        human.pop();
        building[humanI][humanJ].second = true;
        for(int i = 0 ; i < 4 ; i++){
            int newI = humanI + dir.at(i).first;
            int newJ = humanJ + dir.at(i).second;
            if(newI >= 0 && newJ >= 0 && newI < row && newJ < col){
                if(building[newI][newJ].first == 0 && building[newI][newJ].second == false){ //0은 빈공간
                    building[newI][newJ] = pib(cost, true);
                    trap = false; // 움직였다면 탈출 가능성이 있으므로 꺼준다.
                    copyHuman.push(pii(newI, newJ));
                }
            }else{ //맵 밖으로 나가면 탈출
                out = true;
            }
        }
    }
    
    human = copyHuman; //업데이트된 큐로 바꿔줌
    return out;
}

void Print(){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cout<<building[i][j].first<<'\t';
        }cout<<endl;
    }
}

