//
//  main.cpp
//  [12100] 2048 (Easy)
//
//  Created by YOO TAEWOOK on 2018. 3. 30..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void move(vector< vector<int> >&, int, bool);
int board_size;
int maximum = 0;

int main(int argc, const char * argv[]) {
    cin>>board_size;
    vector< vector<int> > board(board_size, vector<int>(board_size));
    for(int i = 0 ; i < board_size ; i++){
        for(int j = 0 ; j < board_size ; j++){
            cin>>board[i][j];
        }
    }
    
    move(board, 0, true);
    
    cout<<maximum<<endl;
    
    return 0;
}

void move(vector< vector<int> >& board, int depth, bool isMoved){
    
    if(!isMoved || depth == 5){ // 5번을 가지 못하거나 5번을 갔을 때 return
        for(int i = 0 ; i < board_size ; i++){
            for(int j = 0 ; j < board_size ; j++){
                if(board[i][j] > maximum){
                    maximum = board[i][j];
                }
            }
        }
        return;
    }
    
    vector< vector<int> > tempBoard; // 원본 board를 복사함
    vector< vector<bool> > updated; // visited 개념 한 번 값이 더해진 곳은 더 이상 건들지 않는다.
    isMoved = false; // 5번 가기전에 움직이지 못하는 상태가 있는지 체크
    for(int dir = 0 ; dir < 4 ; dir++){
        tempBoard = board;
        updated.assign(board_size, vector<bool>(board_size, false));
        if(dir == 0){ //WEST 0 2 0 2
            for(int i = 0 ; i < board_size ; i++){ //행
                for(int j = 1 ; j < board_size ; j++){ //열
                    for(int k = 0 ; k < j ; k++){ //열
                        if(tempBoard[i][j] == 0) //0은 이동 안하니까 continue
                            continue;
                        if(!updated[i][k]){ // 업데이트 된 적이 없다면
                            if(tempBoard[i][k] == tempBoard[i][j]){ // 기준 인덱스에 있는 값과 비교되는 인덱스에 있는 값이 같을때
                                bool canUpdate = true;
                                for(int s = j - 1 ; s > k ; s--){ // 중간에 다른 숫자가 있어서 덧셈을 위한 이동이 가능한지 체크
                                    if(tempBoard[i][s] != 0)
                                        canUpdate = false;
                                }
                                if(canUpdate){ //업데이트 할 때, 변경이 있었다(isMoved = true) 업데이트 되어 더 이상 수정하지 않는다(updated[i][k] = true)를 체크
                                    tempBoard[i][k] += tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                    updated[i][k] = true;
                                }
                            } else if(tempBoard[i][k] == 0){
                                if(tempBoard[i][j] != 0){
                                    tempBoard[i][k] = tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                }
                            }
                        }
                    }
                }
            }
        } else if(dir == 1){ //EAST
            for(int i = 0 ; i < board_size ; i++){ //행
                for(int j = board_size - 2 ; j >= 0 ; j--){//열
                    for(int k = board_size - 1 ; k > j ; k--){
                        if(tempBoard[i][j] == 0)
                            continue;
                        if(!updated[i][k]){
                            if(tempBoard[i][k] == tempBoard[i][j]){
                                bool canUpdate = true;
                                for(int s = j + 1 ; s < k ; s++){
                                    if(tempBoard[i][s] != 0)
                                        canUpdate = false;
                                }
                                if(canUpdate){
                                    tempBoard[i][k] += tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                    updated[i][k] = true;
                                }
                            }else if(tempBoard[i][k] == 0){
                                if(tempBoard[i][j] != 0){
                                    tempBoard[i][k] = tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                }
                            }
                        }
                    }
                }
            }
        } else if(dir == 2){//SOUTH
            for(int j = 0; j < board_size ; j++){ //열
                for(int i = board_size - 2; i >= 0; i--){ //행
                    for(int k = board_size - 1; k > i ; k--){ //행
                        if(tempBoard[i][j] == 0)
                            continue;
                        if(!updated[k][j]){
                            if(tempBoard[k][j] == tempBoard[i][j]){
                                bool canUpdate = true;
                                for(int s = i + 1 ; s < k ; s++){
                                    if(tempBoard[s][j] != 0)
                                        canUpdate = false;
                                }
                                if(canUpdate){
                                    tempBoard[k][j] += tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                    updated[k][j] = true;
                                }
                            }else if(tempBoard[k][j] == 0){
                                if(tempBoard[i][j] != 0){
                                    tempBoard[k][j] = tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                }
                            }
                        }
                    }
                }
            }
        } else if(dir == 3){ //NORTH
            for(int j = 0 ; j < board_size ; j++){ //열
                for(int i = 1 ; i < board_size ; i++){ //행
                    for(int k = 0 ; k < i ; k++){ //행
                        if(!updated[k][j]){
                            if(tempBoard[i][j] == 0)
                                continue;
                            if(tempBoard[k][j] == tempBoard[i][j]){
                                bool canUpdate = true;
                                for(int s = i - 1 ; s > k ; s--){
                                    if(tempBoard[s][j] != 0)
                                        canUpdate = false;
                                }
                                if(canUpdate){
                                    tempBoard[k][j] += tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                    updated[k][j] = true;
                                }
                            }else if(tempBoard[k][j] == 0){
                                if(tempBoard[i][j] != 0){
                                    tempBoard[k][j] = tempBoard[i][j];
                                    tempBoard[i][j] = 0;
                                    isMoved = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        move(tempBoard, depth + 1, isMoved);
    }
}

