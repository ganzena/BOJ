//
//  main.cpp
//  [14500] 테트로미노
//
//  Created by YOO TAEWOOK on 2018. 3. 14..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> direction = {pair<int, int>(1, 0), pair<int, int>(0, 1), pair<int, int>(-1, 0), pair<int, int>(0, -1)}; // NORTH EAST SOUTH WEST
vector< vector<int> > board;
vector<int> sumVector(4); // 테트로미노 합을 구하기 위한 합벡터
vector< vector<bool> > visited;

int maximum = 0;

void search(int, int, int);
void vertical(int, int);
void horizontal(int, int);

int row, col;
int main(int argc, const char * argv[]) {
    
    cin>>row>>col;
    board.assign(row, vector<int>(col)); // 종이 초기화
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>board[i][j];
        }
    }
    visited.assign(row, vector<bool>(col, false));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            sumVector[0] = board[i][j]; //합벡터.at(0)은 시작점
            search(i, j, 1); //depth 1부터 시작
            vertical(i, j); // ㅓ ㅏ 찾기
            horizontal(i, j); // ㅗ ㅜ 찾기
        }
    }
    
    cout<<maximum<<endl;
    return 0;
}

void vertical(int i, int j){
    int left = 0, right = 0;
    if(i + 2 < row){
        if(j - 1 >= 0){ // ㅓ
            left = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
        }
        if(j + 1 < col){ // ㅏ
            right = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
        }
    }
    
    int temp = max(left, right);
    maximum = max(temp, maximum);
}

void horizontal(int i, int j){
    int up = 0, down = 0;
    if(j + 2 < col){
        if(i - 1 >= 0){ // ㅗ
            up = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1];
        }
        
        if(i + 1 < row){ // ㅜ
            down = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
        }
    }
    
    int temp = max(up, down);
    maximum = max(temp, maximum);
    
}

void search(int startI, int startJ, int depth){
    
    if(depth == 4){
        int compare = 0;
        for(int i = 0 ; i < 4 ; i++){
            compare += sumVector[i];
        }
        
        maximum = max(maximum, compare);
        return;
    }
    
    visited[startI][startJ] = true;
    
    for(int k = 0 ; k < 4 ; k++){
        int neighborI = startI + direction.at(k).first;
        int neighborJ = startJ + direction.at(k).second;
        if(neighborI >= 0 && neighborI < row && neighborJ >= 0 && neighborJ < col){
            if(!visited[neighborI][neighborJ]){
                sumVector[depth] = board[neighborI][neighborJ];
                search(neighborI, neighborJ, depth + 1);
            }
        }
    }
    
    visited[startI][startJ] = false;
}

