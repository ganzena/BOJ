//
//  main.cpp
//  [13565] 침투
//
//  Created by YOO TAEWOOK on 2020/09/28.
//

#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

vector<vector<char> > map;
vector<vector<bool> > visit;
vector<pair<int, int> > dir;
queue<pair<int, int> > startQ;

int M, N;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(!startQ.empty()){
        pair<int, int> now = startQ.front();
        visit[now.first][now.second] = true;
        startQ.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            pair<int, int> next = pair<int, int>(now.first + dir.at(i).first, now.second + dir.at(i).second);
            if(next.first >= M || next.first < 0 || next.second >= N || next.second < 0)
                continue;
            if(visit[next.first][next.second] || map[next.first][next.second] == '1')
                continue;
            
            visit[next.first][next.second] = true;
            startQ.push(next);
        }
    }
    
    for(int j = 0 ; j < N ; j++){
        if(visit[M - 1][j]){
            cout<<"YES"<<endl;
            return;
        }
    }
    
    cout<<"NO"<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>M>>N;
    map.assign(M, vector<char>(N, '0'));
    visit.assign(M, vector<bool>(N, false));
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
            if(i == 0 && map[i][j] == '0')
                startQ.push(pair<int, int>(i, j));
        }
    }
    
    dir.push_back(pair<int, int>(0, 1));
    dir.push_back(pair<int, int>(0, -1));
    dir.push_back(pair<int, int>(1, 0));
    dir.push_back(pair<int, int>(-1, 0));
}
