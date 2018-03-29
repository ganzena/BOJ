//
//  main.cpp
//  [1726] 로봇
//
//  Created by YOO TAEWOOK on 2018. 3. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
vector<pii> dir = {pii(0, 1), pii(0, -1), pii(1, 0),pii(-1, 0)}; // 동쪽이 0, 서쪽이 1, 남쪽이 2, 북쪽이 3
vector< vector<pii> > factory;
vector< vector<bool> > visit;
int row, col, startI, startJ, startDir, endI, endJ, endDir, curDir, cost = 0;
void Move();
int turnLeft(int);
int turnRight(int);
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    factory.assign(row, vector<pii>(col, pii(0, 0)));
    visit.assign(row, vector<bool>(col, 0));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>factory[i][j].first;
            if(factory[i][j].first == 1)
                visit[i][j] = true;
        }
    }

    cin>>startI>>startJ>>startDir;
    cin>>endI>>endJ>>endDir;
    startI--;
    startJ--;
    endI--;
    endJ--;
    startDir--;
    endDir--;
    curDir = startDir;
    Move();
    cout<<factory[endI][endJ].first<<endl;
    return 0;
}

void Move(){
    queue<tiii> robotQ;
    robotQ.push(tiii(startI, startJ, startDir));
    visit[startI][startJ] = true;
    while(!robotQ.empty()){
        int startI = get<0>(robotQ.front());
        int startJ = get<1>(robotQ.front());
        int startDir = get<2>(robotQ.front());
        visit[startI][startJ] = true;
        robotQ.pop();
        int leftDir = turnLeft(startDir);
        int rightDir = turnRight(startDir);
        printf("%d, %d, %d", startI, startJ, startDir);
        if(startI == endI && startJ == endJ && startDir == endDir){
            break;
        }
        else{// go 1 or 2 or 3
        int copyI = startI;
        int copyJ = startJ;
        int i;
        for(i = 0 ; i < 3 ; i++){
            int newI = startI + dir.at(startDir).first;
            int newJ = startJ + dir.at(startDir).second;
            if(newI >= 0 && newJ >= 0 && newI < row && newJ < col && visit[newI][newJ] == false){
                visit[newI][newJ] = true;
                factory[newI][newJ].first = factory[copyI][copyJ].first + 1;
                startI = newI;
                startJ = newJ;
                if(startI == endI && startJ == endJ){
                    i++;
                    break;
                }
                
                //continue;
            }else
                break;
        }
        if(i > 0){
            robotQ.push(tiii(startI, startJ, startDir));
            //cost++;
        }
        
        if(factory[copyI][copyJ].second < 4){
            if(factory[copyI][copyJ].second < 3){
                
                factory[copyI][copyJ].second++;
                factory[copyI][copyJ].first++;
                robotQ.push(tiii(copyI, copyJ, leftDir));
            }else{
                
                factory[copyI][copyJ].second++;
                factory[copyI][copyJ].first--;
                robotQ.push(tiii(copyI, copyJ, leftDir));
            }
        }
        
        cout<<endl;
//        cout<<"("<<factory[3][1].first<<", "<<factory[3][1].second<<")"<<endl;;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                cout<<"("<<factory[i][j].first<<", "<<factory[i][j].second<<")"<<'\t';
            }cout<<endl;
        }
        }
    }
}

int turnLeft(int curDir){
    if(curDir == 0)
        return 3;
    else if(curDir == 1)
        return 2;
    else if(curDir == 2)
        return 0;
    else
        return 1;
}

int turnRight(int curDir){
    if(curDir == 0)
        return 2;
    else if(curDir == 1)
        return 3;
    else if(curDir == 2)
        return 1;
    else
        return 0;
}

