//
//  main.cpp
//  [1018] 체스판 다시 칠하기
//
//  Created by YOO TAEWOOK on 2018. 3. 9..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX_CHESS_BOARD_SIZE 50
#define CHESS_BOARD_SIZE 8

using namespace std;

vector< vector<char> > chessBoard(MAX_CHESS_BOARD_SIZE, vector<char>(MAX_CHESS_BOARD_SIZE));
vector< vector<char> > cuttedBoard(CHESS_BOARD_SIZE, vector<char>(CHESS_BOARD_SIZE));
vector< vector<char> > blackBoard(CHESS_BOARD_SIZE, vector<char>(CHESS_BOARD_SIZE));
vector< vector<char> > whiteBoard(CHESS_BOARD_SIZE, vector<char>(CHESS_BOARD_SIZE));
const char BLACK = 'B';
const char WHITE = 'W';

void cutBoard(int, int);
int compareBoard();
void perpectChessBoard();
int MIN = 64;

int main(int argc, const char * argv[]) {
    int row, col;
    cin>>row>>col;
    
    for(int i = 0 ; i < row ; i++){ //체스판 입력
        for(int j = 0 ; j < col ; j++){
            cin>>chessBoard[i][j];
        }
    }
    
    perpectChessBoard();
    
    for(int i = 0 ; i <= row - CHESS_BOARD_SIZE ; i++){
        for(int j = 0 ; j <= col - CHESS_BOARD_SIZE ; j++){
            cutBoard(i, j); // 입력받은 판에서 체스판 사이즈로 잘라냄
            int counter = compareBoard();
            if(MIN > counter)
                MIN = counter; //최솟값 갱신
        }
    }
    
    cout<<MIN<<endl;
    return 0;
}

int compareBoard(){ // 흰색부터 시작하는 체스판과 검은색부터 시작하는 체스판과의 비교
    int whiteCounter = 0, blackCounter = 0;
    for(int i = 0 ; i < CHESS_BOARD_SIZE ; i++){
        for(int j = 0 ; j < CHESS_BOARD_SIZE ; j++){
            if(cuttedBoard[i][j] != whiteBoard[i][j])
                whiteCounter++;
            if(cuttedBoard[i][j] != blackBoard[i][j])
                blackCounter++;
        }
    }
    
    return (whiteCounter < blackCounter ? whiteCounter : blackCounter); // 그 중 더 적은 비용의 counter를 리턴
}

void cutBoard(int x, int y){
    for(int i = x ; i < x + CHESS_BOARD_SIZE ; i++){
        for(int j = y ; j < y + CHESS_BOARD_SIZE ; j++){
            cuttedBoard[i - x][j - y] = chessBoard[i][j];
        }
    }
}

void perpectChessBoard(){ //완벽한 체스판을 만든다.
    for(int i = 0 ; i < CHESS_BOARD_SIZE ; i++){
        char start, other;
        if(i % 2 == 0){ //i가 0을 포함한 짝수일 경우 시작색은 검은색
            blackBoard[i][0] = BLACK;
            start = BLACK;
            other = WHITE;
        }else{ //아닐시 시작색은 흰색
            blackBoard[i][0] = WHITE;
            start = WHITE;
            other = BLACK;
        }
        
        for(int j = 0 ; j < CHESS_BOARD_SIZE ; j++){
            if(j % 2 == 0){ // 열에 접근할 때 각각 검흰을 칠함
                blackBoard[i][j] = start;
            }else{
                blackBoard[i][j] = other;
            }
        }
    }
    
    for(int i = 0 ; i < CHESS_BOARD_SIZE ; i++){ //마찬가지
        char start, other;
        if(i % 2 == 0){
            whiteBoard[i][0] = WHITE;
            start = WHITE;
            other = BLACK;
        }else{
            whiteBoard[i][0] = BLACK;
            start = BLACK;
            other = WHITE;
        }
        
        for(int j = 0 ; j <CHESS_BOARD_SIZE ; j++){
            if(j % 2 == 0){
                whiteBoard[i][j] = start;
            }else{
                whiteBoard[i][j] = other;
            }
        }
    }
}
