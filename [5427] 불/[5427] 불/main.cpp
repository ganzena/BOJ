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
void print();
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
                    isFire = true;
                    building[i][j] = pib(-1, true);
                    fire.push(pii(i, j));
                }else if(str.at(j) == '@'){
                    human.push(pii(i, j));
                }
            }
        }
        while(1){
            if(isFire)
                fireBFS();
            if(humanBFS()){
                cout<<cost<<endl;
                break;
            }
            if(trap){
                cout<<"IMPOSSIBLE"<<endl;
                break;
            }
            trap = true;
            cost++;
        }
        trap = true;
        cost = 1;
        while(!fire.empty())
            fire.pop();
        while(!human.empty())
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
    bool out = false;
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
                    trap = false;
                    copyHuman.push(pii(newI, newJ));
                }
            }else{
                out = true;
            }
        }
    }
    
    human = copyHuman;
    return out;
}

