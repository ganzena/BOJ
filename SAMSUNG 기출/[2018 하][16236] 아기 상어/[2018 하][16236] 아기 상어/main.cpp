//
//  main.cpp
//  [2018 하][16236] 아기 상어
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Fish{ // 물고기 구조체
    int x;
    int y;
    int size;
};

struct Shark{ // 상어 구조체
    int x;
    int y;
    int size;
    int time;
    int exp;
};

int N;
Shark shark = {0,0,0,0,0};
int minSize = 7;
int ans = 0;

vector<vector<int> > map;
vector<vector<bool> > visit;
vector<pair<int, int> > dir;
queue<Shark> sharkQ;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    cout<<ans<<endl;
    return 0;
}

void solve(){
    while(1){
        vector<Fish> fishV; // 먹이 대상 정보 저장
        visit.assign(N, vector<bool>(N, false));
        
        // 1. 상어가 움직일 위치 확보
        sharkQ.push(shark);
        int minDist = -1; // 이 값이 업데이트가 되면 먹이를 찾은 것
        visit[shark.x][shark.y] = true;
        while(!sharkQ.empty()){
            Shark nowShark = sharkQ.front();
            sharkQ.pop();
            // 먹이를 찾은 상태이고, 가장 짧은 거리에 있을 때
            if(minDist > 0 && minDist == nowShark.time){
                // 빈 칸도 아니고, 크기도 상어보다 작아야만 먹이가 된다
                if(map[nowShark.x][nowShark.y] != 0 && map[nowShark.x][nowShark.y] < nowShark.size){
                    Fish fish = {nowShark.x, nowShark.y, map[nowShark.x][nowShark.y]};
                    fishV.push_back(fish);
                }
                continue;
            }
            for(int i = 0 ; i < 4 ; i++){
                int xx = nowShark.x + dir.at(i).first;
                int yy = nowShark.y + dir.at(i).second;
                if(xx < 0 || yy < 0 || xx >= N || yy >= N || visit[xx][yy] || map[xx][yy] > nowShark.size)
                    continue;
                Shark nextShark = {xx, yy, nowShark.size, nowShark.time + 1, nowShark.exp};
                
                visit[xx][yy] = true;
                if(map[xx][yy] == nowShark.size || map[xx][yy] == 0 ){ //빈칸이나 크기가 같으면 그냥 지나간다
                    sharkQ.push(nextShark);
                }else if(map[xx][yy] != 0){
                    if(minDist == -1) // 첫 발견 먹이에 대한 거리 업데이트
                        minDist = nextShark.time;
                    sharkQ.push(nextShark);
                }
            }
        }
        
        if(fishV.empty()) // 먹이가 업으면 종료
            return;
        
        // 2. 확보한 위치들 중 가장 위에 가장 왼쪽에 있는 물고기 찾기
        Fish target = {-1,-1,-1}; //초기값
        for(int i = 0 ; i < fishV.size() ; i++){
            if(target.size < 0) //초긱밧일 경우 업데이트
                target = fishV.at(i);
            else{
                if(target.x > fishV.at(i).x){//가장 위쪽에 있고
                    target = fishV.at(i);
                }else if(target.x == fishV.at(i).x){
                    if(target.y > fishV.at(i).y){//가장 왼쪽에 있는 물고기
                        target = fishV.at(i);
                    }
                }
            }
        }
        
        // 3. 물고기 먹어 치우고 상어 업데이트
        shark.x = target.x;
        shark.y = target.y;
        shark.time = 0;
        if(++shark.exp == shark.size){
            shark.exp = 0;
            shark.size++;
        }
        map[target.x][target.y] = 0; //먹었으므로 0으로 업데이트
        ans += minDist; //이동거리 더하기
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N;
    map.assign(N, vector<int>(N, 0));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
            if(map[i][j] == 9){ //상어
                shark.x = i;
                shark.y = j;
                shark.size = 2;
                map[i][j] = 0;
            }
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
