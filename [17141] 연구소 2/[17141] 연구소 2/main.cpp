//
//  main.cpp
//  [17141] 연구소 2
//
//  Created by YOO TAEWOOK on 2020/09/28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define endl "\n"
#define pii pair<int, int>

using namespace std;

vector<vector<int> > map;
vector<vector<int> > copiedMap; // 맵 백업
vector<vector<bool> > visit;
vector<vector<bool> > copiedVisit; // 방문 백업
vector<pii> dir; // 방향

vector<pii> candidateV; // 바이러스가 놓일 수 있는 위치
vector<pii> selectedV; // 바이러스가 놓일 위치
queue<pii> virusQ;

int N, M;
bool success = false;
int answer = INT_MAX;

void init();
void solve();
void select(int, int);

int main(int argc, const char * argv[]) {
    init();
    select(0, 0);
    if(answer == INT_MAX)
        cout<< -1 <<endl;
    else
        cout<< answer <<endl;
    return 0;
}

void solve(){
    // map,  visit 백업
    copiedMap = map;
    copiedVisit = visit;
    
    //바이러스 큐 셋팅 및 바이러스 위치 방문 처리
    for(int i = 0 ; i < M ; i++){
        virusQ.push(selectedV.at(i));
        visit[selectedV.at(i).first][selectedV.at(i).second] = true;
    }
    
    //바이러스 전파
    while(!virusQ.empty()){
        pii now = virusQ.front();
        visit[now.first][now.second] = true;
        virusQ.pop();
        for(int i = 0 ; i < 4 ; i++){
            pii next = pii(now.first + dir.at(i).first, now.second + dir.at(i).second);
            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                continue;
            if(visit[next.first][next.second] || map[next.first][next.second] != 0)
                continue;
            visit[next.first][next.second] = true;
            map[next.first][next.second] = map[now.first][now.second] + 1;
            virusQ.push(next);
        }
    }
    
    // 바이러스가 퍼졌는지 체크
    bool flag = true;
    int maximum = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] == 0 && !visit[i][j]){ // 0이면서 방문하지 못한 곳 있는지 확인
                flag = false;
                break;
            }else{
                maximum = max(maximum, map[i][j]);
            }
        }
    }

    // 전파가 완료되었다면 answer(최소 시간) 갱신
    if(flag){
        success = true;
        answer = min(answer, maximum);
    }
    
    // map, visit 원복
    map = copiedMap;
    visit = copiedVisit;
}

void select(int start, int depth){
    // 위치 선정 완료 후 전파 시작
    if(depth >= M){
        solve();
        return;
    }
    
    for(int k = start ; k < candidateV.size() ; k++){
        selectedV.push_back(candidateV.at(k)); //후보 벡터 추가
        select(k + 1, depth + 1);
        selectedV.pop_back(); // 후보 벡터에서 삭제
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    map.assign(N, vector<int>(N, 0));
    visit.assign(N, vector<bool>(N, false));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
            if(map[i][j] == 2){ //바이러스가 놓일 곳
                candidateV.push_back(pair<int, int>(i, j));
                map[i][j] = 0;
            }else if(map[i][j] == 1){ // 비용 산정을 위해 벽은 -1로
                map[i][j] = -1;
            }
        }
    }
    
    //방향 벡터
    dir.push_back(pair<int, int>(0, 1));
    dir.push_back(pair<int, int>(0, -1));
    dir.push_back(pair<int, int>(1, 0));
    dir.push_back(pair<int, int>(-1, 0));
}
