//
//  main.cpp
//  [14891] 톱니바퀴
//
//  Created by YOO TAEWOOK on 2018. 3. 13..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//
// N극은 0, S극은 1

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector< deque<int> > topni(5);
vector< vector<int> > initVec(5, vector<int>(8));
vector<int> rotation(5);
void dequeInit();
void printScore();
void rotateClock(int);
void rotateReverse(int);
void setRotation(int, int);
void doRotation();

int main(int argc, const char * argv[]) {
    
    for(int i = 1 ; i < 5 ; i++){
        string input;
        cin>>input;
        for(int j = 0 ; j < 8 ; j++){
            int temp = input.at(j);
            temp -= 48;
            topni.at(i).push_back(temp);
        }
    }

    int runNum;
    cin>>runNum;
    while(runNum--){
        int topniNum, direction;
        cin>>topniNum>>direction;

        setRotation(topniNum, direction);
        doRotation();
        rotation.assign(5, 0);
    }
    
    printScore();

    return 0;
}

void rotateClock(int topniNum){
    int temp = topni.at(topniNum).back();
    topni.at(topniNum).pop_back();
    topni.at(topniNum).push_front(temp);
}

void rotateReverse(int topniNum){
    int temp = topni.at(topniNum).front();
    topni.at(topniNum).pop_front();
    topni.at(topniNum).push_back(temp);
}

void printScore(){
    int score = 0;
    for(int i = 1 ; i < 5 ; i++){
        if(topni.at(i).front() == 1){ // 1이 S극
            if(i == 1){
                score += 1;
            }else if(i == 2){
                score += 2;
            }else if(i == 3){
                score += 4;
            }else if(i == 4){
                score += 8;
            }
        }
    }
    
    cout<<score<<endl;
}

void setRotation(int topniNum, int direction){
    int temp = direction;
    rotation[topniNum] = direction;
    for(int i = topniNum ; i > 1 ; i--){
        if(topni.at(i).at(6) != topni.at(i - 1).at(2)){
            if(rotation[i] != 0){
                rotation[i - 1] = temp * -1;
                temp *= -1;
            }
        }else{
            rotation[i - 1] = 0;
        }
    }
    temp = direction;
    for(int i = topniNum ; i < 4 ; i++){
        if(topni.at(i).at(2) != topni.at(i + 1).at(6)){
            if(rotation[i] != 0){
                rotation[i + 1] = temp * -1;
                temp *= -1;
            }
        }else{
            rotation[i + 1] = 0;
        }
    }
}

void doRotation(){
    for(int i = 1 ; i < rotation.size() ; i++){
        if(rotation.at(i) == 1){
            rotateClock(i);
        }else if(rotation.at(i) == -1){
            rotateReverse(i);
        }
    }
}
