//
//  main.cpp
//  [모의 SW 역량테스트] 홈 방범 서비스
//
//  Created by YOO TAEWOOK on 2018. 4. 11..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
vector< vector<int> > town;
vector< vector<bool> > visited;
vector<int> price;
vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};

int test, townSize, money, maximum = 0;
void BFS(int, int, int);
void print();
int main(int argc, const char * argv[]) {
    cin>>test;
    int cnt = 0;
    price.assign(MAX + 2, 0);
    for(int i = 1 ; i < MAX + 2 ; i++){ //커버 영역에 따른 가격표 작성
        price[i] = i * i + (i - 1) * (i - 1);
    }
    while(cnt < test){
        cin>>townSize>>money;
        town.assign(townSize, vector<int>(townSize));
        visited.assign(townSize, vector<bool>(townSize, false));
        for(int i = 0 ; i < townSize ; i++){
            for(int j = 0 ; j < townSize ; j++){
                cin>>town[i][j]; //1 은 집
            }
        }
        for(int i = 0 ; i < townSize ; i++){
            for(int j = 0 ; j < townSize ; j++){

                BFS(i, j, 1);
//                cout<<endl;
//                print();
                visited.assign(townSize, vector<bool>(townSize, false));
            }
        }

        cnt++;
        cout<<"#"<<cnt<<" "<<maximum<<endl;
        maximum = 0;
        
    }
    return 0;
}

void BFS(int I, int J, int k){
    queue<piii> q;
    q.push(piii(pii(I, J), k));
    visited[I][J] = true;
    int houseNum = 0;
    int cover = k;
    if(town[I][J] == 1)
        houseNum++;
    if(houseNum * money - price[cover] >= 0){ //커버영역(K)가 1일 때를 고려 안했었음
        maximum = max(houseNum, maximum);
    }
    while(!q.empty()){
        int startI = q.front().first.first;
        int startJ = q.front().first.second;
        if(cover != q.front().second){ //커버 단위가 갱신될때
            cover = q.front().second;
            if(cover == townSize + 2){
                break;
            }
            if(houseNum * money - price[cover] >= 0){
                maximum = max(houseNum, maximum);
            }
        }
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int newI = startI + dir.at(i).first;
            int newJ = startJ + dir.at(i).second;
            if(newI >= 0 && newJ >= 0 && newI < townSize && newJ < townSize){
                if(visited[newI][newJ] == false){
                    visited[newI][newJ] = true;
                    if(town[newI][newJ] == 1){
                        houseNum++;
                    }
                    q.push(piii(pii(newI, newJ), cover + 1));
                }
            }
        }
    }

}

void print(){
    for(int i = 0 ; i < townSize ; i++){
        for(int j = 0 ; j < townSize ; j++){
            cout<<visited[i][j]<<" ";
        }cout<<endl;
    }
}
