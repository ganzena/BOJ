//
//  main.cpp
//  [18809] Gaaaaaaaaaarden
//
//  Created by YOO TAEWOOK on 2020/03/25.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum STATUS {LAKE, CAN_WATER, NO_WATER};
enum WATER {EMPTY, GREEN, RED, FLOWER};

struct Water{
    int x; // bfs를 위한 좌표 기록
    int y; // bfs를 위한 좌표 기록
    int t; // 도달한 시간
    WATER color; // 상태
};

void init();
void solve(int, int);
void check();
void spread();
void print();

vector<pair<int, int> > dir;
vector<vector<STATUS> > map; // 호수, 배양액 뿌릴 수 있는 곳 없는 곳 체크
vector<vector<Water> > waterMap; // 빈 칸, 초록, 빨강, 꽃 상태 체크
vector<pair<int, int> > canWaterV;
vector<Water> tempV;


int N, M, G, R; // G = 초록색 배양액 R = 빨간색 배양액
int ans = 0;

int main(int argc, const char * argv[]) {
    init();
    solve(0, 0);
    cout<<ans<<endl;
    return 0;
}

void spread(){
    Water waterTemp;
    waterTemp.color = EMPTY; // 빈칸
    waterTemp.t = 0;
    waterMap.assign(N, vector<Water>(M, waterTemp)); // 매 확산 시작시 맵 할당
    
    int temp = 0; // 꽃의 갯수
    int time = 0; // 시간이 얼마나 흘렀는가
    
    queue<Water> redQ; // 빨간 배양액 큐
    queue<Water> greenQ; // 초록 배양액 큐
    
    for(int i = 0 ; i < tempV.size() ; i++){ // tempV에서 초록 빨강을 나누어 큐에 집어넣는다.
        Water init = tempV.at(i);
        waterMap[init.x][init.y] = init; // 확산 전 waterMap에 배양액을 뿌려둔다
        if(tempV.at(i).color == RED){
            redQ.push(tempV.at(i)); // 큐에 저장
        }else{
            greenQ.push(tempV.at(i)); // 큐에 저장
        }
    }
    // 빨간색 다음 초록색 순으로 확산 시작
    while(!redQ.empty() && !greenQ.empty()){
        while(!redQ.empty()){
            Water now = redQ.front();
            if(now.t > time)
                break;
            redQ.pop();
            if(waterMap[now.x][now.y].color == FLOWER) // 초록색이 확산된 후 빨간색이 있던 자리가 꽃이 되었을 수 있음
                continue;
            waterMap[now.x][now.y] = now;
            for(int i = 0 ; i < 4 ; i++){
                int xx = now.x + dir.at(i).first;
                int yy = now.y + dir.at(i).second;
                if(xx < 0 || yy < 0 || xx >= N || yy >= M || waterMap[xx][yy].color != EMPTY || map[xx][yy] == LAKE ){
                    continue;
                }
                
                Water next;
                next.x = xx;
                next.y = yy;
                next.t = now.t + 1;
                next.color = RED;
                waterMap[xx][yy] = next;
                redQ.push(next);
            }
            
        }
        while(!greenQ.empty()){
            Water now = greenQ.front();
            if(now.t > time)
                break;
            greenQ.pop();
            
            waterMap[now.x][now.y] = now;
            for(int i = 0 ; i < 4 ; i++){
                int xx = now.x + dir.at(i).first;
                int yy = now.y + dir.at(i).second;
                if(xx < 0 || yy < 0 || xx >= N || yy >= M || waterMap[xx][yy].color == GREEN || map[xx][yy] == LAKE || waterMap[xx][yy].color == FLOWER){
                    continue;
                }
                
                if(waterMap[xx][yy].color == RED){ // 빨강인데 확산된 시간이 다르면 무시
                    if(waterMap[xx][yy].t != now.t + 1)
                        continue;
                }
                
                //RED랑 EMPTY만 나옴
                Water next;
                next.x = xx;
                next.y = yy;
                next.t = now.t + 1;
                next.color = GREEN;
                if(waterMap[xx][yy].color == RED){
                    temp++;
                    waterMap[xx][yy] = next;
                    waterMap[xx][yy].color = FLOWER;
                }else{
                    waterMap[xx][yy] = next;
                    greenQ.push(next);
                }
                
            }
        }
        time++;
    }
    
    ans = max(temp, ans);
}

void solve(int depth, int start){
    
    if((R <= 0 && G <= 0)){ // 배양액을 모두 소진했으면 확산시킨다
        spread();
        return;
    }
    
    for(int i = start ; i < (int)canWaterV.size() ; i++){
        Water temp; //초기 상태 셋팅
        temp.x = canWaterV.at(i).first; // 배양액 뿌릴 수 있는 곳 지정
        temp.y = canWaterV.at(i).second; // 배양액 뿌릴 수 있는 곳 지정
        temp.t = 0;
        if(R > 0){ // 빨강 배양액을 뿌릴 수 있으면
            temp.color = RED; // 색깔 지정
            tempV.push_back(temp);
            R--;
            solve(depth + 1, i + 1);
            R++;
            tempV.pop_back();
        }
        
        if(G > 0){ // 초록 배양액을 뿌릴 수 있으면
            temp.color = GREEN; // 색깔 지정
            tempV.push_back(temp);
            G--;
            solve(depth + 1, i + 1);
            G++;
            tempV.pop_back();
        }
    }
    return;
    
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>G>>R;
    map.assign(N, vector<STATUS>(M, LAKE));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int num;
            cin>>num;
            if(num == 0){
                map[i][j] = LAKE;
            }else if(num == 1){
                map[i][j] = NO_WATER;
            }else{
                map[i][j] = CAN_WATER;
                canWaterV.push_back(make_pair(i, j)); // 배양액 뿌릴 수 있는 곳을 저장
            }
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
