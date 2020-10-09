//
//  main.cpp
//  [18404] 현명한 나이트
//
//  Created by YOO TAEWOOK on 2020/09/28.
//

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define pii pair<int, int>

using namespace std;

int map[501][501];
bool visit[501][501];
vector<pair<int, int> > dir;
vector<pair<int, int> > enemy;
pair<int, int> knight;
int N, M;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    
    return 0;
}

void solve(){
    queue<pair<int, int> > q;
    visit[knight.first][knight.second] = true;
    q.push(knight);
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        for(int d = 0 ; d < 8 ; d++){
            pii next = pii(now.first + dir.at(d).first, now.second + dir.at(d).second);
            if(next.first <= 0 || next.second <= 0 || next.first > N || next.second > N)
                continue;
            if(visit[next.first][next.second])
                continue;
            visit[next.first][next.second] = true;
            map[next.first][next.second] = map[now.first][now.second] + 1;
            q.push(next);
        }
    }
    
    
    
    for(int i = 0 ; i < M ; i++){
        cout<<map[enemy.at(i).first][enemy.at(i).second]<<" ";
    }cout<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    cin>>knight.first>>knight.second;
    for(int i = 0 ; i < M ; i++){
        int x, y;
        cin>>x>>y;
        enemy.push_back(pii(x, y));
    }
    
    dir.push_back(pair<int, int>(-2, -1));
    dir.push_back(pair<int, int>(-2, +1));
    dir.push_back(pair<int, int>(-1, -2));
    dir.push_back(pair<int, int>(-1, 2));
    dir.push_back(pair<int, int>(1, -2));
    dir.push_back(pair<int, int>(1, 2));
    dir.push_back(pair<int, int>(2, 1));
    dir.push_back(pair<int, int>(2, -1));
}
