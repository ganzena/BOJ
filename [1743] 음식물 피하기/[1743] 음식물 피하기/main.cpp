//
//  main.cpp
//  [1743] 음식물 피하기
//
//  Created by YOO TAEWOOK on 2020/09/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init();

int map[101][101];
int visit[101][101];
queue<pair<int, int> > trashQ;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M, K;
int maximum = 0;
int cnt = 0;

void init();
void solve();
void DFS(int, int, int);

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(!trashQ.empty()){
        pair<int, int> now = trashQ.front();
        trashQ.pop();
        if(visit[now.first][now.second])
            continue;
        DFS(now.first, now.second, 0);
        maximum = max(maximum, cnt);
        // count 초기화
        cnt = 0;
    }

    cout<<maximum<<endl;
}

void DFS(int x, int y, int depth){
    // 최초 탐색지 방문 처리
    visit[x][y] = true;
    if(depth == 10000){
        return;
    }
    // DFS 돈 만큼 count
    cnt++;
    for(int i = 0 ; i <4 ; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX > N || nextX <= 0 || nextY > M || nextY <= 0 || visit[nextX][nextY] == true || map[nextX][nextY] == 0)
            continue;

        visit[nextX][nextY] = true;
        DFS(nextX, nextY, depth + 1);
       
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>K;
    for(int i = 0 ; i < K ; i++){
        int x, y;
        cin>>x>>y;
        map[x][y] = 1;
        trashQ.push(pair<int, int>(x, y));
    }
}
