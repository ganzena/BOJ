//
//  main.cpp
//  [2174] 로봇 시뮬레이션
//
//  Created by YOO TAEWOOK on 2018. 3. 9..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_ROBOT 100
#define MAX_SPACE_SIZE 100
using namespace std;

vector< pair<int, int> > direction = {pair<int, int>(-1, 0), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(0, 1)}; //N W S E
vector< vector< pair<int, int> > > map;

int MAX_ROW;
int MAX_COL;

int dirToInt(char);
int turnLeft(int);
int turnRight(int);

int main(int argc, const char * argv[]) {
    cin>>MAX_COL>>MAX_ROW;
    map.assign(MAX_ROW, vector< pair<int, int> >(MAX_COL, pair<int, int>(0, -1)));
    int robotNum, cmdNum;
    int serialNo = 1;
    cin>>robotNum>>cmdNum;
    
    while(robotNum--){
        int curX, curY, curDir;
        char initDir;
        cin>>curY>>curX>>initDir;
        curY -= 1;
        curX = MAX_ROW - curX;
        curDir = dirToInt(initDir);
        map[curX][curY].first = serialNo;
        map[curX][curY].second = curDir;
        serialNo++;
    }
    
    while(cmdNum--){
        int robotNo, cmdTime;
        char cmd;
        cin>>robotNo>>cmd>>cmdTime;
        int targetI = 0, targetJ = 0;
        bool isBroken = false;
        for(int i = 0 ; i < MAX_ROW ; i++){
            for(int j = 0 ; j < MAX_COL ; j++){
                if(map[i][j].first == robotNo){
                    targetI = i;
                    targetJ = j;
                    isBroken = true;
                    break;
                }
            }
            if(isBroken)
                break;
        }
        
        for(int i = 0 ; i < cmdTime ; i++){
            if(cmd == 'L'){
                map[targetI][targetJ].second = turnLeft(map[targetI][targetJ].second);
            } else if(cmd == 'R'){
                map[targetI][targetJ].second = turnRight(map[targetI][targetJ].second);
            } else if(cmd == 'F'){
                int curDir = map[targetI][targetJ].second;
                int newI = targetI + direction[curDir].first;
                int newJ = targetJ + direction[curDir].second;
                if(newI >= 0 && newI < MAX_ROW && newJ >= 0 && newJ < MAX_COL){
                    if(map[newI][newJ].first != 0){
                        cout<< "Robot " << map[targetI][targetJ].first << " crashes into robot " <<map[newI][newJ].first<<endl;
                        return 0;
                    }else{
                        map[newI][newJ].first = map[targetI][targetJ].first;
                        map[newI][newJ].second = map[targetI][targetJ].second;
                        map[targetI][targetJ].first = 0;
                        map[targetI][targetJ].second = -1;
                        targetI = newI;
                        targetJ = newJ;
                    }
                }else{
                    cout<<"Robot "<< map[targetI][targetJ].first <<" crashes into the wall "<<endl;
                    return 0;
                }
            }
        }
    }
    
    cout<<"OK"<<endl;
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

int dirToInt(char initDir){
    switch (initDir) {
        case 'N':
            return 0;
        case 'W':
            return 1;
        case 'S':
            return 2;
        case 'E':
            return 3;
    }
    
    return -1;
}
