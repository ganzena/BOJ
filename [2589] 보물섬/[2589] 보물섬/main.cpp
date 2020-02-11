//
//  main.cpp
//  [2589] 보물섬
//
//  Created by YOO TAEWOOK on 10/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<char, int> > > initMap; //<문자, 해당 칸에 몇번째 도달인지>
vector<vector<bool> > visit; //방문벡터
vector<pair<int, int> > dir; //방향벡터
queue<pair<int, int> > q;

int N, M;
void init();
void solve();
int ans = 0;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(!q.empty()){ //전체 큐가 빌 떄까지
        queue<pair<int, int> >tq; //임시 큐를 만들어서
        tq.push(q.front()); //전체 큐에서 하나씩 빼서 임시큐에 넣는다.
        q.pop();
        visit.assign(50, vector<bool>(50, false)); //임시큐 한번 끝날때마다 방문벡터 초기화
        vector<vector<pair<char, int> > > map = initMap; //임시큐 한번 끝날때마다 초기맵으로 초기화
        int cnt = 0; // 최장거리를 잴 변수
        while(!tq.empty()){ //임시큐에서 BFS 돌리면서 카운트한다
            pair<int, int> cur = tq.front();
            visit[cur.first][cur.second] = true;
            cnt = map[cur.first][cur.second].second;
            tq.pop();
            for(int i = 0 ; i < 4 ; i++){
                pair<int, int> next = make_pair(cur.first + dir.at(i).first, cur.second + dir.at(i).second);
                if(next.first >= N || next.first < 0 || next.second >= M || next.second < 0 || map[next.first][next.second].first == 'W' || visit[next.first][next.second]){
                    continue;
                }
                
                visit[next.first][next.second] = true;
                map[next.first][next.second].second = map[cur.first][cur.second].second + 1;
                tq.push(next);
                
            }
        }
        ans = max(cnt, ans); //최장거리 구함
    }
    
    cout<<ans<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    initMap.assign(50, vector<pair<char, int> >(50, make_pair(' ', 0))); //cost 0으로 초기화
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ;j++){
            cin>>initMap[i][j].first;
            if(initMap[i][j].first == 'L'){
                q.push(make_pair(i, j)); //현재 L인 곳의 좌표를 모두 큐에 넣는다.
            }
        }
    }
    
    visit.assign(50, vector<bool>(50, false));
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
