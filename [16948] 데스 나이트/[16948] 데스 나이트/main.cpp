//
//  main.cpp
//  [16948] 데스 나이트
//
//  Created by YOO TAEWOOK on 2020/10/09.
//

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define pii pair<int, int>

using namespace std;

vector<pii> dir;
vector<vector<int> > map;
vector<vector<bool> > visit;

int N;
pii start, finish;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    queue<pii> q;
    q.push(start);
    visit[start.first][start.second] = true;
    while(!q.empty()){
        pii now = q.front();
        q.pop();
        visit[now.first][now.second] = true;
        for(int i = 0 ; i < 6 ; i++){
            pii next = pii(now.first + dir.at(i).first, now.second + dir.at(i).second);
            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                continue;
            if(visit[next.first][next.second])
                continue;
            
            visit[next.first][next.second] = true;
            map[next.first][next.second] = map[now.first][now.second] + 1;
            q.push(next);
        }
    }
    
    if(map[finish.first][finish.second] == 0)
        cout<< -1 <<endl;
    else
        cout<<map[finish.first][finish.second]<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    cin>>start.first>>start.second>>finish.first>>finish.second;
    map.assign(N, vector<int>(N, 0));
    visit.assign(N, vector<bool>(N, false));
    
    dir.push_back(pii(-2, -1));
    dir.push_back(pii(-2, 1));
    dir.push_back(pii(0, -2));
    dir.push_back(pii(0, 2));
    dir.push_back(pii(2, -1));
    dir.push_back(pii(2, 1));
}
