//
//  main.cpp
//  [2580] 스도쿠
//
//  Created by YOO TAEWOOK on 2020/03/22.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<int> > sudoku;
vector<pair<int, int> > emptyV;


void init();
void solve(int);
void print();
bool check();

int main(int argc, const char * argv[]) {
    init();
    if(emptyV.empty())
        print();
    solve(0);
    return 0;
}

bool check(pair<int, int> loc, int cand){
    //같은 행 같은 열 같은 박스 체크
    int row = loc.first;
    int col = loc.second;
    
    // 같은 열 검사
    for(int i = 0 ; i < 9 ; i++){
        if(sudoku[i][col] == cand)
            return false;
    }
    
    // 같은 행 검사
    for(int j = 0 ; j < 9 ; j++){
        if(sudoku[row][j] == cand)
            return false;
    }
    
    // 3x3 크기로 각기 검사
    if(row < 3){
        if(col < 3){
            for(int i = 0 ; i < 3 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }else if(col < 6){
            for(int i = 0 ; i < 3 ; i++){
                for(int j = 3 ; j < 6 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }else{
            for(int i = 0 ; i < 3 ; i++){
                for(int j = 6 ; j < 9 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }
    }else if(row < 6){
        if(col < 3){
            for(int i = 3 ; i < 6 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }else if(col < 6){
            for(int i = 3 ; i < 6 ; i++){
                for(int j = 3 ; j < 6 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }else{
            for(int i = 3 ; i < 6 ; i++){
                for(int j = 6 ; j < 9 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }
    }else{
        if(col < 3){
            for(int i = 6 ; i < 9 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }else if(col < 6){
            for(int i = 6 ; i < 9 ; i++){
                for(int j = 3 ; j < 6 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }else{
            for(int i = 6 ; i < 9 ; i++){
                for(int j = 6 ; j < 9 ; j++){
                    if(sudoku[i][j] == cand)
                        return false;
                }
            }
        }
    }
    
    return true;
}

void print(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout<<sudoku[i][j]<<" ";
        }cout<<endl;
    }
}

void solve(int depth){
    if(depth >= (int)emptyV.size()){
        print();
        exit(0); // 하나 나오면 바로 종료
    }
    
    pair<int, int> emptyLoc = emptyV.at(depth);
    for(int k = 1 ; k < 10 ; k++){ // 1~9까지 빈공간에 넣어서 가능한지 체크
        if(check(emptyLoc, k)){ // k가 빈 칸에 들어갈 수 있으면 재귀 진행
            sudoku[emptyLoc.first][emptyLoc.second] = k;
            solve(depth + 1);
            sudoku[emptyLoc.first][emptyLoc.second] = 0; // 초기화
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    sudoku.assign(9, vector<int>(9, 0));
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j] == 0) // 빈 공간 기록
                emptyV.push_back(make_pair(i, j));
        }
    }
}
