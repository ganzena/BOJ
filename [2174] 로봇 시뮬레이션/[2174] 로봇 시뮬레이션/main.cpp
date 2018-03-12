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

vector<pair<int, int>> direction = {pair<int, int>(-1, 0), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(0, 1)};

class Robot{
private:
    int robotNo;
    int curDir; // NORTH = 0, WEST = 1, SOUTH = 2, EAST = 3
    int curX;
    int curY;
    
public:
    Robot(int robotNo = NULL, int curDir = NULL, int curX = NULL, int curY = NULL){
        this->robotNo = robotNo;
        this->curDir = curDir;
        this->curX = curX;
        this->curY = curY;
    }
    
    int getRobotNo(){
        return this->robotNo;
    }
    
    void setCurDir(int dir){
        this->curDir = dir;
    }
    
    int getCurDir(){
        return this->curDir;
    }
    
    int getCurX(){
        return this->curX;
    }
    
    int getCurY(){
        return this->curY;
    }
    
    void setCurX(int curX){
        this->curX = curX;
    }
    
    void setCurY(int curY){
        this->curY = curY;
    }
    
};

int dirToInt(char);
void rotateLeft(Robot *);
void rotateRight(Robot *);
vector<Robot*> robotVector(101);
int row, col;
int main(int argc, const char * argv[]) {
    
    cin>>col>>row; // 공간의 row, col 행 4 열 5
    vector< vector<Robot*> > space(row, vector<Robot*>(col, NULL));
    int robotNum, cmdNum;
    cin>>robotNum>>cmdNum;
    int serialNo = 1;
    
    while(robotNum--){ //로봇 초기설정
        int locX, locY;
        char dir;
        cin>>locY>>locX>>dir; //열 행 방향
        int dirInt = dirToInt(dir);
        locX = row - locX;
        locY--;
        Robot* robot = new Robot(serialNo, dirInt, locX, locY);
        space[locX][locY] = robot;
        robotVector[serialNo] = robot;
        serialNo++;
    }
    
    while(cmdNum--){
        int robotNo, runNum;
        char cmd;
        cin>>robotNo>>cmd>>runNum;
        Robot* robot = robotVector[robotNo];

        
        while(runNum--){
            if(cmd == 'L'){

                rotateLeft(robot);
            }else if(cmd == 'R'){
//                int x = robot.getCurX();
//                int y = robot.getCurY();
                rotateRight(robot);
            }else if(cmd == 'F'){
                int x = robot->getCurX();
                int y = robot->getCurY();
                int newX = x + direction.at(robot->getCurDir()).first;
                int newY = y + direction.at(robot->getCurDir()).second;
                if(newX >= 0 && newX < row && newY >= 0 && newY < col){
                    if(space[newX][newY]->getRobotNo()){
                        robot->setCurX(newX);
                        robot->setCurY(newY);
                        space[newX][newY] = robot;
                        space[x][y] = NULL;
                    }else{
                        cout<<"Robot " << robot->getRobotNo()<<" crashes into robot "<<space[newX][newY]->getRobotNo()<<endl;
                        return 0;
                    }
                }else{
                    cout<<"Robot "<<robot->getRobotNo()<<" crashes into the wall"<<endl;
                    return 0;
                }
            }
        }
        
    }
    
    
    cout<<"OK"<<endl;
    
    return 0;
}

int dirToInt(char dir){
    if(dir == 'N'){
        return 0;
    }else if(dir == 'W'){
        return 1;
    }else if(dir == 'S'){
        return 2;
    }else{
        return 3;
    }
}

void rotateLeft(Robot* robot){
    robot->setCurDir((robot->getCurDir() + 1) % 4);
}

void rotateRight(Robot* robot){
    if(robot->getCurDir() == 0){
        robot->setCurDir(3);
    }else{
        robot->setCurDir((robot->getCurDir() - 1) % 4);
    }
}


