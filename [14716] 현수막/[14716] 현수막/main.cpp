//
//  main.cpp
//  [14716] 현수막
//
//  Created by YOO TAEWOOK on 2020/09/28.
//

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int map[250][250];
bool visit[250][250];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void init();
void solve();
void DFS(int, int, int);

int M, N;
int cnt = 0;

int main(int argc, const char * argv[]) {
    
    init();
    solve();
    return 0;
}

void DFS(int x, int y, int depth){
    
    if(depth > M * N){
        return;
    }
    visit[x][y] = true;
    
    for(int d = 0 ; d < 8 ; d++){
        int xx = x + dx[d];
        int yy = y + dy[d];
        if(xx >= M || yy >= N || xx < 0 || yy < 0)
            continue;
        if(visit[xx][yy] || map[xx][yy] == 0)
            continue;
        visit[xx][yy] = true;
        DFS(xx, yy, depth + 1);
    }
}

void solve(){
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] == 1 && !visit[i][j]){
                DFS(i, j, 0);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>M>>N;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }
}
