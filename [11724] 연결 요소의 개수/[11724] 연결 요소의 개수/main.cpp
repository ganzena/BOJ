//
//  main.cpp
//  [11724] 연결 요소의 개수
//
//  Created by YOO TAEWOOK on 12/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt = 0;
bool map[1001][1001] = {false, };
bool visit[1001][1001] = {false, };

void init();
void solve(int, int);

int main(int argc, const char * argv[]) {
    init();
    for(int i = 1 ; i < N + 1 ; i++){
        if(visit[i][i]) //해당 정점이 이미 방문되었다면 수행하지 않는다(이미 연결요소로 들어감)
            continue;
        solve(i, i);
        cnt++; //연결 요소의 갯수 세기
    }
    cout<<cnt<<endl;
    return 0;
}

void solve(int x, int y){
    if(visit[x][y]){ //이미 방문한 정점 혹은 간선이라면 끝낸다
        return;
    }else{
        visit[x][x] = true; // 해당 정점에 대한 방문 표시
        visit[y][y] = true; // 해당 정점에 대한 방문 표시
        visit[x][y] = true; // 해당 정점에 대한 방문 표시
        visit[y][x] = true; // 해당 정점에 대한 방문 표시
        for(int i = 1 ; i < N + 1 ; i++){
            if(map[y][i]){ //간선이라면
                solve(y, i); // 재귀 호출
            }
        }
        return; // 끝낸다
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    for(int i = 0 ; i < M ; i++){
        int x, y;
        cin>>x>>y;
        map[x][y] = true; //
        map[y][x] = true;
    }
}
