//
//  main.cpp
//  [2019 상][17140] 이차원 배열과 연산
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<vector<int> > board;

void init();
void solve();
void rFunc(); // 모든 행에 대해 정렬
void cFunc(); // 모든 열에 대해 정렬
void print();
bool compare(pair<int, int>, pair<int, int>); // 정렬을 위한 함수


int R, C, K;

int rSize = 3; //행 크기
int cSize = 3; //열 크기
int ans = INT_MAX; //map[r][c] == k 가 되는 최소 시간

int main(int argc, const char * argv[]) {
    init();
    solve();

    return 0;
}

void print(){
    for(int i = 0 ; i < rSize ; i++){
        for(int j = 0 ; j < cSize ; j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) // 등장횟수가 같으면 키가 작은 순서대로
        return a.first < b.first;
    else //등장횟수가 적은 순서대로
        return a.second < b.second;
}

void rFunc(){
    int tempCSize = 0; //가변적으로 늘어날 열의 크기
    for(int i = 0 ; i < rSize ; i++){
        map<int, int> m;
        for(int j = 0 ; j < cSize ; j++){
            if(board[i][j] == 0) // 0은 안 센다
                continue;
            bool flag = m.insert(make_pair(board[i][j], 1)).second; // insert().second 는 삽입 성공 여부
            if(!flag){
                m.find(board[i][j])->second++; // 찾았으면 갯수 증가
            }
        }
        //  연산에 의해 만들어진 새로운 열 길이 정의
        tempCSize = max(tempCSize, (int)m.size() * 2); // {key, value} 의 갯수가 크기이므로 *2 그 중 가장 큰 값에 새로운 배열을 맞춰야한다
        if(tempCSize > 100) //100이 넘어갈 경우에는 버릴거므로 무조건 100으로 설정
            tempCSize = 100;
        // 적게 나온 횟수부터 -> 키 값이 작은 수 부터
        vector<pair<int, int> > pairV (m.begin(), m.end()); //map에 있는 값을 벡터로 옮겨왔다
        sort(pairV.begin(), pairV.end(), compare); //벡터에 대한 정렬
        
        // 정렬된 pair를 벡터로 옮기기
        vector<int> tempV;
        for(int j = 0 ; j < pairV.size() ; j++){
            tempV.push_back(pairV.at(j).first);
            tempV.push_back(pairV.at(j).second);
        }
        
        // 먼저 tempV에 있는 값들을 board에 반영 (단, index가 100을 넘어가면 안 된다.
        for(int j = 0 ; j < tempV.size() && j < 100; j++){
            board[i][j] = tempV.at(j);
        }
        
        // tempV에 있는 값을 옮기고 그 뒤로는 쭉 0으로 설정
        for(int j = (int)tempV.size() ; j < 100 ; j++){
            board[i][j] = 0;
        }
    }
    // 연산이 끝난 뒤의 최종 열의 크기
    cSize = tempCSize;
    
}
void cFunc(){
    int tempRSize = 0;
    for(int j = 0 ; j <  cSize ; j++){
        map<int, int> m;
        for(int i = 0 ; i < rSize ; i++){
            if(board[i][j] == 0) // 0은 안 센다
                continue;
            bool flag = m.insert(make_pair(board[i][j], 1)).second;
            if(!flag){
                m.find(board[i][j])->second++; // 찾았으면 갯수 증가
            }
        }
        //  연산에 의해 새로운 열 길이 정의
        tempRSize = max(tempRSize, (int)m.size() * 2);
        if(tempRSize > 100)
            tempRSize = 100;
        // 적게 나온 횟수부터 -> 키 값이 작은 수 부터
        vector<pair<int, int> > pairV (m.begin(), m.end());
        sort(pairV.begin(), pairV.end(), compare);
        
        // 정렬된 pair 벡터 옮기기
        vector<int> tempV;
        for(int i = 0 ; i < pairV.size() ; i++){
            tempV.push_back(pairV.at(i).first);
            tempV.push_back(pairV.at(i).second);
        }
        
        for(int i = 0 ; i < tempV.size() && i < 100 ; i++){
            board[i][j] = tempV.at(i);
        }
        
        for(int i = (int)tempV.size() ; i < 100 ; i++){
            board[i][j] = 0;
        }
    }
    rSize = tempRSize;
}

void solve(){
    int depth = 0;
    while(board[R][C] != K && depth <= 100){
        if(rSize >= cSize)
            rFunc();
        else
            cFunc();
        //print();
        depth++;
    }
    if(depth > 100)
        cout<<-1<<endl;
    else
        cout<<depth<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>R>>C>>K;
    R--; //좌표보정
    C--; //좌표보정
    board.assign(100, vector<int>(100, 0));
    for(int i = 0 ; i < rSize ; i++){
        for(int j = 0 ; j < cSize ; j++){
            cin>>board[i][j];
        }
    }
}
