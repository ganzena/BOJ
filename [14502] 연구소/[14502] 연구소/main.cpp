//
//  main.cpp
//  [14502] 연구소
//
//  Created by YOO TAEWOOK on 2018. 3. 20..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > lab;
vector< vector<bool> > infested;
vector< vector<int> > buildCompleted;
vector< pair<int, int> > direction = {pair<int, int>(1, 0), pair<int, int>(-1, 0), pair<int, int>(0, 1), pair<int, int>(0, -1)};
void buildWall(int);
void letSpread(int, int);

int row, col;
int maximum = 0;
int main(int argc, const char * argv[]) {
    
    cin>>row>>col;
    
    lab.assign(row, vector<int>(col));
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>lab[i][j];
        }
    }

    buildWall(0);
    // 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다
    // 벽은 3개를 세울 수 있다.
    
    cout<<maximum<<endl;
    return 0;
}

void buildWall(int depth){
    if(depth == 3){
        infested.assign(row, vector<bool>(col, false));
        buildCompleted = lab; //벽이 지어진 연구소를 buildCompleted에 저장
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(lab[i][j] == 2 && infested[i][j] == false){ //연구소에 있는 바이러스에서 퍼져나가기 시작
                    letSpread(i, j);
                }
            }
        }
        int counter = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(buildCompleted[i][j] == 0) // 바이러스가 안 퍼진 곳을 검사한다.
                    counter++;
            }
        }

        maximum = max(maximum, counter);
        return;
    }
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(lab[i][j] == 0){
                lab[i][j] = 1; // 벽 세운다
                buildWall(depth + 1);
                lab[i][j] = 0; // 재귀 끝나면 벽을 허문다
            }
            
        }
    }
}

void letSpread(int startI, int startJ){ //퍼질 곳이 없으면 알아서 멈출것임 BFS로 짰어도 될듯
    buildCompleted[startI][startJ] = 2;
    infested[startI][startJ] = true;
    for(int i = 0 ; i < 4 ; i++){
        int newI = startI + direction.at(i).first;
        int newJ = startJ + direction.at(i).second;
        if(newI >= 0 && newI < row && newJ >= 0 && newJ < col && infested[newI][newJ] == false && buildCompleted[newI][newJ] == 0){
            letSpread(newI, newJ);
        }
    }
}
