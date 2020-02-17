//
//  main.cpp
//  [1987] 알파벳
//
//  Created by YOO TAEWOOK on 13/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char> > map;
vector<pair<int, int> > dir;
vector<bool> visit; //각 알파벳 별로 visit 여부 기록

int R, C;

int ans = 0;

void init();
void solve(int, pair<int, int>);
void print();


int main(int argc, const char * argv[]) {
    init();
    solve(1, make_pair(0, 0));
    cout<<ans<<endl;
    return 0;
}

void solve(int depth, pair<int, int> loc){
    ans = max(ans, depth); //depth가 여러번 들어갈 것이고 그때 최고의 depth로만 갱신
    for(int i = 0 ; i < 4 ; i++){
        pair<int, int> next = make_pair(loc.first + dir.at(i).first, loc.second + dir.at(i).second);
        if(next.first >= R || next.first < 0 || next.second >= C || next.second < 0 || visit[map[next.first][next.second] - 'A'])
            continue;
        visit[map[next.first][next.second] - 'A'] = true; //방문 알파벳 방문 표시
        solve(depth + 1, next);
        visit[map[next.first][next.second] - 'A'] = false; //방문 알파벳 방문 취소
    }
    return;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>R>>C;
    map.assign(R, vector<char>(C, ' '));
    visit.assign(26, false); //알파벳 방문 여부 벡터
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin>>map[i][j];
        }
    }
    visit[map[0][0] - 'A'] = true; //초기 위치의 알파벳은 방문한 것으로
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
