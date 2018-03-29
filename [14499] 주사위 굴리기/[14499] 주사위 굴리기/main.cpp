//
//  main.cpp
//  [14499] 주사위 굴리기
//
//  Created by YOO TAEWOOK on 2018. 3. 23..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector< pair<int, int> > dir = {make_pair(0, 1), make_pair(0, -1), make_pair(-1, 0), make_pair(1, 0)};
vector<int> command;
vector< vector<int> > map;

vector<int> dice(7, 0);
vector<int> nextDice(7, 0);

int row, col, startI, startJ, commandNum;
void move();
int main(int argc, const char * argv[]) {
    cin>>row>>col>>startI>>startJ>>commandNum;
    map.assign(row, vector<int>(col));
    command.assign(commandNum, 0);
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i = 0 ; i < commandNum ; i++){
        cin>>command[i];
        command[i]--;
    }
    nextDice = dice;
    move();
    return 0;
}

void move(){
    for(int i = 0 ; i < commandNum ; i++){
        int nextDir = command[i];
        int nextI = startI + dir.at(nextDir).first;
        int nextJ = startJ + dir.at(nextDir).second;
        if(nextI >= 0 && nextI < row && nextJ >= 0 && nextJ < col){
            if(command[i] == 0){ //동쪽
                nextDice[1] = dice[4];
                nextDice[3] = dice[1];
                nextDice[4] = dice[6];
                nextDice[6] = dice[3];
                
            }else if(command[i] == 1){ //서쪽
                nextDice[1] = dice[3];
                nextDice[3] = dice[6];
                nextDice[4] = dice[1];
                nextDice[6] = dice[4];
            }else if(command[i] == 2){ //북쪽
                nextDice[1] = dice[5];
                nextDice[5] = dice[6];
                nextDice[2] = dice[1];
                nextDice[6] = dice[2];
            }else if(command[i] == 3){ //남쪽
                nextDice[1] = dice[2];
                nextDice[2] = dice[6];
                nextDice[5] = dice[1];
                nextDice[6] = dice[5];
            }
            if(map[nextI][nextJ] == 0){
                map[nextI][nextJ] = nextDice[6];
            }else{
                nextDice[6] = map[nextI][nextJ];
                map[nextI][nextJ] = 0;
            }
            cout<<nextDice[1]<<endl;
            dice = nextDice;
            startI = nextI;
            startJ = nextJ;
        }
    }
}
