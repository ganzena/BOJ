//
//  main.cpp
//  [2019 상][17142] 연구소 3
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 0 : empty / 1 : wall / 2 : virus
// -4 : empty / -1 : wall / -2 : virus(de-activate) / -3 : virus(activate)
using namespace std;

int N,M;
int minTime = 2000;
vector<vector<int> > map;
vector<vector<int> > copyMap;
vector<vector<bool> > visited;
vector<pair<int, int> > loc;
vector<pair<int, int> > temp;
vector<pair<int, int> > dir;


void init();
void combi(int, int);
void spread();
void check();
void answer();

int main(int argc, const char * argv[]) {
    init();
    combi(0, 0);
    answer();
    return 0;
}

void answer(){
    if(minTime == 2000){
        cout<< -1 <<endl;
    }else{
        cout<< minTime <<endl;
    }
}

void check(){
    int maxTime = 0;
    visited.assign(N, vector<bool>(N, false));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(copyMap[i][j] == -4){
                return;
            }
            maxTime = max(maxTime, copyMap[i][j]);
        }
    }
    minTime = min(minTime, maxTime);
}

void spread(){
    copyMap = map; // 항상 새로운 맵에서 하기 위해 다른 맵을 씀
    queue<pair<int, int> > locQ;
    vector<vector<int> > history; // 비활성화 바이러스가 활성화 될 때, 언제 활성화 되었는지 기록하는 벡터
    history.assign(N, vector<int>(N, 0));
    for(int i = 0 ; i < temp.size() ; i++){
        locQ.push(temp.at(i));
        copyMap[temp.at(i).first][temp.at(i).second] = 0;
        visited[temp.at(i).first][temp.at(i).second] = true; // 초기 활성화된 바이러스가 붙어있을 수 있으므로, 모두 방문 처리
    }
    int cnt = 0;
    while(!locQ.empty()){
        int x = locQ.front().first, y = locQ.front().second;
        visited[x][y] = true;
        locQ.pop();
        for(int i = 0 ; i < 4 ; i++){
            int xx = x + dir.at(i).first;
            int yy = y + dir.at(i).second;
            if(xx < 0 || yy < 0 || xx >= N || yy >= N || visited[xx][yy] || copyMap[xx][yy] == -1)
                continue;
            if(copyMap[xx][yy] != -2){ // 다음칸이 비활성화 바이러스가 아닐 때
                if(history[x][y] != 0){ // 현재 칸이 활성화된 비활성화 바이러스라면
                    copyMap[xx][yy] = history[x][y]+1; // 이전에 기록해놓은 활성화 되었던 시간에 + 1을 해준다
                }else{ //현재 칸이 그냥 전염된 바이러스면
                    copyMap[xx][yy] = copyMap[x][y] + 1; //평범하게 현재 칸에서 + 1을 해준다
                }
            } else{ // 비활성화 바이러스에 들어간 경우(무조건 history 에 현재 시간을 기록)
                copyMap[xx][yy] = copyMap[x][y]; // 맵은 그 전 가중치를 그대로 대입한다
                if(history[x][y] == 0){ //현재 위치가 비활성화 -> 활성화 가 아닌 경우 (활성화에서 퍼져나온 경우)
                    history[xx][yy] = copyMap[x][y] + 1;
                }else{ // 현재 위치가 비활성화 -> 활성화 된 경우 (map에서는 그전 가중치를 갖고있으나, 실제 변경된 시간은 history에 있음)
                    history[xx][yy] = history[x][y] + 1;
                }
            }
            visited[xx][yy] = true;
            locQ.push(make_pair(xx, yy));
        }
        cnt++;
        if(cnt <= M){
            copyMap[x][y] = -3;
        }
    }
}

void combi(int depth, int start){
    if(depth == M){
        spread();
        check();
        return;
    }
    
    for(int i = start ; i < loc.size() ; i++){
        temp.push_back(loc.at(i));
        combi(depth + 1, i + 1);
        temp.pop_back();
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>> N >> M;
    map.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
            if(map[i][j] == 1){
                map[i][j] = -1; //wall
            }else if(map[i][j] == 2){
                map[i][j] = -2; //virus 후보
                loc.push_back(make_pair(i, j));
            }else if(map[i][j] == 0)
                map[i][j] = -4; //empty
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
