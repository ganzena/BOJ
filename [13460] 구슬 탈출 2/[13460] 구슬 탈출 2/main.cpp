//
//  main.cpp
//  [13460] 구슬 탈출 2
//
//  Created by YOO TAEWOOK on 06/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//5 5
//#####
//#..B#
//#.#.#
//#RO.#
//#####
//R과 B는 공이고 O에 다가 R만 넣는거다
//통은 동서남북으로 틀어서 움직일 수 있다
//10번이 지나면 실패처리로 -1
//최소한의 횟수로 O에다가 넣을 방법을 구해라

using namespace std;

struct Ball{
    int depth; //횟수 기록용
    int rx, ry, bx, by; //R과 B의 위치 기록
};

void init();
void solve();
void move(int&, int&, int);

int N, M, ans = -1;
bool visit[10][10][10][10] ; // 한 번 왔던 자리는 다시 올 필요가 없다
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 오른쪽, 왼쪽, 아래, 위
char map[10][10];
int endX, endY; // 구멍의 위치
Ball balls;


int main(){
    init();
    solve();
    cout<<ans<<endl;
}

void solve(){
    queue<Ball> q;
    q.push(balls); //초기의 공을 큐에 넣는다
    visit[balls.rx][balls.ry][balls.bx][balls.by] = true;
    
    while(!q.empty()){
        Ball cur = q.front();
        q.pop();
        if(cur.depth > 10){ //10번이 넘어가면 멈춘다
            break;
        }
        if(cur.rx == endX && cur.ry == endY ){ //빨강이 구멍에 빠졌으면 횟수 기록하고 끝
            ans = cur.depth;
            break;
        }
        
        for(int i = 0 ; i < 4 ; i++){ // 동서남북으로 공을 이동시킨다.
            int rx = cur.rx; // 해당 방향으로 움직였을 때의 R, B 위치 기록
            int ry = cur.ry;
            int bx = cur.bx;
            int by = cur.by;
            move(rx, ry, i);
            move(bx, by, i);
            
            if(bx == endX && by == endY){ // 파란 공이 구멍에 빠졌으면 끝낸다
                continue;
            }
            if (rx == bx && ry == by) { //공이 겹쳤을 때의 위치 조정
                // 오른쪽, 왼쪽, 위, 아래
                switch (i) {
                    case 0: //오른쪽
                    cur.ry < cur.by ? ry-- : by--; break;
                    case 1: //왼쪽
                    cur.ry < cur.by ? by++ : ry++; break;
                    case 2: //아래
                    cur.rx < cur.bx ? rx-- : bx--; break;
                    case 3: //위
                    cur.rx < cur.bx ? bx++ : rx++; break;

                }
            }
            
            if(!visit[rx][ry][bx][by]){ //해당 위치에 온적 없으면 판을 또 돌린다
                Ball next = {cur.depth + 1, rx, ry, bx, by};
                q.push(next);
                visit[rx][ry][bx][by] = true;
            }
        }
    }
}

void move(int& x, int& y, int i){
    while(1){ //해당 방향으로 좌표를 움직인다
        x += dir[i][0];
        y += dir[i][1];
        if(map[x][y] == '#'){ //벽이면 왔던 방향의 반대로 다시 돌아오고 이동을 멈춘다
            x -= dir[i][0];
            y -= dir[i][1];
            break;
        }else if(map[x][y] == 'O'){ //구멍이면 바로 멈춘다
            break;
        }
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ;j++){
            cin>>map[i][j];
            if(map[i][j] == 'O'){
                endX = i;
                endY = j;
            }else if(map[i][j] == 'R'){
                balls.rx = i;
                balls.ry = j;
            }else if(map[i][j] == 'B'){
                balls.bx = i;
                balls.by = j;
            }
        }
    }
    balls.depth = 0;
}
