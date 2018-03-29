//
//  main.cpp
//  [3197] 백조의 호수
//
//  Created by YOO TAEWOOK on 2018. 3. 28..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, bool> pib;
vector< vector<pib> > lake;
vector< vector<pib> > initLake; //호수를 원상복구시키기위함
vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};
queue<pii> swan; //백조가 있는 위치
queue<pii> water; //물이 있는 위치

int row, col, startI, startJ, endI, endJ, counter = 0, dayCounter = 0, result = 0;
int minMelt = 0, maxMelt, midMelt;
bool BFS(); // 첫번째 백초와 두번째 백조가 만날 수 있는지 확인한다.
void lakeSet(int); // 해당 일을 포함하여 이전 날들에 녹았어야할 빙산들을 녹인다.
void swanInit(); // 첫번째 백조와 두번째 백조를 지정한다.
void countDay(); // 모든 빙산이 녹는 일수를 구한다.
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    lake.assign(row, vector<pib>(col, pib(0, false))); //first = swan ice water second = visit
    string str;
    for(int i = 0 ; i < row ; i++){
        cin>>str;
        for(int j = 0 ; j < col ; j++){
            if(str.at(j) == 'L'){ //백조
                swan.push(pii(i, j));
                water.push(pii(i, j)); //백조가 있는 곳도 물이 있으므로 물 큐에 넣는다.
                lake[i][j].first = -2;
            }else if(str.at(j) == '.'){ //물
                water.push(pii(i, j));
                lake[i][j].first = 0;
            }else if(str.at(j) == 'X'){ //얼음
                lake[i][j].first = -1;
                lake[i][j].second = true;
            }
        }
    }
    swanInit();

    while(1){
        if(water.empty())
            break;
        dayCounter++;
        countDay();
    }
    dayCounter--;

    maxMelt = dayCounter;
    while(minMelt <= maxMelt){
        midMelt = (maxMelt + minMelt)/2;
        initLake = lake;
        lakeSet(midMelt);
        if(BFS()){ //true면
            maxMelt = midMelt - 1;
        }else{
            minMelt = midMelt + 1;
        }
        lake = initLake;
    }
    result = minMelt;
    cout<<result<<endl;
    return 0;
}

void lakeSet(int base){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(lake[i][j].first > 0 && lake[i][j].first <= base){
                lake[i][j].first = 0;
                lake[i][j].second = false;
            }
        }
    }
}

bool BFS(){
    queue<pii> swanMove;
    swanMove.push(pii(startI, startJ));
    lake[startI][startJ].second = true;
    while(!swanMove.empty()){
        int initI = swanMove.front().first;
        int initJ = swanMove.front().second;
        swanMove.pop();
        if(initI == endI && initJ == endJ)
            return true;
        for(int i = 0 ; i < 4 ; i++){
            int newI = initI + dir.at(i).first;
            int newJ = initJ + dir.at(i).second;
            if(newI >= 0 && newJ >= 0 && newI < row && newJ < col && lake[newI][newJ].second == false && lake[newI][newJ].first < 1){
                lake[newI][newJ].second = true;
                swanMove.push(pii(newI, newJ));
            }
        }
    }
    return false;
}
void countDay(){
    queue<pii> copyWater;
    while(!water.empty()){
        int waterI = water.front().first;
        int waterJ = water.front().second;
        water.pop();
        for(int j = 0 ; j < 4 ; j++){
            int newI = waterI + dir.at(j).first;
            int newJ = waterJ + dir.at(j).second;
            if(newI >= 0 && newJ >= 0 && newI < row && newJ < col && lake[newI][newJ].first == -1){
                    lake[newI][newJ].first = dayCounter;
                copyWater.push(pii(newI, newJ));
            }
        }
    }
    water = copyWater;
}

void swanInit(){
    startI = swan.front().first;
    startJ = swan.front().second;
    swan.pop();
    endI = swan.front().first;
    endJ = swan.front().second;
}

