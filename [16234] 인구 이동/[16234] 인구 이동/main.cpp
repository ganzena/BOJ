//
//  main.cpp
//  [16234] 인구 이동
//
//  Created by YOO TAEWOOK on 28/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
int counter = 0;
int unitedNum = 0;

vector<vector<int>> map;
vector<vector<int>> united;
vector<int> unionSum;
vector<int> unionNum;
vector<pair<int, int>> dir = {pair<int, int>(0, -1), pair<int, int>(0, 1), pair<int, int>(1, 0), pair<int, int>(-1, 0)};

void init();
void BFS();

int main(int argc, const char * argv[]) {
    init();
    BFS();
    cout<<counter<<endl;
    return 0;
}

void BFS(){
    while(1){
        united.assign(N, vector<int>(N, -1));
        unionNum.assign(N*N, 0);
        unionSum.assign(N*N, 0);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(united[i][j] == -1){
                    united[i][j] = unitedNum;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    int sum = map[i][j];
                    unionNum[unitedNum] = 1;
                    while(!q.empty()){
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            pair<int, int> next = make_pair(now.first + dir.at(k).first, now.second + dir.at(k).second);
                            
                            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N){
                                continue;
                            }
                            
                            if(united[next.first][next.second] == -1){
                                int gap = abs(map[next.first][next.second] - map[now.first][now.second]);
                                if(gap <= R && gap >= L){
                                    united[next.first][next.second] = unitedNum;
                                    sum += map[next.first][next.second];
                                    unionNum[unitedNum]++;
                                    q.push(next);
                                }
                            }
                        }
                    }
                    unionSum[unitedNum] = sum;
                    unitedNum++;
                }
            }
        }
        if(unitedNum == (N * N)){
            break;
        }
        unitedNum = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                int num = united[i][j];
                int newNum = unionSum[num] / unionNum[num];
                map[i][j] = newNum;
            }
        }
        counter++;
    }
}

void init(){
    cin>>N>>L>>R;
    map.assign(N, vector<int>(N, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }
}
