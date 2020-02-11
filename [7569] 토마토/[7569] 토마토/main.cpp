//
//  main.cpp
//  [7569] 토마토
//
//  Created by YOO TAEWOOK on 09/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tomato{
    int day, x, y, z;
};

struct Dir{
    int x, y, z;
};

int box[100][100][100]; //1 익은 토마토 0 은 안 익은 토마토
bool visit[100][100][100] = {false, };
vector<Dir> dir;
queue<Tomato> q;
bool allMature = false;
int M, N, H;
int ans;

void init();
bool check();
void spread();
void print(int);

int main(int argc, const char * argv[]) {
    init();
    spread();
    return 0;
}

void spread(){
    if(q.empty()){ //익은 토마토가 없으면 -1을 출력
        cout<<-1<<endl;
        return;
    }
    
    if(allMature){ //초기 상태가 모두 익은 상태면 0을 출력
        cout<<0<<endl;
        return;
    }
    
    while(!q.empty()){
        Tomato cur = q.front();
        q.pop();
        
        ans = cur.day;
        //print(cur.day);
        for(int i = 0 ; i < dir.size() ; i++){
            int xx = cur.x + dir.at(i).x;
            int yy = cur.y + dir.at(i).y;
            int zz = cur.z + dir.at(i).z;
            
            if(xx >= N || xx < 0 || yy >= M || yy < 0 || zz >= H || zz < 0 || visit[xx][yy][zz] || box[xx][yy][zz] == -1){
                continue;
            }
            
            if(box[xx][yy][zz] == 0){
                box[xx][yy][zz] = 1;
                visit[xx][yy][zz] = true;
                q.push({cur.day + 1, xx, yy, zz});
            }
        }
    }
    
    if(check()){ //모두 다 익었으면 day 출력
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl; //익지 않았으면 -1 출력
    }
}

bool check(){
    for(int k = 0 ; k < H ; k++){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(box[i][j][k] == 0){
                    return false;
                }
            }
        }
    }
    return true;
}

void print(int day){
    cout<<day<<" day"<<endl;
    for(int k = 0 ; k < H ; k++){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cout<<box[i][j][k]<<"\t";
            }cout<<endl;
        }cout<<endl;
    }cout<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>M>>N>>H;
    
    for(int k = 0 ; k < H ; k++){ //1층부터 받을거니까 첫 루프틑 H로 잡는다
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cin>>box[i][j][k];
                if(box[i][j][k] == 1){ //익은 토마토 큐에 푸시
                    q.push({0, i,j,k});
                    visit[i][j][k] = true;
                }else if(allMature && box[i][j][k] == 0){
                    allMature = false;
                }
            }
        }
    }
    // 6개 방향 추가
    dir.push_back({1,0,0});
    dir.push_back({-1,0,0});
    dir.push_back({0,1,0});
    dir.push_back({0,-1,0});
    dir.push_back({0,0,1});
    dir.push_back({0,0,-1});
}
