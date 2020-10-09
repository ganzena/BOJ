//
//  main.cpp
//  [1303] 전쟁 - 전투
//
//  Created by YOO TAEWOOK on 2020/09/28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define endl "\n"

using namespace std;

char map[100][100];
bool visit[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int M, N;
int wP = 0;
int bP = 0;
int wCnt = 0;
int bCnt = 0;

void init();
void solve();
void DFS(int, int, int, char);

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void DFS(int x, int y, int depth, char team){
    if(depth > M * N)
        return;
    visit[x][y] = true;
    if(team == 'W')
        wCnt++;
    else
        bCnt++;
    for(int d = 0 ; d < 4 ;d++){
        int xx = x + dx[d];
        int yy = y + dy[d];
        if(xx < 0 || yy < 0 || xx >= M || yy >= N || visit[xx][yy] || map[xx][yy] != team)
            continue;
        visit[xx][yy] = true;
        DFS(xx, yy, depth + 1, team);
    }
}

void solve(){
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visit[i][j])
                continue;
            DFS(i, j, 0, map[i][j]);
            if(map[i][j] == 'W'){
                wP += pow(wCnt, 2);
                wCnt = 0;
            }else{
                bP += pow(bCnt, 2);
                bCnt = 0;
            }
        }
    }
    
    cout<<wP<<' '<<bP<<endl;
}
void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }
}
